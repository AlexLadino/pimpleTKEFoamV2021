

volSymmTensorField pDiffRes
(
    IOobject
    (
        "pDiffRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),  
    mesh,
       dimensionedSymmTensor
      (
           "pDiffMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

/*
// ----------------------------------------------------------------------------
volVectorField pUPrimeRes
(
    IOobject
    (
        "pUPrimeRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        p*UPrime
);

pDiffRes = -twoSymm(fvc::grad(pUPrimeRes)); // Pressure diffusion rate

// ----------------------------------------------------------------------------
*/

volSymmTensorField pDiffMean
(
    IOobject
    (
        "pDiffMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
        ),
    mesh,
       dimensionedSymmTensor
      (
           "pDiffMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField pDiffAcc(pDiffMean*tSpanTKE);
