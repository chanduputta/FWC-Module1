#Code by Shreyash Chandra (works on termux)
#October 15, 2022
#License
#https://www.gnu.org/licenses/gpl-3.0.en.html
#To find the locus of mid point of PQ where P is (1,0) and Q is a point on the locus y**2 = 8*x --eqn 


#Python libraries for math and graphics
import numpy as np
from sympy import Symbol,solve,diff
import matplotlib.pyplot as plt
from numpy import linalg as LA
from math import *
#if using termux
import subprocess           
import shlex
#end if



import sys                                          #for path to external scripts
sys.path.insert(0,'/sdcard/Download/CoordGeo/CoordGeo')         #path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import conic_quad
#Generating points on a Given parabola
def parab_point(y,a):
	x = y**2/a
	return x
#Generating points on a  locus 
def Locus_point(y,a):
	x = (y**2+2)/a
	return x 
#Point of intersection of conic with line  
def inter_pt(m,q,V,u,f):
    a = m@V@m
    b = m@(V@q+u)
    c = conic_quad(q,V,u,f)
    l1,l2 =np.roots([a,2*b,c]) 
#    print(a,b,c)
    x1 = q+l1*m
    x2 = q+l2*m
    return x2 


#equation of conic formula
#y**2 = 8*x ------given locus eqn

#Input parameters from given eqn

V = np.array(([0,0],[0,1]))
#print(V)
u = np.array([-4,0])
#print(u)
f = 0 


#given point
P = np.array([1,0])


#symbols
x = Symbol('x')
y = Symbol('y')
X=np.array([x,y])


#section formula for 1:1 
#X = (Q+P)/2
Q = 2*X - P


q_locus = conic_quad(X,V,u,f)	# given locus
x_locus = conic_quad(Q,V,u,f)   # obtained/req locus
print("------------------------------------------------")
print(q_locus,"= 0 --> given locus")
print(x_locus,"= 0 --> req locus")
print("------------------------------------------------")
print("---verification-----")
n = int(input("Input y-coordinate to generate point on abtained Locus: "))	
#Point on Given Locus
X = np.array([Locus_point(n,4),n])


#Point on given Parab 

m = dir_vec(P,X)

Q = np.array(inter_pt(m,X,V,u,f))

print("verification of X == (Q+P)/2 or not")
comparison = X == (Q+P)/2
	
if(comparison.all()):
	print("-----✓✓----locus is verified----✓✓----")
else:
	print("xxxxxxxxxYou have to work on itxxxxxxxxxx")
########################ploting############
#parameters
#Q = np.zeros(2)
#X = (Q+P)/2

#generate the locus
y = np.linspace(-6, 6, 500)
x = ((y ** 2)+2)/4
k = np.linspace(-10, 10, 50000)
h = (k ** 2)/8
#generate line
x_QP = line_gen(Q,P)
#plotting the locus
plt.plot(h, k, label= "{}=0 given eq".format(q_locus))
plt.plot(x, y, label= "{}=0 msrd eq".format(x_locus/4))
#plot line
plt.plot(x_QP[0,:],x_QP[1,:])
#Labeling the coordinates
tri_coords = np.vstack((P,X,Q)).T
plt.scatter(tri_coords[0, :], tri_coords[1, :])
vert_labels = ['P','X','Q']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
                 (tri_coords[0, i], tri_coords[1, i]),
                 textcoords="offset points",
                 xytext=(0, 10),
                 ha='center')
    plt.xlabel('$x$')
    plt.ylabel('$y$')
    plt.title('Plot of locus equations')
    plt.legend(loc='best')
    plt.grid()
    plt.axis('equal')

##if using termux
plt.savefig('/sdcard/download/python/conic/fig/conicfig.pdf')
subprocess.run(shlex.split("termux-open /sdcard/download/python/conic/fig/conicfig.pdf"))          
#else     
#plt.show()
