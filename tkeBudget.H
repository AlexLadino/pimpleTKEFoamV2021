   dimensionedScalar tTKEAveraging("tTKEAveraging", dimTime, currentTime.value()-tStartTKEAveraging.value());      
     
// ------------------- BUDGET TERMS ----------------------------
    
//     if (computeBudget.value() == 1)
//     {
         
        Info << "Computing budget terms " << nl << endl;
        //Info << "Production " << nl << endl;
        #include    "termProduction.H"      // OK (OK rev 28/05/2020)
        //Info << "Dissipation " << nl << endl;
        #include    "termDissipation.H"     // OK (OK rev 28/05/2020)     
        //Info << "Turbulent transport " << nl << endl;
        #include    "termTurbulentTransport.H" // OK (OK rev 28/05/2020)
        //Info << "Pressure Strain " << nl << endl;
        #include    "termPressureStrain.H"  // OK (OK rev 28/05/2020)
        //Info << "Pressure difffusion " << nl << endl;
        #include    "termPressureDiffusion.H"     // OK (OK rev 28/05/2020)
        //Info << "Molecular Diffusion " << nl << endl;
        #include    "termMolecularDiffusion.H"    // OK (OK rev 28/05/2020)
        //Info << "Derivatives Reynolds Stress " << nl << endl;
        #include    "termTotalDerivativeReynoldsStress.H"     // OK (OK rev 28/05/2020)
        //Info << "Numerical Dissipation " << nl << endl;
        #include    "termNumericalDissipation.H"  // OK (OK rev 28/05/2020)    
        //Info << "Fin calculo budget" << nl << endl;        
        
        /*
         if (qDNSOrLES.value() == 2)
         {
             Info << "Computing LES statistics " << endl;
             // #include  "termTKEOrig.H" // OK (OK rev 28/05/2020)                                 
         }
        */
        
        
        if (runTime.writeTime())
        {
            
            Info << "Writing Budget terms " << endl;

            //prodRes.write();
            prodMean.write();

            //dissipationRes.write();
            dissipationMean.write();

            //turbTransRes.write();
            turbTransMean.write();

            //pStrainRes.write();
            pStrainMean.write();

            //pDiffRes.write();
            pDiffMean.write();           

            //molDiffRes.write();
            molDiffMean.write();     

            //DDtReynoldsStressRes.write();
            DDtReynoldsStressMean.write();       

            //dissipationNumericalRes.write();
            dissipationNumericalMean.write();              

            nuNumericalMean.write();
            QDNSIndexMean.write();                       
            
            prodTKEMean.write();
            dissipationTKEMean.write();
            turbulenceTransportTKEMean.write();
            viscousDiffusionTKEMean.write();
            pressureDiffusionTKEMean.write();
            pressureStrainTKEMean.write();
            
        }
            
//             if (qDNSOrLES.value() == 2)
//             {
//                 Info << "Writing LES statistics " << endl;
//                 kMean.write();
//                 epsMean.write();
//                 LESIndexMean.write();
//                 MIndexMean.write();
//             }
                       
//         }      
        
        
//     }
       
//     contador = 0;      
//     Info << "El contador se reinicia a " << contador.value() << endl;
// }


