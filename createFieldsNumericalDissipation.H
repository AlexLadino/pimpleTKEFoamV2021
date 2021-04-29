const volScalarField trDissipationSmall
(
    IOobject
    (
        "trDissipationSmall",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "trDissipationSmall",
            dimLength*dimLength/(dimTime*dimTime*dimTime), 
           VSMALL 
      )
);

volScalarField prodTKERes
(
    IOobject
    (
        "prodTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(prodRes)
);

volScalarField prodTKEMean
(
    IOobject
    (
        "prodTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "prodTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )
);

volScalarField prodTKEAcc(prodTKEMean*tSpanTKE);

volScalarField dissipationTKERes
(
    IOobject
    (
        "dissipationTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(dissipationRes)
);

volScalarField dissipationTKEMean
(
    IOobject
    (
        "dissipationTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "dissipationTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      ) 
);

volScalarField dissipationTKEAcc(dissipationTKEMean*tSpanTKE);

volScalarField turbulenceTransportTKERes
(
    IOobject
    (
        "turbulenceTransportTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(turbTransRes)
);

volScalarField turbulenceTransportTKEMean
(
    IOobject
    (
        "turbulenceTransportTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "turbulenceTransportTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )
);

volScalarField turbulenceTransportTKEAcc(turbulenceTransportTKEMean*tSpanTKE);

volScalarField viscousDiffusionTKERes
(
    IOobject
    (
        "viscousDiffusionTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(molDiffRes)
);

volScalarField viscousDiffusionTKEMean
(
    IOobject
    (
        "viscousDiffusionTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "viscousDiffusionTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )
);

volScalarField viscousDiffusionTKEAcc(viscousDiffusionTKEMean*tSpanTKE);

volScalarField pressureDiffusionTKERes
(
    IOobject
    (
        "pressureDiffusionTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(pDiffRes)
);

volScalarField pressureDiffusionTKEMean
(
    IOobject
    (
        "pressureDiffusionTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "pressureDiffusionTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )
);

volScalarField pressureDiffusionTKEAcc(pressureDiffusionTKEMean*tSpanTKE);

volScalarField pressureStrainTKERes
(
    IOobject
    (
        "pressureStrainTKERes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    0.5*tr(pStrainRes)
);

volScalarField pressureStrainTKEMean
(
    IOobject
    (
        "pressureStrainTKEMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "pressureStrainTKEMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )     
);

volScalarField pressureStrainTKEAcc(pressureStrainTKEMean*tSpanTKE);

volScalarField dissipationNumericalRes
(
    IOobject
    (
        "dissipationNumericalRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
-0.5*(tr(DDtReynoldsStressRes) - (tr(prodRes) + tr(dissipationRes) + tr(turbTransRes) + tr(pStrainRes) + tr(pDiffRes) + tr(molDiffRes)))
);

volScalarField dissipationNumericalMean
(
    IOobject
    (
        "dissipationNumericalMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "dissipationNumericalMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           scalar (VSMALL)
      )
);

volScalarField dissipationNumericalAcc(dissipationNumericalMean*tSpanTKE);

volScalarField nuNumericalRes
(
    IOobject
    (
        "nuNumericalRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
        nuLam*(dissipationNumericalRes/(max(trDissipationSmall,0.5*tr(dissipationRes))))
);

volScalarField nuNumericalMean
(
    IOobject
    (
        "nuNumericalMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "nuNumericalMean", 
           dimLength*dimLength/dimTime, 
           scalar (VSMALL)
      )
);

volScalarField nuNumericalAcc(nuNumericalMean*tSpanTKE);
Info<< "Min nuNumericalAcc :: " << gMin(nuNumericalAcc) << " Max nuNumericalAcc:: " << gMax(nuNumericalAcc) << nl << endl;
Info<< "tSpanTKE :: " << tSpanTKE << nl << endl;

volScalarField QDNSIndexRes // Eq 7.4 Launchbury
(
    IOobject
    (
        "QDNSIndexRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
      nuNumericalRes/(nuNumericalRes + nuLam) 
);

volScalarField QDNSIndexMean
(
    IOobject
    (
        "QDNSIndexMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
       dimensionedScalar
      (
           "QDNSIndexMean", 
           dimless, 
           scalar (VSMALL)
      )  
);

volScalarField QDNSIndexAcc(QDNSIndexMean*tSpanTKE);

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
        IOobject::NO_WRITE
    ),
        -2*nuLam*(SRes && SRes)
);



