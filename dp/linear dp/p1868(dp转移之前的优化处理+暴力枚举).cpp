#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int n,p;
int f[3000030];
ll res;
vector<int>pre[3000030];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>n;
	  for(int i=1;i<=n;++i)
	  {
	  	int x,y;
	  	cin>>x>>y;
	  	pre[y].pb(x);
	  	p = max(p,y);
	  }
	  for(int i=0;i<=p;++i)
	  {	
	  	if(i!=0)
	  	f[i] = f[i-1];
	  	for(int j = 0;j<pre[i].size();j++)
	  		f[i] = max(f[i], ((pre[i][j]-1>=0)?f[pre[i][j]-1]:0) + i-pre[i][j]+1);
	  }
	  cout<<f[p]<<endl;
	return 0;
}