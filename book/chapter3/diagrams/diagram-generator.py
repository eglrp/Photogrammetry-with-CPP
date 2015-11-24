#!/usr/bin/env python

from mpl_toolkits.basemap import Basemap
from mpl_toolkits.mplot3d import Axes3D, proj3d

import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
from itertools import product, combinations
import pylab, math



#--------------------------#
#-   Simple Arrow Class   -#
#--------------------------#
class Arrow3D(mpl.patches.FancyArrowPatch):
    
    def __init__(self, xs, ys, zs, *args, **kwargs):
        mpl.patches.FancyArrowPatch.__init__(self, (0,0), (0,0), *args, **kwargs)
        self._verts3d = xs, ys, zs
        
    def draw(self, renderer):
        xs3d, ys3d, zs3d = self._verts3d
        xs, ys, zs = proj3d.proj_transform(xs3d, ys3d, zs3d, renderer.M)
        self.set_positions((xs[0],ys[0]),(xs[1],ys[1]))
        mpl.patches.FancyArrowPatch.draw(self, renderer)




#   Plot
fig = plt.figure(figsize=(14,14))
ax = fig.gca(projection='3d')

#  Draw Axes
ax.plot([ 0,1],[ 0,0],[ 0,0],'b')
ax.plot([-1,0],[ 0,0],[ 0,0],'b--')
ax.plot([ 0,0],[-1,0],[ 0,0],'b--')
ax.plot([ 0,0],[ 0,1],[ 0,0],'b')
ax.plot([ 0,0],[ 0,0],[-1,0],'b--')
ax.plot([ 0,0],[ 0,0],[ 0,1],'b')


#  Draw Sphere
u = np.linspace( 0, 2 * np.pi, 500 )
v = np.linspace( 0, np.pi, 500 )

x = np.outer(np.cos(u), np.sin(v))
y = np.outer(np.sin(u), np.sin(v))
z = np.outer(np.ones(np.size(u)), np.cos(v))

ax.plot_surface( x, y, z )



plt.show()
