import requests
import json
import urllib
import time
import os
import shutil
from exep import *
from bs4 import BeautifulSoup


def GetPic(lan,imgpath,path):
	filename=time.strftime('%Y-%m-%d',time.localtime(time.time()))+'.jpg'
	if os.path.exists(imgpath+filename):
		raise FileExistsException(filename+' exists')
	url=ConstructURL(0,1)
	response=requests.get(url)
	if response.status_code!=200:
		raise NetworkException("can not get image url!")
	tp=json.loads(response.text)['images'][0]['url']
	imageurl='http://bing.com'+tp
	urllib.request.urlretrieve(imageurl,filename)
	shutil.move(filename,imgpath)
	return True
	

def ConstructURL(idx,n):
	return 'http://cn.bing.com/HPImageArchive.aspx?format=js&idx='+str(idx)\
			+'&n='+str(n)+'&mkt=zh-CN&mkt=zh-CN&quiz=1&fav=1'