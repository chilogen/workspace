import requests,re
from pprint import pprint
url='https://kyfw.12306.cn/otn/resources/js/framework/station_name.js?station_version=1.9025'
response=requests.get(url,verify=False)
ans1=re.findall(u'([\u4e00-\u9fa5]+)\|([A-Z]+)',response.text)
print('StationList=')
pprint(dict(ans1),indent=4)
print('Eng2Chn=')
ans2=dict()
for key in dict(ans1):
	ans2[dict(ans1)[key]]=key
pprint(ans2,indent=4)