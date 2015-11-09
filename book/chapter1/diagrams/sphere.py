#!/usr/bin/env python

# -*- coding: utf-8 -*-
from mpl_toolkits.mplot3d import Axes3D, proj3d
from mpl_toolkits.basemap import Basemap
import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
from itertools import product, combinations
import pylab, math


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
plt.figure(figsize=(14,14))


mp = Basemap( width=1500000,height=1125000,
              resolution='l',area_thresh=100.,projection='lcc',
              lat_1=32,lat_2=44,lat_0=38,lon_0=-120)

# draw the edge of the mp projection region (the projection limb)
mp.drawcoastlines(linewidth=0.25)
mp.drawcountries(linewidth=0.25)


# draw lat/lon grid lines every 30 degrees.
mp.drawmeridians(np.arange(0,360,1),  labels=[True, False, False, True])
mp.drawparallels(np.arange(-90,90,1), labels=[False, True, True, False])

mp.drawstates(linewidth=1)
mp.drawcountries(linewidth=2)

mp.shadedrelief()

#  Write the figure
plt.savefig('figure_1_1.png')

#---------------------------------#
#-      Create Vector Plot       -#
#---------------------------------#
fig2 = plt.figure(figsize=(14,14))

ax = fig2.gca(projection='3d')

#  Draw Axes
ax.plot([ 0,1],[ 0,0],[ 0,0],'b')
ax.plot([-1,0],[ 0,0],[ 0,0],'b--')
ax.plot([ 0,0],[-1,0],[ 0,0],'b--')
ax.plot([ 0,0],[ 0,1],[ 0,0],'b')
ax.plot([ 0,0],[ 0,0],[-1,0],'b--')
ax.plot([ 0,0],[ 0,0],[ 0,1],'b')

#  Draw Spheres
ax.plot(np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)),
        np.cos(np.linspace(       0, 4*np.pi, 360)),
        np.linspace(       0,       0, 360),
        'b')

ax.plot(np.linspace(       0,       0, 360),
        np.cos(np.linspace(       0, 4*np.pi, 360)),
        np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)),
        'b')

ax.plot(np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)),
        np.linspace(       0,       0, 360),
        np.cos(np.linspace(       0, 4*np.pi, 360)),
        'b')


#  Add Arrows
theta = 45 * math.pi / 180.0
phi   = 45 * math.pi / 180.0
px = math.sin(theta) * math.cos(phi)
py = math.sin(theta) * math.sin(phi)
pz = math.cos(theta)
arrow = Arrow3D( [0, px], [0, py], [0, pz], arrowstyle='-|>', color='k', lw=2 )
ax.add_artist( arrow )

#  Add Arrow Arcs
ar = 0.4
ax.plot(ar * np.sin(np.linspace(0, np.pi/4, 45)),
        ar * np.cos(np.linspace(0, np.pi/4, 45)),
        ar * np.linspace(       0,       0, 45),
        'r')

theta = np.linspace(np.pi/4, np.pi/4, 45)
phi   = np.linspace(0, np.pi/4, 45)

px = ar * np.cos(theta) * np.cos(phi)
py = ar * np.sin(theta) * np.cos(phi)
pz = ar * np.sin(phi)

ax.plot( px, py, pz, 'g')

#  Write the figure
plt.savefig('figure_1_2.png')

plt.show()
