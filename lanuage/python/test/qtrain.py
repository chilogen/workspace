# conding: gb2312
"""
    Usage:
        qtrain [-gdtkzsa] <data> <start> <end>

    Option:
        a          不限
        g          高铁
        d          动车
        t          特快
        k          快车
        z          直达
        s          学生
        
    Example：
        qtrain 2017-08-21 海南    成都
        qtrain -ks  2017-08-21 海南   成都
"""
from docopt import docopt
from pprint import pprint
from StationList import *
from prettytable import PrettyTable
import re,requests,sys

def Main():
    arg=docopt(__doc__)
    data=arg['<data>']
    start=StationList[arg['<start>']]
    end=StationList[arg['<end>']]
    if arg['-s']:   purpose_code='0x00'
    else: purpose_code='ADULT'
    url='https://kyfw.12306.cn/otn/leftTicket/query?leftTicketDTO.train_date={}&leftTicketDTO.from_station={}&leftTicketDTO.to_station={}&purpose_codes=ADULT'.format(data,start,end,purpose_code)
    response=requests.get(url,verify=False)
    ResList=ProcessResult(response)
    show(ResList,arg)
    
def ProcessResult(response):
    res=response.json()['data']['result']
    ind2inf=[3,4,6,7,5,8,9,10,26,29,24,28,23,30,31,32]
    List=[]
    for x in res:
        List.append(GetList(x,ind2inf))
    return List

def GetList(x,ind2inf):
    x=x.split('|')
    List=[]
    for j in ind2inf:
        List.append(x[j])
    return List

def show(List,arg):
    index=['车次','始发站','出发站','到达站','终点站','发车时间','到达时间','历时','无座','硬座','软座','硬卧','软卧','二等座','一等座','商务座']
    pt=PrettyTable()
    pt._set_field_names(index)
    for x in List:
        for i,m in enumerate(x):
            if m=='':   x[i]='-'
        x[1]=Eng2Chn[x[1]]
        x[2]=Eng2Chn[x[2]]
        x[3]=Eng2Chn[x[3]]
        x[4]=Eng2Chn[x[4]]
        if arg['-a']:
            pt.add_row(x)
        else:
            s='-'+x[0].lower()[0]
            if arg[s]:
                pt.add_row(x)
    print(pt)

Main()
