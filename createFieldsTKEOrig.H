const volScalarField kSmall
(
    IOobject
    (
        "kSmall",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "kSmall", 
           dimVelocity*dimVelocity,
           SMALL 
      )
);

volSymmTensorField RSGS
(
    IOobject
    (
        "RSGS",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        turbulence->R()
);

volScalarField kSGS
(
    IOobject
    (
        "kSGS",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        0.5*tr(RSGS)
);

/*
volSymmTensorField RRes
(
    IOobject
    (
        "RRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        symm((UPrime*UPrime))
);
*/

// Turbulent Kinetic Energy
volScalarField kRes
(
    IOobject
    (
        "kRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    0.5*tr(RRes)
);

// Fluctuating strain rate
volSymmTensorField SRes
(
    IOobject
    (
        "Sres",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        symm(fvc::grad(UPrime))
);

// Dissipation
volScalarField epsRes
(
    IOobject
    (
        "epsRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        -2*nuLam*(SRes && SRes)
);


volScalarField LESIndexRes
(
    IOobject
    (
        "LESIndexRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        kRes/max(kSmall,(kRes+kSGS))
);

volScalarField MIndexRes // Launchbury Pg 66
(
    IOobject
    (
        "MIndexRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
      kSGS/max(kSmall,(kRes+kSGS))
);



volScalarField IQIndexNuRes // Launchbury Pg 66
(
    IOobject
    (
        "IQIndexNuRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
      nut/(nuLam + nut)
);

volScalarField kMean
(
    IOobject
    (
        "kMean",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        mesh,
    dimensionedScalar
    (
        "kMean", 
        dimensionSet(0,2,-3,0,0,0,0), 
        scalar(VSMALL)
    )
);

volScalarField kAcc(kMean*tSpan);

volScalarField epsMean
(
    IOobject
    (
        "epsMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "epsMean", 
            dimensionSet(0,2,-3,0,0,0,0), 
           scalar(VSMALL)
      )
);

volScalarField epsAcc(epsMean*tSpan);


volScalarField LESIndexMean
(
    IOobject
    (
        "LESIndexMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "LESIndexMean", 
            dimensionSet(0,0,0,0,0,0,0), 
           scalar(VSMALL)
      )
);

volScalarField LESIndexAcc(LESIndexMean*tSpan);


volScalarField MIndexMean
(
    IOobject
    (
        "MIndexMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "MIndexMean", 
            dimensionSet(0,0,0,0,0,0,0), 
           scalar(VSMALL)
      )
);

volScalarField MIndexAcc(MIndexMean*tSpan);


volScalarField IQIndexNuMean
(
    IOobject
    (
        "IQIndexNuMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "IQIndexNuMean", 
            dimensionSet(0,0,0,0,0,0,0), 
           scalar(VSMALL)
      )
);

volScalarField IQIndexNuAcc(IQIndexNuMean*tSpan);
