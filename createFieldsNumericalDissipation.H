Info<< "Dentro de createFieldsNumericalDissipation.H \n" << endl;

Info<< "Creating trDissipationSmall NO_READ \n" << endl;
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

Info<< "Creating prodTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating prodTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating prodTKEAcc\n" << endl;
volScalarField prodTKEAcc(prodTKEMean*tSpanTKE);

Info<< "Creating dissipationTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating dissipationTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Creating dissipationTKEAcc READ_IF_PRESENT \n" << endl;
volScalarField dissipationTKEAcc(dissipationTKEMean*tSpanTKE);

Info<< "Creating turbulenceTransportTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating turbulenceTransportTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating turbulenceTransportTKEAcc READ_IF_PRESENT \n" << endl;
volScalarField turbulenceTransportTKEAcc(turbulenceTransportTKEMean*tSpanTKE);

Info<< "Creating viscousDiffusionTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating viscousDiffusionTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating viscousDiffusionTKEAcc \n" << endl;
volScalarField viscousDiffusionTKEAcc(viscousDiffusionTKEMean*tSpanTKE);

Info<< "Creating pressureDiffusionTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating pressureDiffusionTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Creating pressureDiffusionTKEAcc \n" << endl;
volScalarField pressureDiffusionTKEAcc(pressureDiffusionTKEMean*tSpanTKE);

Info<< "Creating pressureStrainTKERes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating pressureStrainTKEMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating pressureStrainTKEAcc \n" << endl;
volScalarField pressureStrainTKEAcc(pressureStrainTKEMean*tSpanTKE);

Info<< "Creating dissipationNumericalRes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating dissipationNumericalMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating dissipationNumericalAcc \n" << endl;
volScalarField dissipationNumericalAcc(dissipationNumericalMean*tSpanTKE);

Info<< "Creating nuNumericalRes READ_IF_PRESENT \n" << endl;
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
        // nuLam*(dissipationNumericalRes/(max(trDissipationSmall,0.5*tr(dissipationRes))))
    mesh,
       dimensionedScalar
      (
           "nuNumericalMean", 
           dimLength*dimLength/dimTime, 
           scalar (VSMALL)
      )
);

Info<< "Creating nuNumericalMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating nuNumericalAcc \n" << endl;
volScalarField nuNumericalAcc(nuNumericalMean*tSpanTKE);
Info<< "Min nuNumericalAcc :: " << gMin(nuNumericalAcc) << " Max nuNumericalAcc:: " << gMax(nuNumericalAcc) << nl << endl;
Info<< "tSpanTKE :: " << tSpanTKE << nl << endl;

Info<< "Creating QDNSIndexRes READ_IF_PRESENT \n" << endl;
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

Info<< "Creating QDNSIndexMean READ_IF_PRESENT \n" << endl;
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

Info<< "Generating QDNSIndexAcc \n" << endl;
volScalarField QDNSIndexAcc(QDNSIndexMean*tSpanTKE);

// Fluctuating strain rate
Info<< "Creating SRes NO_READ \n" << endl;
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
Info<< "Creating epsRes NO_READ \n" << endl;
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

Info<< "Fin createFieldsNumericalDissipation.H \n" << endl;

