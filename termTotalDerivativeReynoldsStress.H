// OK VECTORIAL DEFINITIVO

// Total derivative Reynolds Stress Term
// ver: https://www.cfd-online.com/Forums/openfoam-solving/58580-ddt.html

/*
ddtReynoldsStressRes = fvc::DDt(phi,RMean); // Total derivative Reynolds Stress
*/

// Ambas son lo mismo
// fvc::DDt(phi,RMean) = fvc::ddt(RMean) + fvc::div(phi,RMean)

// ddtReynoldsStressRes2 = fvc::ddt(RMean) + fvc::div(phi,RMean); 

// Info << "Computing Derivative of Reynolds Stress DDtReynoldsStressRes :: " << endl;

//(OK rev 28/05/2020)
DDtReynoldsStressRes = fvc::DDt(phi,RMean); // Total derivative Reynolds Stress

DDtReynoldsStressAcc += DDtReynoldsStressRes*currentTimeStep;
DDtReynoldsStressMean = DDtReynoldsStressAcc/(max(tSmall,tTKEAveraging));