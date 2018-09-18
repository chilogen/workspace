
tn=[[]for i in range(8)]
vis=[0 for i in range(1010)]
ans=10**6

def check(x):
	state=0
	tans=0
	global ans
	for i in range(1,8):
		if x&(1<<i)==0 or len(tn[i])==0:
			continue
		tans=tans+tn[i][0]
		state=state|i
		if state==7:
			break;

	if state==7:
		ans=min(ans,tans)

n=int(input())
for i in range(n):
	t=input().split(" ")
	k=0
	for j in t[1]:
		k=k|(1<<(ord(j)-ord('A')))
	tn[k].append(int(t[0]))

for i in range(1,8):
	tn[i].sort()

for i in range(1,2**8-1):
	check(i)

if ans==10**6:
	print(-1)
else:
	print(ans)