#!/usr/bin/env python

from mpl_toolkits.basemap import Basemap
from mpl_toolkits.mplot3d import Axes3D, proj3d

import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np


#-     Create New Figure     
fig = plt.figure()


#-     Construct the Basemap
#mp = Basemap( width=1500000,height=1125000,
#              resolution='l',area_thresh=100.,projection='lcc',
#              lat_1=32,lat_2=44,lat_0=38,lon_0=-120)
mp = Basemap( projection='ortho',lon_0=-120,lat_0=39,resolution='l' )

# draw the edge of the mp projection region (the projection limb)
mp.drawcoastlines(linewidth=0.25)
mp.drawcountries(linewidth=0.25)


# draw lat/lon grid lines every 30 degrees.
#mp.drawmeridians(np.arange(0,360,1),  labels=[True, False, False, True])
#mp.drawparallels(np.arange(-90,90,1), labels=[False, True, True, False])

#mp.drawstates(linewidth=1)
#mp.drawcountries(linewidth=2)

mp.shadedrelief()


plt.show()

