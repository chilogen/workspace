import os
import math
import matplotlib.pyplot as plt
import matplotlib.animation as ani
from PIL import Image

def GetIM():
	cmd1="adb shell screencap -p /sdcard/screen.png"
	cmd2="adb pull /sdcard/screen.png"
	os.system(cmd1)
	os.system(cmd2)
	Img=Image.open("./screen.png")
	return Img


X=[0,0]
Y=[0,0]
k=1.35

def Mouse(even):
	global done
	if(done):
		X[0]=even.xdata
		Y[0]=even.ydata
		done=False
	else:
		X[1]=even.xdata
		Y[1]=even.ydata
		done=True
	if(done):
		press()

def press():
	cmd="adb shell input swipe 0 0 1 1 "
	dst=math.hypot(X[1]-X[0],Y[1]-Y[0])
	ms=int(k*dst)
	cmd=cmd+str(ms)
	os.system(cmd)

done=True
while(1):
	img=GetIM()
	fig=plt.figure()
	plt.imshow(img,animated=True)
	fig.canvas.mpl_connect("button_press_event",Mouse)
	plt.show()
