// Original pimpleTKEBudgetFoam

// (OK rev 28/05/2020)
RSGS = turbulence->R(); //Instantaneous subgrid-scale reynolds stress tensor
kSGS = 0.5*tr(RSGS); //Instantaneous subgrid-scale turbulent kinetic energy

kRes = 0.5*tr(RRes); //Instantaneous resolved tke

kAcc += kRes*currentTimeStep;
kMean = kAcc/(max(tSmall,tAveraging));

//Instantaneous resolved dissipation rate Baumann 2014 Eq 11b
epsRes = -2*nuLam*(SRes && SRes); 

epsAcc += epsRes*currentTimeStep;
epsMean = epsAcc/(max(tSmall,tAveraging));

//Instantaneous ratio of resolved to total (Resolved + SGS) tke 
// Baumann 2014 Eq 3
LESIndexRes = kRes/max(kSmall,(kRes+kSGS)); 

LESIndexAcc += LESIndexRes*currentTimeStep;
LESIndexMean = LESIndexAcc/(max(tSmall,tAveraging));

MIndexRes = kSGS/max(kSmall,(kRes+kSGS)); // Launchbury Pg 66

MIndexAcc += MIndexRes*currentTimeStep;
MIndexMean = MIndexAcc/(max(tSmall,tAveraging));

IQIndexNuRes = = nut/(nuLam+nut);

IQIndexNuAcc += IQIndexNuRes*currentTimeStep;
IQIndexNuMean = IQIndexNuAcc/(max(tSmall,tAveraging));

// Adicionales basados en Baumann
// Effective dissipation rate epsEffectiveRes

epsEffRes = epsRes + dissipationNumericalRes;

// Efective Kolmogorov Scale
kolgomorovLengthScaleEffLESRes = pow(pow(nuLam,3)/epsEffRes),0.25);

// kolgomorovLengthScaleEffLESAcc += kolgomorovLengthScaleEffLESRes*currentTimeStep;
// kolgomorovLengthScaleEffLESMean = kolgomorovLengthScaleEffLESAcc/(max(tSmall,tAveraging));





// volScalarField lCellScale
// (
//   IOobject
//   (
//       "lCellScale",
//       runTime.timeName(),
//       mesh,
//       IOobject::NO_READ,
//       IOobject::NO_WRITE
//   ),
//   mesh,
//   dimensionedScalar("zero", dimensionSet(0, 1, 0, 0, 0, 0, 0), 0.0)
// );





// tmp<volScalarField> tLScale
//     (
//         new volScalarField
//         (
//             IOobject
//             (
//                 "dummy",
//                 mesh.time().timeName(),
//                 mesh,
//                 IOobject::NO_READ,
//                 IOobject::NO_WRITE
//             ),
//             mesh,
//             dimensionedScalar("0", dimensionSet(0, 1, 0, 0, 0), 0.0),
//             zeroGradientFvPatchScalarField::typeName
//         )
//     );



// tLScale.ref().ref() = pow(mesh.V(),1.0/3.0);
// tLScale.ref().correctBoundaryConditions();      
// lCellScale = tLScale;
// lCellScale.write();     
// Info<< " Minimum actual lCellScale:: " << gMin(lCellScale) << endl;
// Info<< " Maximum actual lCellScale:: " << gMax(lCellScale) << endl;












