import requests
from bs4 import BeautifulSoup
url='http://idas.uestc.edu.cn/authserver/login?service=http://portal.uestc.edu.cn/index.portal'
UserAgent='Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:55.0) Gecko/20100101 Firefox/55.0'
header={'User-Agent':UserAgent}
session=requests.Session()
response=session.get(url,headers=header)
res=BeautifulSoup(response.content,'html.parser')
lt=res.find('input',{'name':'lt'})['value']
postdata={'username':'2016060107001',
			'password':'604003',
			'lt':lt,
			'dllt':'userNamePasswordLogin',
			'execution':'e1s1',
			'_eventId':'submit',
			'rmShown':'1'}
session.post(url,data=postdata,headers=header)
response=session.get('http://portal.uestc.edu.cn/index.portal?.pn=p346',headers=header)
print(response.content.decode('utf-8'))