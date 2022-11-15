import numpy as np
import numpy.linalg as LA
import sympy as sp
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
#import tikzplotlib as tpl

import sys
sys.path.insert(0,'/sdcard/fwc-1/math/assignment/CoordGeo')
from line.funcs import *

import subprocess
import shlex

def line_conic_intersect(V,u,f,q,m):
    D = (m.T@(V@q + u))**2 - (q.T@V@q + 2*u.T@q + f)*(m.T@V@m)
    
    if(D[0,0] < 0):
        return -1, np.nan, np.nan 
    
    if(m.T@V@m < 1e-16): #lim-->0 
        k = -(q.T@V@q + 2*u.T@q + f)/(2*m.T@(V@q + u)) 
        return 0, q+k*m, np.nan

    d = np.sqrt(D)
    k1 = (d - m.T@(V@q + u))/(m.T@V@m)
    k2 = (-d - m.T@(V@q + u))/(m.T@V@m)

    return 1, q+k1*m, q+k2*m

def conic_intersect(V1,u1,f1,V2,u2,f2):
    
    K1 = np.block([[V1,u1],[u1.T,f1]])
    K2 = np.block([[V2,u2],[u2.T,f2]])
    
    x = sp.Symbol('x')
    M1 = sp.Matrix(K1)
    M2 = sp.Matrix(K2)
    M = M1 + x*M2
    eq = M.det()
    soln = sp.solveset(eq, x)
    print(soln)

    intersect_pts = []
    
    for i in soln:
        if(not i.is_real): 
            print("complex found")
            continue
        
        mu = float(i)
        K = K1 + mu*K2
        V = K[:2,:2]
        u = K[:2, 2].reshape(2,1)
        f = K[2,2]

        lamda, gamma = LA.eigh(V)
        if(lamda[1] == 0):      # If eigen value negative, present at start of lamda 
            lamda = np.flip(lamda)
            gamma = np.flip(gamma,axis=1)
        
        if(LA.det(V) > 0):
            print("Det of N is positive")
            continue
        elif(LA.det(V) == 0):
            p1 = gamma[:,0].reshape(2,1)
            eta = u.T@p1
            print("eta:",eta)
            a = np.vstack((u.T + eta*p1.T, V))
            print(a)
            b = np.vstack((-f, eta*p1-u)) 
            c = LA.lstsq(a,b,rcond=None)[0] 
            print("Det of N is 0", c) 
            continue
        else:
            print("Det of N is negative")
            c = -LA.inv(V)@u #h, POI
            print('H = ',c.T)

        n1 = gamma@np.array([np.sqrt(np.abs(lamda[0])), np.sqrt(np.abs(lamda[1]))])
        n1 = n1.reshape(2,1)
        n2 = gamma@np.array([np.sqrt(np.abs(lamda[0])), -np.sqrt(np.abs(lamda[1]))])
        n2 = n2.reshape(2,1)

        omat = np.array([[0,-1],[1,0]]) 
        m1 = omat@n1
        m2 = omat@n2
        
        print("N1 and m1",end=" ") #common points
        code, p1, p2 = line_conic_intersect(V1,u1,f1,c,m1)
        if(code == 0):
            print("1")
            intersect_pts.append(p1)
        elif(code > 0):
            print("2")
            intersect_pts.append(p1)
            intersect_pts.append(p2)
        else:
            print("0")
            pass

        print("N1 and m2",end=" ") #common points
        code, p1, p2 = line_conic_intersect(V1,u1,f1,c,m2)
        if(code == 0):
            print("1")
            intersect_pts.append(p1)
        elif(code > 0):
            print("2")
            intersect_pts.append(p1)
            intersect_pts.append(p2)
        else:
            print("0")
            pass
 
    return np.unique(intersect_pts, axis=0), c, m1, m2 

# Original conics A and B
A = np.array([0,0,-4,0,1,0,-4,0,0]).reshape(3,3)
B = np.array([0,0.5,0,0.5,0,0,0,0,1]).reshape(3,3)

# Dual conics C and D
C = LA.det(A)*LA.inv(A)
D = LA.det(B)*LA.inv(B)
print("Dual of A")
print(C)
print("Dual of B")
print(D)

intersect_pts, cenH, m1, m2 = conic_intersect(
        C[0:2,0:2],
        C[0:2,2].reshape(2,1),
        C[2,2],
        D[0:2,0:2],
        D[0:2,2].reshape(2,1),
        D[2,2]
    )
print(intersect_pts)
#print(cenH)
#print(m1)
#print(m2)

#### plotting ####

plt.xlabel('$x$')
plt.ylabel('$y$',rotation=0)
plt.grid() 
plt.axis('equal')

x = np.linspace(-4.5, 4.5, 100)
y = np.linspace(-3, 3, 100)
x, y = np.meshgrid(x, y)
intersect_pts = intersect_pts.reshape(1,2)
cen = cenH.reshape(1,2)

## plot 1 ...
#plt.contour(x,y,(x*y),[-1],linestyles='-',colors='red') #label='Curve (2)')
#plt.contour(x,y,y**2-8*x,[0],linestyles='-',colors='blue') #label='Curve (1)')
#plt.contour(x,y,x-y,[-2], linestyles='-',colors='black') #label='Common Tangent')
## labelling
#colors = ['black', 'red', 'blue']
#lines = [Line2D([0], [0], color=c, linewidth=1, linestyle='-') for c in colors]
#labels = ['common tangent', 'curve (2)', 'curve (1)']
#plt.legend(lines, labels, loc="best")
#plt.savefig('/sdcard/fwc-1/math/assignment/conic/figs/comm_tan.png')
#plt.savefig('/sdcard/fwc-1/math/assignment/conic/figs/comm_tan.pdf')
##tpl.save('comm_tan.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
#subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/math/assignment/conic/figs/comm_tan.pdf'"))
##... plot 1 #

# plot 2 ...
k1 =  0.7
k2 = -1
k3 = -1.1
line1 = line_dir_pt(m1,cenH,k1,k2)
line2 = line_dir_pt(m2,cenH,k1,k3)
plt.plot(line1[0,:],line1[1,:],color='black')
plt.plot(line2[0,:],line2[1,:],color='black')
plt.contour(x,y,2*y**2-x,[0],linestyles='-',colors='turquoise') #label='Dual of (1)')
plt.contour(x,y,x*y,[-0.25],linestyles='-',colors='tomato') #label='Dual of (2)')
#Labelling
#P
plt.scatter(intersect_pts.T[0],intersect_pts.T[1])
plt.annotate('P',(intersect_pts.T[0],intersect_pts.T[1]+0.3))
#H
plt.scatter(cen.T[0],cen.T[1])
plt.annotate('H',(cen.T[0],cen.T[1]+0.3))
#legend
colors = ['turquoise', 'tomato', 'black']
lines = [Line2D([0], [0], color=c, linewidth=1, linestyle='-') for c in colors]
labels = ['Dual of (1)', 'Dual of (2)', 'PoSL (10)']
plt.legend(lines, labels, loc='lower left')
plt.savefig('/sdcard/fwc-1/math/assignment/conic/figs/dual_int.png')
plt.savefig('/sdcard/fwc-1/math/assignment/conic/figs/dual_int.pdf')
#tpl.save('dual_int.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
#subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/math/assignment/conic/figs/dual_int.pdf'"))
#... plot 2 #
