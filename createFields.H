//Info << "VSMALL :: " << VSMALL << nl << endl;
//Info << "SMALL :: " << SMALL << nl << endl;

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

volVectorField vorticity
(
    IOobject
    (
        "vorticity",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    fvc::curl(U)
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

dimensionedScalar tSpan("tSpan", tStart-tStartAveraging);

if (tStart.value() < tStartAveraging.value())
{
      dimensionedScalar tSpan("tSpan", dimTime, 0.0);
}

// ----------------------------------------------------------------------------
dimensionedScalar tStartTKEAveraging
(
    "tStartTKEAveraging",
    dimTime,
    averagingProperties.lookup("tStartTKEAveraging")
);

Info << "Started to collect TKE statistics at t = " << tStartTKEAveraging.value() << " s" << endl;

dimensionedScalar tSpanTKE("tSpanTKE", tStart-tStartTKEAveraging);

if (tStart.value() < tStartTKEAveraging.value())
{
      dimensionedScalar tSpanTKE("tSpanTKE", dimTime, 0.0);
}


/*
dimensionedScalar nAveragingTimeSteps
(
    "nAveragingTimeSteps",
    dimless,
    averagingProperties.lookup("nAveragingTimeSteps")
);

Info << "Averaging every " << nAveragingTimeSteps.value() << " timeSteps" << endl;
*/

dimensionedScalar contador("contador", dimless, 0);


dimensionedScalar computeBudget
(
    "computeBudget",
    dimless,
    averagingProperties.lookup("computeBudget")
);


dimensionedScalar qDNSOrLES
(
    "qDNSOrLES",
    dimless,
    averagingProperties.lookup("qDNSOrLES")
);

dimensionedScalar LPT
(
    "LPT",
    dimless,
    averagingProperties.lookup("LPT")
);


/*
dimensionedScalar tStartBudget
(
    "tStartBudget",
    dimTime,
    averagingProperties.lookup("tStartBudget")
);
*/

//Mean fields are read if present

Info<< "Reading field UMean READ_IF_PRESENT \n" << endl;

volVectorField UMean
(
    IOobject
    (
        "UMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "UMean", 
           dimVelocity, 
           vector (VSMALL,VSMALL,VSMALL)
      )
);

//UMean.write();

Info<< "Reading field pMean READ_IF_PRESENT \n" << endl;
volScalarField pMean
(
    IOobject
    (
        "pMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
      dimensionedScalar
      (
           "pMean", 
           dimVelocity*dimVelocity, 
           scalar(VSMALL)
      )      
);

Info<< "Reading field vorticityMean READ_IF_PRESENT \n" << endl;
volVectorField vorticityMean
(
    IOobject
    (
        "vorticityMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE // AUTO_WRITE
    ),
    mesh,
      dimensionedVector
      (
           "vorticityMean", 
            dimless/dimTime, 
           vector(VSMALL,VSMALL,VSMALL)
      )    
);


//Instantiate accumulated U*time_step and p*time_step to calculate the average
//Initialize as Averaged_Value/Sampling_time (where sampling time = tStart - tStartAveraging) to continue averaging from previous fields
Info<< "Generating UAcc NO_READ \n" << endl;
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

Info<< "Generating pAcc NO_READ \n" << endl;
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

Info<< "Generating vorticityAcc NO_READ \n" << endl;
volVectorField vorticityAcc
(
    IOobject
    (
        "vorticityAcc",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    vorticityMean*tSpan
);

//Instantiate instantaneous values of velocity and pressure fluctuations
Info<< "Generating UPrime NO_READ \n" << endl;
volVectorField UPrime
(
    IOobject
    (
        "UPrime",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ), 			   
	U-UMean
);

Info<< "Generating pPrime NO_READ \n" << endl;
volScalarField pPrime
(
    IOobject
    (
        "pPrime",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
	p-pMean
);

Info<< "Generating vorticityPrime NO_READ \n" << endl;
volVectorField vorticityPrime
(
    IOobject
    (
        "vorticityPrime",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),  
	vorticity-vorticityMean
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
Info<< "Generating nuLam \n" << endl;
const volScalarField nuLam(turbulence->nu());
Info<< "Generating gradUPrime \n" << endl;
volTensorField gradUPrime(fvc::grad(UPrime));
Info<< "Generating twoSRes \n" << endl;
volSymmTensorField twoSRes(twoSymm(gradUPrime));
Info<< "Generating gradUMean \n" << endl;
volTensorField gradUMean(fvc::grad(UMean));

// --------------------------------------------------------------------
Info<< "Generating vorticity2PrimeRes NO_READ \n" << endl;
volSymmTensorField vorticity2PrimeRes
(
    IOobject
    (
        "vorticity2PrimeRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    symm(vorticityPrime*vorticityPrime)
);

Info<< "Reading field vorticity2PrimeMean READ_IF_PRESENT \n" << endl;
volSymmTensorField vorticity2PrimeMean
(
    IOobject
    (
        "vorticity2PrimeMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedSymmTensor("vorticity2PrimeMean", dimless/(dimTime*dimTime), symmTensor::zero)
);

Info<< "Generating vorticity2PrimeMean \n" << endl;
volSymmTensorField vorticity2PrimeAcc(vorticity2PrimeMean*tSpan);

Info<< "Generating RRes NO_READ \n" << endl;
volSymmTensorField RRes
(
    IOobject
    (
        "RRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
    symm((UPrime*UPrime))
);

Info<< "Generating RMean NO_READ \n" << endl;
volSymmTensorField RMean
(
    IOobject
    (
        "RMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "RMean", 
           dimVelocity*dimVelocity, 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

Info<< "Generating RAcc \n" << endl;
volSymmTensorField RAcc(RMean*tSpan);

Info<< "Creating createFieldsProduction \n" << endl;
#include "createFieldsProduction.H" //    OK
Info<< "Creating createFieldsDissipation \n" << endl;
#include "createFieldsDissipation.H"      //    OK
Info<< "Creating createFieldsTurbulentTransport \n" << endl;
#include "createFieldsTurbulentTransport.H" //      OK
Info<< "Creating createFieldsPressureStrain \n" << endl;
#include "createFieldsPressureStrain.H"   //    OK
Info<< "Creating createFieldsPressureDiffusion \n" << endl;
#include "createFieldsPressureDiffusion.H"      //    OK
Info<< "Creating createFieldsMolecularDiffusion \n" << endl;
#include "createFieldsMolecularDiffusion.H"     //    OK
Info<< "Creating createFieldsTotalDerivativeReynoldsStress \n" << endl;
#include "createFieldsTotalDerivativeReynoldsStress.H"      //    OK
Info<< "Creating createFieldsNumericalDissipation \n" << endl;
#include "createFieldsNumericalDissipation.H"   //    OK

/*
if (qDNSOrLES.value() == 2)
{
    Info << "Large Eddy Simulation - LES statistics " << endl;
    #include "createFieldsTKEOrig.H"  //      OK
}
*/

#include "createMRF.H"

Info<< "Reading transportProperties\n" << endl;
IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);
