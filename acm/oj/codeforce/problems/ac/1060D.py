n=int(input())

a=[]
b=[]
for i in range(n):
	inp=[int(x) for x in input().split(" ")]
	a.append(inp[0])
	b.append(inp[1])

a.sort()
b.sort()

ans=0

for i in range(n):
	ans=ans+max(a[i],b[i])+1

print(ans)