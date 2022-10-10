#! /bin/bash
#svn co 
cd code
pio run
#pio run -t nobuild -t upload
cd ..
texfot pdflatex ide.tex
termux-open ide.pdf
