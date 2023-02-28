#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int m,s,t,res;
int f[300030];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>m>>s>>t;
	  f[0] =0;
	  for(int i=1;i<=t;++i)
	  {
	  	if(m>=10)
	  	{
	  		f[i]=f[i-1]+60;
	  		m-=10;
	  	}
	  	else
	  	{
	  		f[i] = f[i-1];
	  		m+=4;
	  	}
	  }
	  for(int i=1;i<=t;++i)
	  {
	  	if(f[i]< f[i-1]+17) f[i] = f[i-1]+17;
	  	if(f[i] >=s)
	  	{
	  		cout<<"Yes"<<endl;
	  		cout<<i<<endl;
	  		return 0;
	  	}
	  	res = max(res,f[i]);
	  }
	  cout<<"No"<<endl;
	  cout<<res<<endl;
	return 0;
}