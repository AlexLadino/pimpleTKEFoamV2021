

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

const dimensionedScalar tStart("tStart", runTime.startTime());
const dimensionedScalar tSmall("tSmall", dimTime, SMALL);

//user must specify the time at which sampling started in the averagingPropertis dictionary
IOdictionary averagingProperties 
(
    IOobject
    (
        "averagingProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar tStartAveraging
(
    "tStartAveraging",
    dimTime,
    averagingProperties.lookup("tStartAveraging")
);

Info << "Started to collect statistics at t = " << tStartAveraging.value() << " s" << endl;

//Mean fields are read if present
volVectorField UMean
(
    IOobject
    (
        "UMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "UMean", 
           dimVelocity, 
           vector (VSMALL,VSMALL,VSMALL)
      )
);

volScalarField pMean
(
    IOobject
    (
        "pMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "pMean", 
           dimVelocity*dimVelocity, 
           scalar(VSMALL)
      )    

);

// ****************************************************************************

volSymmTensorField prodTerm
(
    IOobject
    (
        "prodTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedSymmTensor
      (
           "prodTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField dissipationTerm
(
    IOobject
    (
        "dissipationTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "dissipationTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField turbTransTerm
(
    IOobject
    (
        "turbTransTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "turbTransTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField pStrainTerm
(
    IOobject
    (
        "pStrainTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "pStrainTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField pDiffTerm
(
    IOobject
    (
        "pDiffTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "pDiffTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField molDiffTerm
(
    IOobject
    (
        "molDiffTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "molDiffTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField ddtReynoldsStressTerm
(
    IOobject
    (
        "ddtReynoldsStressTerm",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "ddtReynoldsStressTerm", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volScalarField dissipationNumerical
(
    IOobject
    (
        "dissipationNumerical",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedScalar
      (
           "dissipationNumerical", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           scalar (VSMALL)
      )
);

volScalarField nuNumerical
(
    IOobject
    (
        "nuNumerical",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedScalar
      (
           "nuNumerical", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           scalar (VSMALL)
      )
);

volScalarField kResMean
(
    IOobject
    (
        "kResMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedScalar
      (
           "kResMean", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -2 0 0 0 0],
           scalar (VSMALL)
      )
);

volScalarField epsResMean
(
    IOobject
    (
        "epsResMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
      dimensionedScalar
      (
           "epsResMean", 
           //dimVelocity*dimVelocity/dimTime, 
           [0 2 -3 0 0 0 0],
           scalar (VSMALL)
      )
);
);

// ****************************************************************************

volTensorField gradU(Foam::fvc::grad(U));
volTensorField gradUPrime(gradU);
volSymmTensorField D(symm(gradU));
volSymmTensorField DPrime(symm(gradUPrime));

volVectorField UAcc
(
    IOobject
    (
        "UAcc",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UMean*tSpan
);

volScalarField pAcc
(
    IOobject
    (
        "pAcc",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        pMean*tSpan
);

RResAcc

dissipationAcc

uPrimeUPrimeUPrimeAcc

pStrainResAcc

pUPrimeAcc

kResAcc

epsResAcc

LESResIndexAcc



//Instantiate instantaneous values of velocity and pressure fluctuations
volVectorField UPrime
(
    IOobject
    (
        "UPrime",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        U-UMean
);

volScalarField pPrime
(
    IOobject
    (
        "pPrime",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        p-pMean
);



#include "createPhi.H"

label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, pimple.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());


singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);


//Instantiate useful instantaneous fields to calculate the budgets
//The corresponding time-averaged quantities for the various fields can be calculated using the fieldAverage function object
const volScalarField nuLam(turbulence->nu());

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

volScalarField LESResIndex 
(
    IOobject
    (
        "LESResIndex",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        kRes/max(kSmall,(kRes+kSGS))
);

#include "createMRF.H"
