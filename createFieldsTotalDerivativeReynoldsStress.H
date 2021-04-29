
volSymmTensorField DDtReynoldsStressRes
(
    IOobject
    (
        "DDtReynoldsStressRes",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE  // AUTO_WRITE
    ),
        fvc::DDt(phi,RMean)
);

volSymmTensorField DDtReynoldsStressMean
(
    IOobject
    (
        "DDtReynoldsStressMean",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE  // AUTO_WRITE
    ),
    mesh,
       dimensionedSymmTensor
      (
           "DDtReynoldsStressMean", 
           dimLength*dimLength/(dimTime*dimTime*dimTime), 
           symmTensor(0,0,0,0,0,0)
      ) 
);

volSymmTensorField DDtReynoldsStressAcc(DDtReynoldsStressMean*tSpanTKE);


// Ambas son lo mismo
// fvc::DDt(phi,RMean) = fvc::ddt(RMean) + fvc::div(phi,RMean)

/*
volSymmTensorField ddtReynoldsStressRes2
(
    IOobject
    (
        "ddtReynoldsStressRes2",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
        fvc::ddt(RMean) + fvc::div(phi,RMean)
);
*/