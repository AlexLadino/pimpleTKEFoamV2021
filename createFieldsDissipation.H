// (OK rev 28/05/2020)
dimensionedScalar disSmall("disSmall", dimLength*dimLength/(dimTime*dimTime*dimTime), VSMALL);

volSymmTensorField dissipationRes
(
    IOobject
    (
        "dissipationRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    -2.0*nuLam*symm(gradUPrime.T() & gradUPrime)
);

volSymmTensorField dissipationMean
(
    IOobject
    (
        "dissipationMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "dissipationMean",
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField dissipationAcc(dissipationMean*tSpanTKE);











/*
volSymmTensorField dissRes
(
    IOobject
    (
        "dissRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        symm(gradUPrime.T() & gradUPrime)
);

volSymmTensorField dissipationRes
(
    IOobject
    (
        "dissipationRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "dissipationRes",
           dimensionSet(0,0,-2,0,0,0,0), 
           symmTensor(0,0,0,0,0,0)
      )
);

volSymmTensorField dissAcc(dissipationRes*tSpanTKE);


volSymmTensorField dissipationRes
(
    IOobject
    (
        "dissipationRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
      -2.0*nuLam*dissMean
);

volSymmTensorField dissAcc(dissipationRes*tSpanTKE);
*/