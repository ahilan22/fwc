#! /bin/bash
#cd tables/
##create the table as .xlsx
##then convert it to .tex file
#ssconvert --export-type=Gnumeric_html:latex $1xlsx $1tex
#cd ..
texfot pdflatex $1tex
termux-open $1pdf
