#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int t,n,m,k,p,ans;
const int N = 200010;
int h[N],e[N],ver[N],ne[N],idx;
int h1[N],e1[N],ver1[N],ne1[N],idx1;
int dis[N],dp[N][55];
int vis_dp[N][55]; //判断是否存在0环的情况
bool vis[N],flag;
void add(int a,int b,int c)
{
	ver[++idx] = b,e[idx] = c;
	ne[idx] = h[a],h[a] = idx;
}
void add1(int a,int b,int c)
{
	ver1[++idx1] = b,e1[idx1] = c;
	ne1[idx1] = h1[a],h1[a] = idx1;
}
void spfa(int s) //反向图和正向图跑一遍
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x]=0;
		for(int i = h[x];i;i=ne[i])
		{
			int y = ver[i], z=e[i];
			if(dis[y] > dis[x]+z)
			{
				dis[y] = dis[x] +z;
				if(!vis[y]) 
				{
				q.push(y);
				vis[y] =1;
				}	
			}
		}
	}
}
int dfs(int x ,int k)
{
	if(dp[x][k] !=-1) return dp[x][k];
	vis_dp[x][k] =1;
	dp[x][k]  =0;
	for(int i = h1[x];i;i=ne1[i])
	{
		int y = ver1[i], z = k+ dis[x] -dis[y] -e1[i];
		if(z>=0)
		{
			if(vis_dp[y][z] ==1)
				flag =0;
			dp[x][k] += dfs(y,z);
			dp[x][k] %=p;
		}
	}
	vis_dp[x][k]=0;
	return dp[x][k];
}
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>t;
	  while(t--)
	  {
	  	idx=0;
	  	idx1=0;
	  	ans=0;
	  	flag=1;
	  	memset(h1,0,sizeof h1);
	  	memset(h,0,sizeof h);
	  	memset(dp,-1,sizeof dp);
	  	ans =0,flag =true;
	  	cin>>n>>m>>k>>p;
	  	for(int i=1;i<=m;++i)
	  	{
	  		int a1,b,c;
	  		cin>>a1>>b>>c;
	  		add(a1,b,c);
	  		add1(b,a1,c);
	  	}
	  	spfa(1);
	  	dp[1][0]=1;
	  	for(int i=0;i<=k;++i)
	  	{
	  		ans+=dfs(n,i);
	  		ans%=p;
	  	}
	  	dfs(n,k+1);
	  	if(!flag)
	  		cout<<"-1"<<endl;
	  	else
	  		cout<<ans<<endl;
	  }
	return 0;
}