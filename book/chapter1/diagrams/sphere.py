#!/usr/bin/env python

# -*- coding: utf-8 -*-
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
from itertools import product, combinations


#draw cube
#r = [-1, 1]
#for s, e in combinations(np.array(list(product(r,r,r))), 2):
#        if np.sum(np.abs(s-e)) == r[1]-r[0]:
#                    ax.plot3D(*zip(s,e), color="b")

#draw sphere
#HRAN=30j
#u, v = np.mgrid[0:2*np.pi:HRAN, 0:np.pi:10j]
#x=np.cos(u)*np.sin(v)
#y=np.sin(u)*np.sin(v)
#z=np.cos(v)
#ax.plot_wireframe(x, y, z, color="r")


#   Plot
plt.figure(figsize=(8,8))


mp = Basemap( width=1500000,height=1125000,
              resolution='l',area_thresh=100.,projection='lcc',
              lat_1=32,lat_2=44,lat_0=38,lon_0=-120)

# draw the edge of the mp projection region (the projection limb)
mp.drawcoastlines(linewidth=0.25)
mp.drawcountries(linewidth=0.25)

# draw the edge of the mp projection region (the projection limb)
#mp.drawmpboundary(fill_color='aqua')


# draw lat/lon grid lines every 30 degrees.
mp.drawmeridians(np.arange(0,360,1),  labels=[True, False, False, True])
mp.drawparallels(np.arange(-90,90,1), labels=[False, True, True, False])

mp.drawstates(linewidth=1)
mp.drawcountries(linewidth=2)

mp.shadedrelief()


#---------------------------------#
#-      Create Vector Plot       -#
#---------------------------------#
fig2 = plt.figure(figsize=(8,8))

ax = fig2.gca(projection='3d')
ax.plot([-1,1],[0,0],[0,0])
ax.plot([0,0],[-1,1],[0,0])
ax.plot([0,0],[0,0],[-1,1])

ax.plot(np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)),
        np.cos(np.linspace(       0, 4*np.pi, 360)),
        np.linspace(       0,       0, 360))

ax.plot(np.linspace(       0,       0, 360),
        np.cos(np.linspace(       0, 4*np.pi, 360)),
        np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)))

ax.plot(np.sin(np.linspace(-2*np.pi, 2*np.pi, 360)),
        np.linspace(       0,       0, 360),
        np.cos(np.linspace(       0, 4*np.pi, 360)))


plt.show()
