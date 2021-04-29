//OK DEFINITIVO

/*
Turbulent kinetic budget terms
Pope Turbulent Flow
Eq 5.164 / 7.178 - 7.183
*/

//(OK rev 28/05/2020)

// Info << "Computing Numerical Dissipation dissipationNumericalRes :: " << nl << endl;


//Info << "Computing prodTKE :: " << nl << endl;
prodTKERes = 0.5*tr(prodRes);
prodTKEAcc += prodTKERes*currentTimeStep;
prodTKEMean = prodTKEAcc/(max(tSmall,tTKEAveraging));
// prodTKEMean.write();
//Info<< "Min :: " << gMin(prodTKERes) << " Max :: " << gMax(prodTKERes) << nl << endl;

//Info << "Computing dissipationTKE :: " << nl << endl;
dissipationTKERes = 0.5*tr(dissipationRes);
dissipationTKEAcc += dissipationTKERes*currentTimeStep;
dissipationTKEMean = dissipationTKEAcc/(max(tSmall,tTKEAveraging));
// dissipationTKEMean.write();
//Info<< "Min :: " << gMin(dissipationTKERes) << " Max :: " << gMax(dissipationTKERes) << nl << endl;

//Info << "Computing turbulenceTransportTKE :: " << nl << endl;
turbulenceTransportTKERes = 0.5*tr(turbTransRes);
turbulenceTransportTKEAcc += turbulenceTransportTKERes*currentTimeStep;
turbulenceTransportTKEMean = turbulenceTransportTKEAcc/(max(tSmall,tTKEAveraging));
// turbulenceTransportTKEMean.write();
//Info<< "Min :: " << gMin(turbulenceTransportTKERes) << " Max :: " << gMax(turbulenceTransportTKERes) << nl << endl;

//Info << "Computing viscousDiffusionTKE :: " << nl << endl;
viscousDiffusionTKERes = 0.5*tr(molDiffRes);
viscousDiffusionTKEAcc += viscousDiffusionTKERes*currentTimeStep;
viscousDiffusionTKEMean = viscousDiffusionTKEAcc/(max(tSmall,tTKEAveraging));
// viscousDiffusionTKEMean.write();
//Info<< "Min :: " << gMin(viscousDiffusionTKERes) << " Max :: " << gMax(viscousDiffusionTKERes) << nl << endl;
        
//Info << "Computing pressureDiffusionTKE :: " << nl << endl;        
pressureDiffusionTKERes = 0.5*tr(pDiffRes);
pressureDiffusionTKEAcc += pressureDiffusionTKERes*currentTimeStep;
pressureDiffusionTKEMean = pressureDiffusionTKEAcc/(max(tSmall,tTKEAveraging));
// pressureDiffusionTKEMean.write();
//Info<< "Min :: " << gMin(pressureDiffusionTKERes) << " Max :: " << gMax(pressureDiffusionTKERes) << nl << endl;

//Info << "Computing pressureStrainTKE :: " << nl << endl;
pressureStrainTKERes = 0.5*tr(pStrainRes);
pressureStrainTKEAcc += pressureStrainTKERes*currentTimeStep;
pressureStrainTKEMean = pressureStrainTKEAcc/(max(tSmall,tTKEAveraging));
// pressureStrainTKEMean.write();
//Info<< "Min :: " << gMin(pressureStrainTKERes) << " Max :: " << gMax(pressureStrainTKERes) << nl << endl;

//Info << "Computing dissipationNumerical :: " << nl << endl;
dissipationNumericalRes = -0.5*tr(DDtReynoldsStressRes) + prodTKERes + dissipationTKERes + turbulenceTransportTKERes + pressureDiffusionTKERes + viscousDiffusionTKERes;  // Numerical dissipation
//Info<< "Min :: " << gMin(dissipationNumericalRes) << " Max :: " << gMax(dissipationNumericalRes) << nl << endl;
//                                      OK                    OK               OK                  OK                          OK                        OK

// 0.5*tr(pStrainRes) = 0 -> Continuity
dissipationNumericalAcc += dissipationNumericalRes*currentTimeStep;
dissipationNumericalMean = dissipationNumericalAcc/(max(tSmall,tTKEAveraging));

// dissipationNumericalRes.write();
// dissipationNumericalMean.write();              

// Info << "Computing Numerical viscosity nuNumericalRes :: " << endl;
// nuNumericalRes = nuLam*(dissipationNumericalRes/(max(trDissipationSmall,0.5*tr(dissipationRes)))); // (0.5*tr(dissipationRes))); // numerical viscosity
//Info << "Computing nuNumerical :: " << nl << endl;
nuNumericalRes = nuLam*(dissipationNumericalRes/(0.5*tr(dissipationRes) + disSmall)); // numerical viscosity
//Info<< "Min nuNumericalRes :: " << gMin(nuNumericalRes) << " Max nuNumericalRes :: " << gMax(nuNumericalRes) << nl << endl;
// Info<< " nuNumericalRes Min :: " << gMin(nuNumericalRes) << endl;
// Info<< " nuNumericalRes Max :: " << gMax(nuNumericalRes) << endl;

//Info<< "Min nuNumericalAcc :: " << gMin(nuNumericalAcc) << " Max nuNumericalAcc:: " << gMax(nuNumericalAcc) << nl << endl;
nuNumericalAcc += nuNumericalRes*currentTimeStep;

nuNumericalMean = nuNumericalAcc/(max(tSmall,tTKEAveraging));
Info<< " nuNumericalMean Min :: " << gMin(nuNumericalMean) << endl;
Info<< " nuNumericalMean Max :: " << gMax(nuNumericalMean) << endl;

// nuNumericalRes.write();
// nuNumericalMean.write();

Info << "Computing QDNSIndex :: " << nl << endl;
QDNSIndexRes = nuNumericalRes/(nuNumericalRes + nuLam); // Eq 7.4 Launchbury
Info<< "Min :: " << gMin(QDNSIndexRes) << " Max :: " << gMax(QDNSIndexRes) << nl << endl;

QDNSIndexAcc += QDNSIndexRes*currentTimeStep;
QDNSIndexMean = QDNSIndexAcc/(max(tSmall,tTKEAveraging));
Info<< " QDNS Quality Index based on Numerical Viscosity :: " << gMax(QDNSIndexMean) << endl;

//Info << "FIN NUMERICAL DISSIPATION " << nl << endl;