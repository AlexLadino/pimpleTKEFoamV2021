
// (OK rev 28/05/2020)

volSymmTensorField prodRes
(
    IOobject
    (
        "prodRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    -twoSymm(RMean & (fvc::grad(UMean)))
);


// -----------------------------

volSymmTensorField prodMean
(
    IOobject
    (
        "prodMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
      dimensionedSymmTensor
      (
           "prodMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField prodAcc(prodMean*tSpanTKE);
