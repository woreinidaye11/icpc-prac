#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int n;
int a[1010][1010];
int dp[1010][1010];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>n;
	  for(int i=1;i<=n;++i)
	  {
	  	for(int j=1;j<=i;++j)
	  	{
	  		cin>>a[i][j];
	  	}
	  }
	  memset(dp,-1,sizeof dp);
	  dp[1][1]=a[1][1];
	  for(int i=1;i<n;++i)
	  {
	  	for(int j=1;j<=i;++j)
	  	{
	  		dp[i+1][j] = max(dp[i+1][j],dp[i][j]+a[i+1][j]);
	  		dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
	  	}
	  }
	  int res=0;
	  //cout<<dp[2][3];
	  for(int i=1;i<=n;++i)
	  {
	  	res = max(res,dp[n][i]);
	  }
	  cout<<res<<endl;
	return 0;
}