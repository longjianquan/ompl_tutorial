from mpl_toolkits.mplot3d import Axes3D
import numpy
import matplotlib.pyplot as plt
data = numpy.loadtxt('path.dat')
#data1= numpy.loadtxt('/home/ljq/python test/111.txt')
data1= numpy.loadtxt('/home/ljq/ompl_tutorial/OMPL_Sample/GeomPlanningSE2/33.txt')
#data1= numpy.loadtxt('obstacle.dat')

x=[]
y=[]
fig = plt.figure()
for i in range(200):
        for j in range(200):
                if (data1[i][j]==0.0):
                        x.append(i)
                        y.append(j)
                        
                

#ax = fig.gca(projection='3d')
plt.plot(data[:,0],data[:,1],'.-')
plt.hold('on')
plt.grid('on')
#plt.fill(data1[:,0],data1[:,1],'r-')
plt.scatter(x,y)
plt.hold('on')
plt.grid('on')
plt.show()

