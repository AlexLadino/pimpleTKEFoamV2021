// Vectorial OK DEFINITIVO
// Info << "Computing Turbulence Dissipation dissipationRes :: " << endl;

dissipationRes = -2.0*nuLam*symm(gradUPrime.T() & gradUPrime);
dissipationAcc += dissipationRes*currentTimeStep;
dissipationMean = dissipationAcc/(max(tSmall,tTKEAveraging));

// dissipationRes.write();
// dissipationMean.write();

/*
forAll(dissipationRes, cellI)
{
dissipationRes[cellI][0] = -2*nuLam[cellI]*(gradUPrime[cellI][0]*gradUPrime[cellI][0] + gradUPrime[cellI][3]*gradUPrime[cellI][3] + gradUPrime[cellI][6]*gradUPrime[cellI][6]);

dissipationRes[cellI][1] = -2*nuLam[cellI]*(gradUPrime[cellI][0]*gradUPrime[cellI][1] + gradUPrime[cellI][3]*gradUPrime[cellI][4] + gradUPrime[cellI][6]*gradUPrime[cellI][7]);

dissipationRes[cellI][2] = -2*nuLam[cellI]*(gradUPrime[cellI][0]*gradUPrime[cellI][2] + gradUPrime[cellI][3]*gradUPrime[cellI][5] + gradUPrime[cellI][6]*gradUPrime[cellI][8]);

dissipationRes[cellI][3] = -2*nuLam[cellI]*(gradUPrime[cellI][1]*gradUPrime[cellI][1] + gradUPrime[cellI][4]*gradUPrime[cellI][4] + gradUPrime[cellI][7]*gradUPrime[cellI][7]);

dissipationRes[cellI][4] = -2*nuLam[cellI]*(gradUPrime[cellI][1]*gradUPrime[cellI][2] + gradUPrime[cellI][4]*gradUPrime[cellI][5] + gradUPrime[cellI][7]*gradUPrime[cellI][8]);

dissipationRes[cellI][5] = -2*nuLam[cellI]*(gradUPrime[cellI][2]*gradUPrime[cellI][2] + gradUPrime[cellI][5]*gradUPrime[cellI][5] + gradUPrime[cellI][8]*gradUPrime[cellI][8]);
    
    
}
*/


