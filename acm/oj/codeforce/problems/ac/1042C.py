from functools import reduce
n=int(input())
a=[int(x) for x in input().split(" ")]
#pos=[i+1 for i,x in enumerate(a) if x>0]
#zero=[i+1 for i,x in enumerate(a) if x==0]
#neg=[i+1 for i,x in enumerate(a) if x<0]
part1=[]
part2=[]
neg=[]
s=-1
for i,x in enumerate(a):
	if x<0:
		if s==-1:
			s=i
			continue
		if(a[s]<x):
			neg.append(s+1)
			s=i
		else:neg.append(i+1)
	if x==0:part1.append(i+1)
	if x>0:part2.append(i+1)
ans=1
if len(neg)%2==0 and s!=-1:
	part1.append(s+1)
if len(neg)%2==1:
	part2.append(s+1)
part2=part2+neg


s=10**10
for i in part1:
	if s==10**10:
		s=i
		continue
	print(1,s,i)
	s=i
if s!=10**10 and len(part2)!=0:print(2,s)

s=10**10
for i in part2:
	if s==10**10:
		s=i
		continue
	print(1,s,i)
	s=i