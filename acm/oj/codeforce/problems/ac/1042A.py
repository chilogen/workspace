def readint():
	a=int(input())
	return a

n=readint()
m=readint()
a=[]
ma=0
s=m

for i in range(n):
	j=readint()
	a.append(j)
	ma=max(j,ma)
	s=s+j

j=int(s/n)
if s%n!=0:
	j=j+1

ans1=max(j,ma)
ans2=ma+m

print(str(ans1)+" "+str(ans2))