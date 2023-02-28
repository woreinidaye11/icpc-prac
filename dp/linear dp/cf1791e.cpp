#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int t,n;
int a[200020],dp[200020];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>t;
	  while(t--)
	  {
	  	cin>>n;
	  	for(int i=1;i<=n;++i) cin>>a[i];
	  	memset(dp,0,sizeof dp);
	  	for(int i=1;i<n;++i)
	  	{
	  		if(a[i] <=0 && a[i+1] <=0 || a[i] <=0 && abs(a[i]) >abs(a[i+1]) || a[i+1]<=0 &&abs(a[i+1]) >abs(a[i]))
	  		{
	  			dp[i] += 1;
	  			dp[i+1]+=1;
	  		}
	  	}
	  	ll res=0;
	  	for(int i=1;i<=n;++i)
	  	{
	  		dp[i] %=2;
	  		if(dp[i] == 1) res+=abs(a[i]);
	  		else res+=a[i];
	  	}
	  	cout<<res<<endl;
	  }
	return 0;
}