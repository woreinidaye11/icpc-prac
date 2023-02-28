#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int n,res;
int a[105];
int f1[105],f2[105];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>n;
	  for(int i=1;i<=n;++i) cin>>a[i];
	  for(int i=1;i<=n;++i)
	  	for(int j =0;j<i;++j)
	  	{
	  		if(a[j] < a[i]) f1[i] = max(f1[i],f1[j] +1);
	  	}
	  for(int i=n;i>=1;--i)
	  	for(int j = n+1;j>i;--j)
	  	{
	  		if(a[j]<a[i]) f2[i] = max(f2[i],f2[j]+1);
	  	}
	  for(int i=1;i<=n;++i)
	  {
	  	int count = f1[i] + f2[i]-1;
	  	res = max(res,count);
	  }
	  cout<<n-res<<endl;
	return 0;
}