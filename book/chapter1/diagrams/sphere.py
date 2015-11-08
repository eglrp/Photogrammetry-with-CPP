#!/usr/bin/env python

# -*- coding: utf-8 -*-
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
from itertools import product, combinations
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.set_aspect("equal")

#  Create the Map Object
map = Basemap( projection='ortho',
               lat_0=45,
               lon_0=-100,
               resolution='l')

#draw cube
r = [-1, 1]
for s, e in combinations(np.array(list(product(r,r,r))), 2):
        if np.sum(np.abs(s-e)) == r[1]-r[0]:
                    ax.plot3D(*zip(s,e), color="b")

#draw sphere
HRAN=30j
u, v = np.mgrid[0:2*np.pi:HRAN, 0:np.pi:10j]
x=np.cos(u)*np.sin(v)
y=np.sin(u)*np.sin(v)
z=np.cos(v)
ax.plot_wireframe(x, y, z, color="r")


#   Plot
plt.show()

