import numpy as np
import matplotlib.pyplot as plt
import tikzplotlib as tpl

import subprocess
import shlex
import sys
sys.path.insert(0,'/sdcard/fwc-1/math/assignment/CoordGeo')
from line.funcs import *
from conics.funcs import circ_gen

##Optimization to find 'x' for maximum area
a = 5
b = 3
def f(x):
    return (2*a*(x**3)-x**4)
def df(x):
    return (6*a*(x**2)-4*x**(3))

#For maxima using gradient ascent
cur_x = 1
alpha = 0.0001 
precision = 0.000000001 
previous_step_size = 1
max_iters = 10000000
iters = 1000

#Gradient ascent calculation
while (previous_step_size > precision) & (iters < max_iters) :
    prev_x = cur_x             
    cur_x += alpha * df(prev_x)   
    previous_step_size = abs(cur_x - prev_x)   
    iters+=1 

max_val = f(cur_x)
print('max point:',cur_x)
print("max val:", max_val)
print("max area using g.ascent:", np.sqrt(max_val)*(b/a))
print("max area using formula:", np.sqrt(27/16)*a*b)

### plotting ###

## plotting sketch
#O = np.array([0,0])
#A = np.array([-4,-3])
#B = np.array([4,-3])
#C = np.array([0,5])
#D = np.array([0,-3])
#E = np.array([0,-5])
#
#x_AB = line_gen(A,B)
#x_BC = line_gen(B,C)
#x_AC = line_gen(A,C)
#x_CE = line_gen(E,C)
#x_AO = line_gen(A,O)
#x_CC = circ_gen(O,a)
#plt.plot(x_AB[0,:],x_AB[1,:],color='black')#,label='$AB$')
#plt.plot(x_AO[0,:],x_AO[1,:],color='black',linestyle='dotted')#,label='$AB$')
#plt.plot(x_BC[0,:],x_BC[1,:],color='black')#,label='$BC$')
#plt.plot(x_CE[0,:],x_CE[1,:],color='black')#,label='$CD$')
#plt.plot(x_AC[0,:],x_AC[1,:],color='black')#,label='$BC$')
#plt.plot(x_CC[0,:],x_CC[1,:],color='black')#,label='$BC$')
#
###Labeling the coordinates
#plm_coords = np.vstack((O,A,B,C,D,E)).T
#plt.scatter(plm_coords[0,:], plm_coords[1,:])
#vert_labels = ['O','A','B','C','D','E']
#for i, txt in enumerate(vert_labels):
#    plt.annotate(txt, # this is the text
#                 (plm_coords[0,i], plm_coords[1,i]))
#
#plt.text(0.2,-1.5,'$(h-a)$')
#plt.text(-1.5,-2.8,'$b$')
#plt.text(-2.2,-1.3,'$a$')
#plt.axis('off')
#
#plt.savefig('/sdcard/fwc-1/optimization/figs/plot.png')
#plt.savefig('/sdcard/fwc-1/optimization/figs/plot.pdf')
##tpl.save('plot.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
#subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/optimization/figs/plot.pdf'"))
## plot end

#Plotting f(x)
x= np.linspace(-2,11,1000)
y= f(x)
label_str = "$2ax^3-x^4$"
plt.plot(x,y,label=label_str)
plt.plot(cur_x,max_val,'o')
plt.text(cur_x, max_val,f'P({cur_x:.4f},{max_val:.4f})')

plt.xlabel('$x$')
plt.ylabel('$R^2$',rotation=0)
plt.grid() 
plt.axis('auto')

plt.savefig('/sdcard/fwc-1/optimization/figs/fx.png')
plt.savefig('/sdcard/fwc-1/optimization/figs/fx.pdf')
#tpl.save('fx.tex', axis_width=r'\figwidth', axis_height=r'\figheight')
subprocess.run(shlex.split("termux-open '/sdcard/fwc-1/optimization/figs/fx.pdf'"))
# f(x) plot end
