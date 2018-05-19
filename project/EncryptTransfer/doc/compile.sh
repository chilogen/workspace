export TEXINPUTS=./dependencies//:
export TEXMFDBS=./dependencies:
jobname=thesis
bash clean.sh
rm $jobname.pdf
pdflatex ./$jobname.tex
makeindex -s $jobname.ist -t $jobname.glg -o $jobname.gls $jobname.glo
makeindex -s $jobname.ist -t $jobname.alg -o $jobname.acr $jobname.acn
bibtex ./$jobname.aux
bibtex ./publications.aux
pdflatex ./$jobname.tex
makeindex -s $jobname.ist -t $jobname.glg -o $jobname.gls $jobname.glo
makeindex -s $jobname.ist -t $jobname.alg -o $jobname.acr $jobname.acn
pdflatex ./$jobname.tex
bash clean.sh
echo ****************************************************************************
echo successful!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo ****************************************************************************
