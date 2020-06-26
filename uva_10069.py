import sys
t = input()
t = int(t)
sys.setrecursionlimit(100001)

def f(i,j,s1,s2,dp):
	if(j==len(s2)):
		return 1
	if(j>len(s2) or i>=len(s1)):
		return 0
	if(dp[i][j]!=-1):
		return dp[i][j]
	ans=0
	if(s1[i]==s2[j]):
		ans+=f(i+1,j+1,s1,s2,dp)+f(i+1,j,s1,s2,dp)
	else:
		ans+=f(i+1,j,s1,s2,dp)
	dp[i][j] = ans
	return ans


while(t):
	
	#print(dp)
	s1 = input()
	s2 = input()
	dp = [[-1 for i in range(len(s2))] for j in range(len(s1))]
	#print(dp)
	print(f(0,0,s1,s2,dp))
	t-=1