#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
typedef long long ll;
using namespace std;
int n,m;
int a[365];
int b[125];
int f[45][45][45][45];
int card[5];
	int main(){
	  ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	for(int i=1;i<=m;++i)card[b[i]]++;
	int fi = card[1];
	int se = card[2];
	int th = card[3];
	int fo = card[4];
	f[0][0][0][0] = a[1];
	for(int i=0;i<=fi;++i)
		for(int j =0;j<=se;++j)
			for(int k =0;k<=th;++k)
				for(int l =0;l<=fo;++l)
				{
					if(i==0&&j==0&&k==0&&l==0) continue;
					int current = 1+i+2*j+3*k+4*l;
					//int count =0;
					if(i>=1)f[i][j][k][l] = max(f[i][j][k][l],f[i-1][j][k][l]+a[current]);
					if(j>=1)f[i][j][k][l] = max(f[i][j][k][l],f[i][j-1][k][l]+a[current]);
					if(k>=1)f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k-1][l]+a[current]);
					if(l>=1)f[i][j][k][l] = max(f[i][j][k][l],f[i][j][k][l-1]+a[current]);
					//f[i][j][k][l]=max(f[i][j][k][l],count);
				}
	cout<<f[fi][se][th][fo];
	return 0;
}