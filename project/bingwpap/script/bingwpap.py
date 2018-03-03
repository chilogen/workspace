import spider
import os
from exep import *
import configparser

config=configparser.ConfigParser()
config.read('../config.ini')
try:
	a=config.get('aaa','language')
	b=config.get('aaa','platform script')
	c=config.get('aaa','picture flode')
	d=config.get('aaa','install path')
	spider.GetPic(a,c,d)
	os.system(d+'shell/'+b)
except NetworkException as e:
	print(e.arg)