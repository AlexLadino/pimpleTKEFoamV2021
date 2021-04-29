
// (OK rev 28/05/2020)
volSymmTensorField pStrainRes
(
    IOobject
    (
        "pStrainRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    pPrime*twoSRes
);
volSymmTensorField pStrainMean
(
    IOobject
    (
        "pStrainMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "pStrainMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField pStrainAcc(pStrainMean*tSpanTKE);

/*
volSymmTensorField pStrainInternaRes
(
    IOobject
    (
        "pStrainInternaRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        pPrime*twoSRes
);

volSymmTensorField pStrainInternaMean
(
    IOobject
    (
        "pStrainInternaMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "pStrainInternaMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(0,0,0,0,0,0)
      )
);

volSymmTensorField pStrainInternaAcc(pStrainInternaMean*tSpanTKE);


volSymmTensorField pStrainRes
(
    IOobject
    (
        "pStrainRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        pStrainInternaMean
);
*/