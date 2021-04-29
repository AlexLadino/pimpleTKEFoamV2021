    dimensionedScalar currentTime("currentTime", dimTime, runTime.value());
    dimensionedScalar currentTimeStep("currentTimeStep", dimTime, runTime.deltaTValue());

    dimensionedScalar tAveraging("tAveraging", dimTime, currentTime.value()-tStartAveraging.value());

    vorticity = fvc::curl(U);
    UAcc += U*currentTimeStep;
    pAcc += p*currentTimeStep;
    vorticityAcc += vorticity*currentTimeStep;

    UMean = UAcc/(max(tSmall,tAveraging));
    pMean = pAcc/(max(tSmall,tAveraging));
    vorticityMean = vorticityAcc/(max(tSmall,tAveraging));

    UPrime = (U - UMean); //instantaneous velocity fluctuations vector
    pPrime = (p - pMean); //instantaneous pressure fluctuations
    vorticityPrime = (vorticity - vorticityMean); //instantaneous vorticity fluctuations    

    gradUPrime = fvc::grad(UPrime);
    twoSRes = twoSymm(gradUPrime); // (gradUPrime + gradUPrime')

    RRes = symm(UPrime*UPrime);
    RAcc += RRes*currentTimeStep;   
    RMean = RAcc/(max(tSmall,tAveraging));
    
    vorticity2PrimeRes = symm(vorticityPrime*vorticityPrime);
    vorticity2PrimeAcc += vorticity2PrimeRes*currentTimeStep;   
    vorticity2PrimeMean = vorticity2PrimeAcc/(max(tSmall,tAveraging));
      
    gradUMean = fvc::grad(UMean);

    if (runTime.writeTime())
    {          
          Info << "Writing Averages accumulated for " << tAveraging.value() << " s" << endl;

          UMean.write();
          pMean.write();
          vorticityMean.write();
//           UPrime.write();
//           pPrime.write();
          RMean.write();
          vorticity2PrimeMean.write();         
    }