// OK VECTORIAL DEFINITIVO
// Pressure strain rate
/*
pStrainInternaRes = pPrime*twoSRes;
pStrainInternaAcc += pStrainInternaRes*currentTimeStep;
pStrainInternaMean = pStrainInternaAcc/(max(tSmall,tTKEAveraging));
pStrainRes = pStrainInternaMean; // Pressure strain rate
*/

// Info << "Computing Pressure Strain pStrainRes :: " << endl;

// (OK rev 28/05/2020)
pStrainRes = pPrime*twoSRes;
pStrainAcc += pStrainRes*currentTimeStep;
pStrainMean = pStrainAcc/(max(tSmall,tTKEAveraging));