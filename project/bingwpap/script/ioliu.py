##爬取 https://bing.ioliu.cn/ 图片
##站主 github:https://github.com/xCss/bing

import requests
import urllib
import shutil
import os
from bs4 import BeautifulSoup

def GetAllPic(w,h,max):
	url1 = 'https://bing.ioliu.cn/?p='
	url2 = 'https://bing.ioliu.cn/'
	decription = []
	imageurl = []
	filename = []
	for page in range(1,max+1):
		tmpurl1 = url1+str(page)
		response = requests.get(tmpurl1)
		print('collect information from page : ' + str(page))
		soup = BeautifulSoup(response.text,'lxml')
		div = soup.findAll('div')
		for d in div:
			if(d['class'][0] == 'card'):
				tmpurl2 = url2 + d.a['href']

				tmpstr = d.img['src']
				strlen = len(tmpstr) - 11
				tmpstr = tmpstr[:strlen]+str(w)+'x'+str(h)+'.jpg'

				tmpfilename = d.p.em.contents[0]

				decription.append(tmpurl2)
				imageurl.append(tmpstr)
				filename.append(tmpfilename)
		print('page '+str(page)+' done')

	num=len(filename)
	path='/home/public/Picture/bing/'
	head={
		"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
		'Accept-Encoding':	'gzip, deflate',
		'Accept-Language':	'en-US,en;q=0.5',
		'Cache-Control':	'max-age=0',
		'Connection':	'keep-alive',
		'Host':	'h1.ioliu.cn',
		'Upgrade-Insecure-Requests':	'1',
		'User-Agent':	'Mozilla/5.0 (X11; Linux x86_64; rv:58.0) Gecko/20100101 Firefox/58.0',
	}

	for index in range(num):
		GetImage(imageurl[index],filename[index]+'.jpg',head,path+'image/')
		Getdescription(decription[index],filename[index]+'.txt',path+'doc/')	

def GetImage(url,filename,head,imagepath):
	if os.path.exists(imagepath+filename):
		print(filename+' exists,ignore')
		return
	print('get '+filename+'--->('+url+')')
	req=urllib.request.Request(url,None,head)
	res=urllib.request.urlopen(req)
	with open(filename,'wb') as f:
		f.write(res.read())
	shutil.move(filename,imagepath)

def Getdescription(url,filename,textpath):
	if os.path.exists(textpath+filename):
		print(filename+' exists,ignore')
		return
	print('get '+filename+'--->('+url+')')
	res=requests.get(url)
	soup=BeautifulSoup(res.text,'lxml')
	meta=soup.findAll('meta')
	with open(filename,'w') as f:
		i=0
		for m in meta:
			if m.has_attr('content'):
				i=i+1
				if(i>10):
					f.write(m['content'])
					f.write('\n')
	shutil.move(filename,textpath)

GetAllPic(1920,1080,5)
