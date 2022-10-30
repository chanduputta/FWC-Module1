#Code by Shreyash Chandra (works on termux)
#October 25s, 2022
#License
#https://www.gnu.org/licenses/gpl-3.0.en.html
#To find the angle |_QPR of thriangle inscribed in the circle x2 + y2 = 25 if Q and R coordinates are (3,4) & (-4,3) respectively . 


#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math
from math import *
import sys  #for path to external scripts
sys.path.insert(0,'/sdcard/Download/CoordGeo/CoordGeo')         #path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#if using termux
import subprocess
import shlex
#end if


# given points on coordinates as vectors
Q = np.array([3,4])
R = np.array([-4,3])

#Circle parameters from given eqn --> X^T X + 2u^T X + f  = 0
u = -np.zeros(2)
f = -25

#we get
O =  -u #center of circle
r = int(np.sqrt(np.dot(u,u)-f))  #LA.norm(Q-O) .....radius(-f) 

# To take random point on circle
n = int(input("Input an angle alpha[0 to 360] to generate a point on circle:"))#99
alpha = np.radians(n)
#print(alpha,"alpha")
x =r*np.cos(alpha)
y=r*np.sin(alpha)
P = np.array([x,y])
#print(P,"random point P")
check = np.linalg.norm(P)
#print(check,"= 5 or not")
M1 = dir_vec(P,Q)

M2 = dir_vec(P,R)

#The angle between two vectors is given by
#θ = cos^−1(#A^⊤B/∥A∥ ∥B∥)

d = M1@M2               #numerator
m1 = np.linalg.norm(M1)  
m2 = np.linalg.norm(M2)
teeta = np.arccos(d/(m1*m2))

degP = int(np.degrees(teeta)) # angle QPR


print("------------------solution--------------------------------")
print ("Measured the \N{MEASURED ANGLE} QPR of inscribed triangle PQR is = {}\N{DEGREE SIGN}.".format(degP))
print("where vertex P is {} on circle".format(P))
print("--------------------------------------------------------------")

########################ploting############

##Generating the circle
x_circ= circ_gen(O,r)

##Generating all lines
xQR = line_gen(Q,R)
xPR = line_gen(P,R)
xPQ = line_gen(P,Q)

#Plotting all lines
plt.plot(xQR[0,:],xQR[1,:],'--',color="green",label='side QR')
plt.plot(xPR[0,:],xPR[1,:],color="green")
plt.plot(xPQ[0,:],xPQ[1,:],color="green",label='\N{MEASURED ANGLE}QPR = {}$^\circ$'.format(degP))


#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


#Labeling the coordinates
tri_coords = np.vstack((O,Q,R,P)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','Q','R','P']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the txt
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center



plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.title('plot of an inscribed triangle PQR')
plt.grid() # minor
plt.axis('equal')


#if using termux                         
plt.savefig('/sdcard/download/python/circle/fig/circlefig.pdf')                       
subprocess.run(shlex.split("termux-open /sdcard/download/python/circle/fig/circlefig.pdf"))                     
#else
#plt.show()


