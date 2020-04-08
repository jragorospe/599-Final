''' Import proper python modules to handle
- serial communication
- casting to Google Chromecast '''
import pychromecast
import serial

from pychromecast.controllers.youtube import YouTubeController

''' Receive data from serial port. This will depend on what 
serial port is available and which one you are writing to. '''
ser = serial.Serial('/dev/ttyACM0', 9600)

# Determine what you Chromecast name is using Google Home
CAST_NAME = "Living Room TV"

# Video I.D for casting. Can be found here - https://www.youtube.com/watch?v=VIDEO_ID
VIDEO_ID = "5qap5aO4i9A"

# Get the available Chromecasts connected to your network
chromecasts = pychromecast.get_chromecasts()
cast = next(cc for cc in chromecasts if cc.device.friendly_name == CAST_NAME)
cast.wait()
yt = YouTubeController()
cast.register_handler(yt)

''' Receive serial information. Handles only HIGH input, so it doesn't 
matter what is transmitted. Can be configured to handle cases. '''

while 1:
    serial_line = ser.readline()
    yt.play_video(VIDEO_ID)