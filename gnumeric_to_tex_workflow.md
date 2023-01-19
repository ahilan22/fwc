# workflow (seperate .tex for tables)

**about:** including tables in a $\LaTeX$ document from seperate .tex file for tables

## generating tables for $\LaTeX$ with spreadsheet
1. Gnumeric is a spreadsheet similar to MS Excel, Google Sheets
3.  **open Gnumeric:** type `gnumeric` in terminal
	1. _in termux:_ you can Google Sheets or other
4. enter your table and add needed formatting & styling
5. save your file as a spreadsheet (we use .xlsx); _for example:_ table.xlsx
6. generate latex file for a spreadsheet, _in our case_
	```
	ssconvert --export-type=Gnumeric_html:latex table.xlsx table.tex
	```

## in main tex
1. add these lines:
	```latex
	\documentclass{article}	% working
	\def\inputGnumericTable{}
	\usepackage[latin1]{inputenc}
	\usepackage{fullpage}
	\usepackage{color}
	\usepackage{array}
	\usepackage{longtable}
	\usepackage{calc}
	\usepackage{multirow}
	\usepackage{hhline}
	\usepackage{ifthen}
    ```
1. **making table**, (place this block where the table is to be placed and also give proper location for table.tex in \input)
	```latex
	\begin{table}[h]
		\input{tables/table}
	\end{table}
    ```
## in table.tex
1. for obtaining fractions as in math mode, etc..
1. say, in one element of the table we have '2/5' which is meant to be a fraction 
1. find that element in table.tex
1. it'll be somewhat like below
	```latex
		\multicolumn{1}{|p{\gnumericColA}|}%
		{\gnumericPB{\centering}\gnumbox{2/5}}
    ```
1. change the above to
	```latex
		\multicolumn{1}{|p{\gnumericColA}|}%
		{\gnumericPB{\centering}\gnumbox{$\frac{2}{5}}$}
    ```
