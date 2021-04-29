// OK VECTORIAL DEFINITIVO

// Info << "Computing Pressure Diffusion pDiffRes :: " << endl;

// Pressure diffusion rate (OK rev 28/05/2020)
volVectorField pUPrimeRes
(
    IOobject
    (
        "pUPrimeRes",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::NO_WRITE
    ),
        p*UPrime
);

pDiffRes = -twoSymm(fvc::grad(pUPrimeRes)); // Pressure diffusion rate

pDiffAcc += pDiffRes*currentTimeStep;
pDiffMean = pDiffAcc/(max(tSmall,tTKEAveraging));
