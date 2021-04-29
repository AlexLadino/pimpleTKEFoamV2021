// OK VECTORIAL
// Molecular diffusion
// Info << "Computing Molecular Diffusion molDiffRes :: " << endl;

//(OK rev 28/05/2020)
molDiffRes = fvc::laplacian(nuLam, RMean); // Molecular diffusion rate

molDiffAcc += molDiffRes*currentTimeStep;
molDiffMean = molDiffAcc/(max(tSmall,tTKEAveraging));
