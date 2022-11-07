#Code to find the locus of P. P is the center of a circle which touches C1 internally and C2 externally. Here, C2 lies inside C1.

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
from conics.funcs import *

#if using termux
import subprocess
import shlex
#end if

#Construction Parameters for circles
ra = 16 #radius of C1
rb = 3 #radius of C2
gap = 2 #better if its even
rp = ra-rb-gap/2 #radius of C
a = np.array([0,0]) #center of C1
bx = ra-gap-rb 
b = np.array([bx,0]) #center of C2
px = rp-ra
p = np.array([px,0]) #center of C

#Defining some more points for labelling
t2x = 2*rp-ra 
t1 = np.array([-ra,0]) #point of contact of C1 and C
t2 = np.array([t2x,0]) #point of contact of C2 and C
d = np.array([ra,0]) #one end of diameter

#Locus Equation Calculation
I = np.eye(2)
u2 = -1*b.reshape(2,1)
c = ra+rb
k = (u2.T@u2) - c**2
V1 = 4*(u2@u2.T)
V2 = 4*(c**2)*I
V = V2-V1
w = 2*k*u2
g = -(k**2)
lam = 16
print('V = ',V/lam)
print('w = ',w/lam)
print('g = ',g/lam)

#Construction parameters for the ellipse
maj = V[1,1]/lam
majax = np.sqrt(maj)
minx = V[0,0]/lam
minax = np.sqrt(minx)
cen1 = w[0,0]/(lam*minx)
cen2 = w[1,0]/(lam*maj)
print('a = ',majax,'b = ',minax,'h = ',cen1,'k = ',cen2)

#centre of circles
A = a.T
B = b.T
P = p.T
D = d.T

##Generating circles and line
circ_1 = circ_gen(A,ra)
circ_2 = circ_gen(B,rb)
circ = circ_gen(P,rp)
#lips = conic_quad(P,V,w,g)
x_AB = line_gen(t1,B)
x_BD = line_gen(B,D)

#Plotting
plt.plot(circ_1[0,:],circ_1[1,:],label='$C_1$',color='black')
plt.plot(circ_2[0,:],circ_2[1,:],label='$C_2$',color='green')
plt.plot(circ[0,:],circ[1,:],label='$C$')
plt.plot(x_AB[0,:],x_AB[1,:],color='black')#label='$AB$')
plt.plot(x_BD[0,:],x_BD[1,:],color='gray',linestyle="--")#label='$AB$')
#plotting ellipse
t = np.linspace(0,2*np.pi,100)
x_lips = cen1 + majax*np.cos(t)
y_lips = cen2 + minax*np.sin(t)
plt.plot(x_lips,y_lips,linestyle="--",label='Locus of $P$',color='orange')

##method 2, for plotting ellipse
#e1 = np.array([1,0]) #standard basis vector i_cap
#e2 = np.array([0,1]) #standard basis vector j_cap
#cen = (A+B)/2
#majax = np.linalg.norm(cen-P)
#e = np.linalg.norm(cen-A)/majax
#minax = majax*np.sqrt(1-e**2)
#print('a = ',majax,'b = ',minax,'h = ',cen@e1,'k = ',cen@e2)
#print(majax,minax,cen@e1,cen@e2)
#t = np.linspace(0,2*np.pi,100)
#x_lips = cen@e1 + majax*np.cos(t)
#y_lips = cen@e2 + minax*np.sin(t)
#plt.plot(x_lips,y_lips,linestyle="--",label='Locus of $P$',color='orange')

##Labeling the coordinates
plm_coords = np.vstack((A,B,P,t1,t2,D)).T
plt.scatter(plm_coords[0,:], plm_coords[1,:])
vert_labels = ['A','B','P','$T_1$','$T_2$','D']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (plm_coords[0,i], plm_coords[1,i])) #, # this is the point to label
                # textcoords="offset pixels", # how to position the text
                # xytext=(5,5), # distance from text to points (x,y)
                # ha='left') # horizontal alignment can be left, right or center

#plt.xlabel('$X$')
#plt.ylabel('$Y$',rotation=0)
plt.legend(loc="best")
#plt.grid() # minor
#plt.axis('off')
plt.axis('equal')
#plt.title('Problem')

##if using termux
plt.savefig('/sdcard/fwc-1/math/assignment/circle/figs/plot.png')
plt.savefig('/sdcard/fwc-1/math/assignment/circle/figs/plot.pdf')
#tpl.save('ellipse2.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/math/assignment/circle/figs/plot.pdf'"))
##else
#plt.show()
