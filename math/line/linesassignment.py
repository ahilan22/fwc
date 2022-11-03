#Code to find the diagonals of the parallelogram, given the equations of it's sides

#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import tikzplotlib as tpl
#plt.rcParams["font.family"] = "Times New Roman"

import sys                                          #for path to external scripts
sys.path.insert(0,'/sdcard/fwc-1/math/assignment/CoordGeo')         #path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#if using termux
import subprocess
import shlex
#end if

#Let the two pair of parallel lines given be represented by
#a_1x^2 + b_1x + c_1 = 0 and a_2y^2 + b_2y + c_2 = 0

#Given data
a_1 = 1
b_1 = -5
c_1 = 6

a_2 = 1
b_2 = -6
c_2 = 5

#e_1 = np.array([[1,0]]) #standard basis vector i_cap
#e_2 = np.array([[0,1]]) #standard basis vector j_cap
#print(e_1.T)
e_1 = np.array([1,0]) #standard basis vector i_cap
e_2 = np.array([0,1]) #standard basis vector j_cap

#Solutions of the quadratic equations
#i.e., 4 sides of given parallelogram
x_1 = (-b_1 - np.sqrt(b_1**2-4*a_1*c_1))/2*a_1
x_2 = (-b_1 + np.sqrt(b_1**2-4*a_1*c_1))/2*a_1
y_1 = (-b_2 - np.sqrt(b_2**2-4*a_2*c_2))/2*a_2
y_2 = (-b_2 + np.sqrt(b_2**2-4*a_2*c_2))/2*a_2

#print(x_1,x_2,y_1,y_2)

#Position Vectors of X and Y intercept for finding line equations
X_1 = np.array([x_1,0])
X_2 = np.array([x_2,0])
Y_1 = np.array([0,y_1])
Y_2 = np.array([0,y_2])

#print(X_1,X_2,Y_1,Y_2)

#simpliying measures
m = np.block([[e_1],[e_2]])
n = np.linalg.inv(m)
#print(n)

#a_1 = e_1@(X_1.T)
#a_2 = e_2.T@Y_1
#print(a_1)
#print(a_2)

#Computations of parallelogram vertices
#A = n@np.array([[e_1@X_1.T],[e_2@Y_1.T]])
#print(A)

A = n@np.array([e_1@X_1.T,e_2@Y_1.T])
B = n@np.array([e_1@X_2.T,e_2@Y_1.T])
C = n@np.array([e_1@X_2.T,e_2@Y_2.T])
D = n@np.array([e_1@X_1.T,e_2@Y_2.T])
print('The vertices of given parallelogram are')
print('A = ',A,',')
print('B = ',B,',')
print('C = ',C,',')
print('D = ',D,'.')

m1 = A-C
m2 = B-D
rot = np.array([[0,-1],[1,0]])
n1 = rot@m1
n2 = rot@m2
c1 = n1.T@A
c2 = n2.T@B
print(n1)
print(n2)
print(c1)
print(c2)

##Generating all lines
m1 = A-C
m2 = B-D
k1 = -1.1
k2 = 0.1
q1 = 5.2
q2 = -1.2
p1 = 2.2
p2 = -1.2

x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CD = line_gen(C,D)
x_DA = line_gen(D,A)
x_AC = line_dir_pt(m1,A,k1,k2)
x_BD = line_dir_pt(m2,B,k1,k2)

l_1 = line_dir_pt(e_2,A,q1,q2)
l_2 = line_dir_pt(e_1,A,p1,p2)
l_3 = line_dir_pt(e_2,B,q1,q2)
l_4 = line_dir_pt(e_1,D,p1,p2)

##Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:],color='black')#,label='$AB$')
plt.plot(x_BC[0,:],x_BC[1,:],color='black')#,label='$BC$')
plt.plot(x_CD[0,:],x_CD[1,:],color='black')#,label='$CD$')
plt.plot(x_DA[0,:],x_DA[1,:],color='black')#,label='$DA$')
plt.plot(x_AC[0,:],x_AC[1,:],label='$Diag 1$',color='purple',linestyle="--")
plt.plot(x_BD[0,:],x_BD[1,:],label='$Diag 2$',color='blue',linestyle="--")

plt.plot(l_1[0,:],l_1[1,:],color='black',linestyle="--")
plt.plot(l_2[0,:],l_2[1,:],color='black',linestyle="--")
plt.plot(l_3[0,:],l_3[1,:],color='black',linestyle="--")
plt.plot(l_4[0,:],l_4[1,:],color='black',linestyle="--")

##Labeling the coordinates
#plm_coords = np.vstack((A,B,C,D)).T
#plt.scatter(plm_coords[0,:], plm_coords[1,:])
#vert_labels = ['A','B','C','D']
#for i, txt in enumerate(vert_labels):
#    plt.annotate(txt, # this is the text
#                 (plm_coords[0,i], plm_coords[1,i]), # this is the point to label
#                 textcoords="offset pixels", # how to position the text
#                 xytext=(5,5), # distance from text to points (x,y)
#                 ha='left') # horizontal alignment can be left, right or center

plt.xlabel('$X$')
plt.ylabel('$Y$',rotation=0)
plt.legend(loc="best")
plt.grid() # minor
plt.axis('equal')
#plt.title('The Diagonals')

plt.text(2.01,0.7,'A')
plt.text(3.02,0.7,'B')
plt.text(2.02,5.08,'D')
plt.text(3.02,5.08,'C')

plt.text(1.6,0,'$L_1$')
plt.text(1,1.2,'$L_2$')
plt.text(3.2,6,'$L_3$')
plt.text(1,5.2,'$L_4$')

##if using termux
#plt.savefig('/sdcard/fwc-1/math/assignment/line/figs/plot.png')
#plt.savefig('/sdcard/fwc-1/math/assignment/line/figs/plot.pdf')
## ****** think before uncommenting the next line ******
#tpl.save('plot1.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
#subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/math/assignment/line/figs/plot.pdf'"))
##else
#plt.show()
