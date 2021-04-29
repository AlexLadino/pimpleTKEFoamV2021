//Pendiente Vectorial

// Info << "Computing Turbulence Transpot turbTransRes :: " << endl;

// volScalarField UPrime000(UPrime.component(0)*UPrime.component(0)*UPrime.component(0));
volScalarField UPrime000
(
    IOobject
    (
        "UPrime000",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(0)*UPrime.component(0)
);
// UPrime000.write();

// volVectorField gradUPrime000(fvc::grad(UPrime000));
volVectorField gradUPrime000
(
    IOobject
    (
        "gradUPrime000",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime000)
);
// gradUPrime000.write();
// Info<< " gradUPrime000 :: " << gMin(gradUPrime000) << endl;


// volScalarField UPrime001(UPrime.component(0)*UPrime.component(0)*UPrime.component(1));
volScalarField UPrime001
(
    IOobject
    (
        "UPrime001",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(0)*UPrime.component(1)
);
// UPrime001.write();
// volVectorField gradUPrime001(fvc::grad(UPrime001));
volVectorField gradUPrime001
(
    IOobject
    (
        "gradUPrime001",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime001)
);
// gradUPrime001.write();
// Info<< " gradUPrime001 :: " << gMin(gradUPrime001) << endl;



// volScalarField UPrime002(UPrime.component(0)*UPrime.component(0)*UPrime.component(2));
volScalarField UPrime002
(
    IOobject
    (
        "UPrime002",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(0)*UPrime.component(2)
);
// UPrime002.write();
// volVectorField gradUPrime002(fvc::grad(UPrime002));
volVectorField gradUPrime002
(
    IOobject
    (
        "gradUPrime002",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime002)
);
// gradUPrime002.write();
// Info<< " gradUPrime002 :: " << gMin(gradUPrime002) << endl;




// volScalarField UPrime011(UPrime.component(0)*UPrime.component(1)*UPrime.component(1));
volScalarField UPrime011
(
    IOobject
    (
        "UPrime011",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(1)*UPrime.component(1)
);
// UPrime011.write();
// volVectorField gradUPrime011(fvc::grad(UPrime011));
volVectorField gradUPrime011
(
    IOobject
    (
        "gradUPrime011",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime011)
);
// gradUPrime011.write();
// Info<< " gradUPrime011 :: " << gMin(gradUPrime011) << endl;



// volScalarField UPrime012(UPrime.component(0)*UPrime.component(1)*UPrime.component(2));
volScalarField UPrime012
(
    IOobject
    (
        "UPrime012",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(1)*UPrime.component(2)
);
// UPrime012.write();
// volVectorField gradUPrime012(fvc::grad(UPrime012));
volVectorField gradUPrime012
(
    IOobject
    (
        "gradUPrime012",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime012)
);
// gradUPrime012.write();
// Info<< " gradUPrime012 :: " << gMin(gradUPrime012) << endl;



// volScalarField UPrime022(UPrime.component(0)*UPrime.component(2)*UPrime.component(2));
volScalarField UPrime022
(
    IOobject
    (
        "UPrime022",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(0)*UPrime.component(2)*UPrime.component(2)
);
// UPrime022.write();
// volVectorField gradUPrime022(fvc::grad(UPrime022));
volVectorField gradUPrime022
(
    IOobject
    (
        "gradUPrime022",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime022)
);
// gradUPrime022.write();
// Info<< " gradUPrime022 :: " << gMin(gradUPrime022) << endl;




// volScalarField UPrime111(UPrime.component(1)*UPrime.component(1)*UPrime.component(1));
volScalarField UPrime111
(
    IOobject
    (
        "UPrime111",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(1)*UPrime.component(1)*UPrime.component(1)
);
// UPrime111.write();
// volVectorField gradUPrime111(fvc::grad(UPrime111));
volVectorField gradUPrime111
(
    IOobject
    (
        "gradUPrime111",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime111)
);
// gradUPrime111.write();
// Info<< " gradUPrime111 :: " << gMin(gradUPrime111) << endl;


// volScalarField UPrime112(UPrime.component(1)*UPrime.component(1)*UPrime.component(2));
volScalarField UPrime112
(
    IOobject
    (
        "UPrime112",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(1)*UPrime.component(1)*UPrime.component(2)
);
// UPrime112.write();
// volVectorField gradUPrime112(fvc::grad(UPrime112));
volVectorField gradUPrime112
(
    IOobject
    (
        "gradUPrime112",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime112)
);
// gradUPrime112.write();
// Info<< " gradUPrime112 :: " << gMin(gradUPrime112) << endl;


// volScalarField UPrime122(UPrime.component(1)*UPrime.component(2)*UPrime.component(2));
volScalarField UPrime122
(
    IOobject
    (
        "UPrime122",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(1)*UPrime.component(2)*UPrime.component(2)
);
// UPrime122.write();
// volVectorField gradUPrime122(fvc::grad(UPrime122));
volVectorField gradUPrime122
(
    IOobject
    (
        "gradUPrime122",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime122)
);
// gradUPrime122.write();
// Info<< " gradUPrime122 :: " << gMin(gradUPrime122) << endl;



// volScalarField UPrime222(UPrime.component(2)*UPrime.component(2)*UPrime.component(2));
volScalarField UPrime222
(
    IOobject
    (
        "UPrime222",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        UPrime.component(2)*UPrime.component(2)*UPrime.component(2)
);
// UPrime222.write();
// volVectorField gradUPrime222(fvc::grad(UPrime222));
volVectorField gradUPrime222
(
    IOobject
    (
        "gradUPrime222",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        fvc::grad(UPrime222)
);
// gradUPrime222.write();


forAll(turbTransRes, cellI)
{
    turbTransRes[cellI][0] = -1*(gradUPrime000[cellI][0] + gradUPrime001[cellI][1] + gradUPrime002[cellI][2]);
    turbTransRes[cellI][1] = -1*(gradUPrime001[cellI][0] + gradUPrime011[cellI][1] + gradUPrime012[cellI][2]);
    turbTransRes[cellI][2] = -1*(gradUPrime002[cellI][0] + gradUPrime012[cellI][1] + gradUPrime022[cellI][2]);
    turbTransRes[cellI][3] = -1*(gradUPrime011[cellI][0] + gradUPrime111[cellI][1] + gradUPrime112[cellI][2]);
    turbTransRes[cellI][4] = -1*(gradUPrime012[cellI][0] + gradUPrime112[cellI][1] + gradUPrime122[cellI][2]);
    turbTransRes[cellI][5] = -1*(gradUPrime022[cellI][0] + gradUPrime122[cellI][1] + gradUPrime222[cellI][2]);
}

// Info<< " turbTransRes Min :: " << gMin(turbTransRes) << endl;
// Info<< " turbTransRes Max :: " << gMax(turbTransRes) << endl;

turbTransAcc += turbTransRes*currentTimeStep;
turbTransMean = turbTransAcc/(max(tSmall,tTKEAveraging));
// Info<< " turbTransMean Min :: " << gMin(turbTransMean) << endl;
// Info<< " turbTransMean Max :: " << gMax(turbTransMean) << endl;

// turbTransRes.write();
// turbTransMean.write();


