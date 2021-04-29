
volSymmTensorField molDiffRes
(
    IOobject
    (
        "molDiffRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE  // AUTO_WRITE
    ),
        fvc::laplacian(nuLam, RMean)
);


volSymmTensorField molDiffMean
(
    IOobject
    (
        "molDiffMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE  // AUTO_WRITE
    ),
    mesh,
       dimensionedSymmTensor
      (
           "molDiffMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField molDiffAcc(molDiffMean*tSpanTKE);
