#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int a[100010],dp[100010],n,dp1[100010];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  n=1;
	  while(cin>>a[++n])
	  dp[0]=0;
	  for(int i=0;i<n;++i)
	  	for(int j=i+1;j<=n;++j)
	  	{
	  		if(a[j] <=a[i]) dp[j] = max(dp[j],dp[i]+1);
	  	}
	  int res =0;
	  int res1=0;
	  dp1[0]=0;
	  for(int i=1;i<=n;++i)
	  	for(int j=0;j<i;++j)
	  	{
	  		if(a[j]<a[i])
	  			{
	  				dp1[i] = max(dp1[i],dp1[j]+1);
	  			}
	  	}
	  for(int i=1;i<=n;++i)
	  {
	  	res = max(res,dp[i]);
	  	res1 = max(res1,dp1[i]);
	  }
	  cout<<res<<endl;
	  cout<<res1;
	return 0;
}


//#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll a[maxn],n=1,dp1[maxn],dp2[maxn],len1,len2;
int main(){
	while(cin>>a[n]){
		n++;
	}
	n--,len1=1,len2=1;
	dp1[1]=a[1],dp2[1]=a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]<=dp1[len1]){
			dp1[++len1]=a[i];
		}
		else{
			ll k1=upper_bound(dp1+1,dp1+len1+1,a[i],greater<ll>())-dp1;
			dp1[k1]=a[i]; 
		}
		if(a[i]>dp2[len2]){
			dp2[++len2]=a[i];
		}
		else{
			ll k2=lower_bound(dp2+1,dp2+len2+1,a[i])-dp2;
			dp2[k2]=a[i];
		}
	}
	write(len1);
	puts("");
	write(len2);
	return 0;
}