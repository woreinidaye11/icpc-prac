#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
const int mod =1000000007;
int n,m,k;
string a,b;
int f[2][210][210][2];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	  cin>>n>>m>>k;
	  cin>>a>>b;
	  a = 'p'+a;
	  b = 'o'+b;
	  f[0][0][0][0] =1;
	  f[1][0][0][0] =1;
	  for(int i=1;i<=n;i++)
	  	for(int j=1;j<=m;++j)
	  		for(int l =1;l<=k;++l)
	  		{
	  			if(a[i] !=b[j])
	  			{
	  				f[i%2][j][l][0] = (f[(i-1)%2][j][l][0]+f[(i-1)%2][j][l][1])%mod;
	  				f[i%2][j][l][1] = 0;
	  			}
	  			else
	  			{
	  				f[i%2][j][l][0] = (f[(i-1)%2][j][l][0]+f[(i-1)%2][j][l][1])%mod;
	  				f[i%2][j][l][1] = ((f[(i-1)%2][j-1][l][1]+f[(i-1)%2][j-1][l-1][1])%mod+f[(i-1)%2][j-1][l-1][0])%mod;
	  			}
	  		}
	  	cout<<(f[n%2][m][k][0]+f[n%2][m][k][1])%mod<<endl;
	return 0;
}
