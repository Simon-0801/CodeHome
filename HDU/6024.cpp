#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f 

using namespace std;

const int maxn=3005;

struct node{
	ll x;
	ll c;
};

int cmp(node a,node b){
	return a.x<b.x;
}

node nod[maxn];
ll dp[maxn][2];
ll sum[maxn][maxn];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&nod[i].x,&nod[i].c);
		}
		sort(nod+1,nod+n+1,cmp);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		//Ô¤´¦Àí 
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum[i][j]=sum[i][j-1]+nod[j].x-nod[i].x;
			}
		}
		//dp
		for(int i=1;i<=n;i++){
			for(int j=0;j<2;j++){
				dp[i][j]=INF;
			}
		}
		dp[1][1]=nod[1].c;
		for(int i=2;i<=n;i++){
			dp[i][1]=min(dp[i-1][0]+nod[i].c,dp[i-1][1]+nod[i].c);
			dp[i][0]=dp[1][1]+sum[1][i];
			for(int j=2;j<i;j++){
				dp[i][0]=min(dp[i][0],dp[j][1]+sum[j][i]);
			}
		}
		printf("%lld\n",min(dp[n][0],dp[n][1]));
	}
	return 0;
}
