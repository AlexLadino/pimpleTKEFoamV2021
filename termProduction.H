// OK vectorial definitivo
// Info << "Computing Turbulence Production prodRes :: " << endl;

/*
forAll(prodRes, cellI)
{
    prodRes[cellI][0] = -(RMean[cellI][0]*gradUMean[cellI][0] + RMean[cellI][1]*gradUMean[cellI][3] + RMean[cellI][2]*gradUMean[cellI][6])-(RMean[cellI][0]*gradUMean[cellI][0] + RMean[cellI][1]*gradUMean[cellI][3] + RMean[cellI][2]*gradUMean[cellI][6]);
    prodRes[cellI][1] = -(RMean[cellI][1]*gradUMean[cellI][0] + RMean[cellI][3]*gradUMean[cellI][3] + RMean[cellI][4]*gradUMean[cellI][6])-(RMean[cellI][0]*gradUMean[cellI][1] + RMean[cellI][1]*gradUMean[cellI][4] + RMean[cellI][2]*gradUMean[cellI][7]);
    prodRes[cellI][2] = -(RMean[cellI][2]*gradUMean[cellI][0] + RMean[cellI][4]*gradUMean[cellI][3] + RMean[cellI][5]*gradUMean[cellI][6])-(RMean[cellI][0]*gradUMean[cellI][2] + RMean[cellI][1]*gradUMean[cellI][5] + RMean[cellI][2]*gradUMean[cellI][8]);
    prodRes[cellI][3] = -(RMean[cellI][1]*gradUMean[cellI][1] + RMean[cellI][3]*gradUMean[cellI][4] + RMean[cellI][4]*gradUMean[cellI][7])-(RMean[cellI][1]*gradUMean[cellI][1] + RMean[cellI][3]*gradUMean[cellI][4] + RMean[cellI][4]*gradUMean[cellI][7]);
    prodRes[cellI][4] = -(RMean[cellI][2]*gradUMean[cellI][1] + RMean[cellI][4]*gradUMean[cellI][4] + RMean[cellI][5]*gradUMean[cellI][7])-(RMean[cellI][1]*gradUMean[cellI][2] + RMean[cellI][3]*gradUMean[cellI][5] + RMean[cellI][4]*gradUMean[cellI][8]);
    prodRes[cellI][5] = -(RMean[cellI][2]*gradUMean[cellI][2] + RMean[cellI][4]*gradUMean[cellI][5] + RMean[cellI][5]*gradUMean[cellI][8])-(RMean[cellI][2]*gradUMean[cellI][2] + RMean[cellI][4]*gradUMean[cellI][5] + RMean[cellI][5]*gradUMean[cellI][8]);     
}
*/
        
prodRes = -twoSymm(RMean & (fvc::grad(UMean)));
prodAcc += prodRes*currentTimeStep;
prodMean = prodAcc/(max(tSmall,tTKEAveraging));

// prodRes.write();
// prodMean.write();
