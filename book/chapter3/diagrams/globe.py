#!/usr/bin/env python2


#  Python Packages
import numpy as np
import matplotlib.pyplot as plt
import datetime
from mpl_toolkits.basemap import Basemap, shiftgrid
import math

lat1=39.0
lon1=-120.0
lat2=39.0
lon2=-77.0

lat_view=(lat1+lat2)/2.0
lon_view=(lon1+lon2)/2.0

bbox = max(math.fabs(lat1-lat2),math.fabs(lon1-lon2))


lat_min=lat_view - (bbox/2.0)
lat_max=lat_view + (bbox/2.0)
lon_min=lon_view - (bbox/1.5)
lon_max=lon_view + (bbox/1.5)


# make orthographic basemap.
m = Basemap(resolution='l',projection='ortho',lat_0=lat_view,lon_0=lon_view,width=1000000,height=1000000)

# create figure, add axes
fig = plt.figure()
ax = fig.add_subplot(111)

ax.set_title('Orthographic')

#  Build lines
meridians = np.arange(0,360,20)
parallels = np.arange(-90,90,20)


#  Draw the coastlines
m.drawcoastlines(linewidth=1.5)
m.drawparallels(parallels)
m.drawmeridians(meridians)

m.shadedrelief()


#  Draw a Great Circle
m.drawgreatcircle( lon1, lat1, lon2, lat2, linewidth=3 )


fig = plt.figure()
ax = fig.add_subplot(111)
ax.set_title('Mercator')

#  Build lines
m = Basemap(resolution='l',projection='merc',lat_0=lat_view,lon_0=lon_view,
            llcrnrlon=lon_min, llcrnrlat=lat_min,
            urcrnrlon=lon_max, urcrnrlat=lat_max )


meridians = np.arange(0,360,20)
parallels = np.arange(-90,90,20)


#  Draw the coastlines
m.drawcoastlines(linewidth=1.5)
m.drawparallels(parallels)
m.drawmeridians(meridians)

m.shadedrelief()


#  Draw a Great Circle
m.drawgreatcircle( lon1, lat1, lon2, lat2, linewidth=3)

plt.show()

