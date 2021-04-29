// (OK rev 28/05/2020)

volSymmTensorField turbTransRes
(
      IOobject
      (
            "turbTransRes",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
      ),
      mesh,
      dimensionedSymmTensor
      (
            "turbTransRes", 
            dimLength*dimLength/(dimTime*dimTime*dimTime), 
            symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )    
);

volSymmTensorField turbTransMean
(
    IOobject
    (
        "turbTransMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
           dimensionedSymmTensor
      (
           "turbTransMean",
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(VSMALL,VSMALL,VSMALL,VSMALL,VSMALL,VSMALL)
      )
);

volSymmTensorField turbTransAcc(turbTransMean*tSpanTKE);


/*

// ----------------- Turbulent Transport term prueba --------------------
volScalarField uPxxx(UPrime.component(vector::X)*UPrime.component(vector::X)*UPrime.component(vector::X));
volScalarField uPxxy(UPrime.component(vector::X)*UPrime.component(vector::X)*UPrime.component(vector::Y));
volScalarField uPxxz(UPrime.component(vector::X)*UPrime.component(vector::X)*UPrime.component(vector::Z));
volScalarField uPxyy(UPrime.component(vector::X)*UPrime.component(vector::Y)*UPrime.component(vector::Y));
volScalarField uPxyz(UPrime.component(vector::X)*UPrime.component(vector::Y)*UPrime.component(vector::Z));
volScalarField uPxzz(UPrime.component(vector::X)*UPrime.component(vector::Z)*UPrime.component(vector::Z));
volScalarField uPyyy(UPrime.component(vector::Y)*UPrime.component(vector::Y)*UPrime.component(vector::Y));
volScalarField uPyyz(UPrime.component(vector::Y)*UPrime.component(vector::Y)*UPrime.component(vector::Z));
volScalarField uPyzz(UPrime.component(vector::Y)*UPrime.component(vector::Z)*UPrime.component(vector::Z));
volScalarField uPzzz(UPrime.component(vector::Z)*UPrime.component(vector::Z)*UPrime.component(vector::Z));

// uPxxxMean = uPxxxAcc*currentTimeStep;
volScalarField uPxxxMean
(
    IOobject
    (
        "uPxxxMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxxxMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPxxyMean = uPxxyAcc*currentTimeStep;
volScalarField uPxxyMean
(
    IOobject
    (
        "uPxxyMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxxyMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPxxzMean = uPxxzAcc*currentTimeStep;
volScalarField uPxxzMean
(
    IOobject
    (
        "uPxxzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxxzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPxyyMean = uPxyyAcc*currentTimeStep;
volScalarField uPxyyMean
(
    IOobject
    (
        "uPxyyMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxyyMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPxyzMean = uPxyzAcc*currentTimeStep;
volScalarField uPxyzMean
(
    IOobject
    (
        "uPxyzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxyzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPxzzMean = uPxzzAcc*currentTimeStep;
volScalarField uPxzzMean
(
    IOobject
    (
        "uPxzzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPxzzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPyyyMean = uPyyyAcc*currentTimeStep;
volScalarField uPyyyMean
(
    IOobject
    (
        "uPyyyMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPyyyMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPyyzMean = uPyyzAcc*currentTimeStep;
volScalarField uPyyzMean
(
    IOobject
    (
        "uPyyzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPyyzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPyzzMean = uPyzzAcc*currentTimeStep;
volScalarField uPyzzMean
(
    IOobject
    (
        "uPyzzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPyzzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

// uPzzzMean = uPzzzAcc*currentTimeStep;
volScalarField uPzzzMean
(
    IOobject
    (
        "uPzzzMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
           dimensionedScalar
      (
           "uPzzzMean", 
           dimVelocity*dimVelocity*dimVelocity, 
           scalar(0.0)
      )    
);

volScalarField uPxxxAcc(uPxxxMean*tSpanTKE);
volScalarField uPxxyAcc(uPxxyMean*tSpanTKE);
volScalarField uPxxzAcc(uPxxzMean*tSpanTKE);
volScalarField uPxyyAcc(uPxyyMean*tSpanTKE);
volScalarField uPxyzAcc(uPxyzMean*tSpanTKE);
volScalarField uPxzzAcc(uPxzzMean*tSpanTKE);
volScalarField uPyyyAcc(uPyyyMean*tSpanTKE);
volScalarField uPyyzAcc(uPyyzMean*tSpanTKE);
volScalarField uPyzzAcc(uPyzzMean*tSpanTKE);
volScalarField uPzzzAcc(uPzzzMean*tSpanTKE);

volVectorField gradUPxxxMean(fvc::grad(uPxxxMean)); 
volVectorField gradUPxxyMean(fvc::grad(uPxxyMean));
volVectorField gradUPxxzMean(fvc::grad(uPxxzMean));
volVectorField gradUPxyyMean(fvc::grad(uPxyyMean));
volVectorField gradUPxyzMean(fvc::grad(uPxyzMean));
volVectorField gradUPxzzMean(fvc::grad(uPxzzMean));
volVectorField gradUPyyyMean(fvc::grad(uPyyyMean));
volVectorField gradUPyyzMean(fvc::grad(uPyyzMean));
volVectorField gradUPyzzMean(fvc::grad(uPyzzMean));
volVectorField gradUPzzzMean(fvc::grad(uPzzzMean));

volScalarField turbTransResUU
(
    IOobject
    (
        "turbTransResUU",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxxxMean.component(vector::X) + gradUPxxyMean.component(vector::Y) + gradUPxxzMean.component(vector::Z))
);

volScalarField turbTransResUV
(
    IOobject
    (
        "turbTransResUV",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxxyMean.component(vector::X) + gradUPxyyMean.component(vector::Y) + gradUPxyzMean.component(vector::Z))
);

volScalarField turbTransResUW
(
    IOobject
    (
        "turbTransResUW",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxxzMean.component(vector::X) + gradUPxyzMean.component(vector::Y) + gradUPxzzMean.component(vector::Z))
);

volScalarField turbTransResVV
(
    IOobject
    (
        "turbTransResVV",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxyyMean.component(vector::X) + gradUPxyzMean.component(vector::Y) + gradUPxzzMean.component(vector::Z))
);

volScalarField turbTransResVW
(
    IOobject
    (
        "turbTransResVW",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxyzMean.component(vector::X) + gradUPyyzMean.component(vector::Y) + gradUPyzzMean.component(vector::Z))
);

volScalarField turbTransResWW
(
    IOobject
    (
        "turbTransResWW",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
-(gradUPxzzMean.component(vector::X) + gradUPyzzMean.component(vector::Y) + gradUPzzzMean.component(vector::Z))
);

volSymmTensorField turbTransRes
(
      IOobject
      (
            "turbTransRes",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
      ),
      mesh,
      dimensionedSymmTensor
      (
            "turbTransRes", 
            dimLength*dimLength/(dimTime*dimTime*dimTime), 
            symmTensor(0,0,0,0,0,0)
      )    
);

*/