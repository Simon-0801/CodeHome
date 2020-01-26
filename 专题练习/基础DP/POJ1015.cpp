#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200 + 2;
const int maxm = 20 + 2;
const int zero = 25;
const int VAL = 42;

struct candidate
{
    int sub;
    int sum;
}c[maxn];

struct node{
    int flag;
    int sum;
    int id;
    node *pre;
}dp[maxn][maxm][maxm*VAL+1];

void output(node *p) {
	if(p){//初始化后dp[0][0][0].Next=0;
		output(p->pre);
		if(p->id) {
			printf(" %d", p->id);
		}
	}
}

int main() {
    int n,m,cas=0;
    while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
        cas++;
        int x,y;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&x,&y);
            c[i].sub=x-y+zero;//把负号去掉
            c[i].sum=x+y;
        }
        memset(dp,0,sizeof dp);
        dp[0][0][0].flag=1;
        for(int i=1;i<=n;i++){
            dp[i][0][0].flag=1;
            for(int j=1;j<=m;j++){
                int tmax=j*VAL,tsub=c[i].sub;
                for(int k=0;k<=tmax;k++){
                    dp[i][j][k]=dp[i-1][j][k];
                    if(k<tsub)  continue;
                    node &pr=dp[i-1][j-1][k-tsub],&now=dp[i][j][k];
                    if(pr.flag&&pr.sum+c[i].sum>now.sum){
                        now.sum=pr.sum+c[i].sum;
                        now.flag=1;
                        now.id=i;
                        now.pre=&pr;
                    }
                }
            }
        }
        int mid=m*zero;
        int anssub,anssum=-1;
        node *path;
        for(int i=0;i<=mid;i++){
            int l=mid-i;
            int r=mid+i;
            if(dp[n][m][l].flag||dp[n][m][r].flag){
                anssub=(dp[n][m][l].sum>dp[n][m][r].sum?-i:i);
                anssum=(dp[n][m][l].sum>dp[n][m][r].sum?dp[n][m][l].sum:dp[n][m][r].sum);
                path=(dp[n][m][l].sum>dp[n][m][r].sum?&dp[n][m][l]:&dp[n][m][r]);
            }
            if(~anssum)break;
        }
        x=(anssub+anssum)/2,y=anssum-x;
        printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",cas,x,y);
        output(path);
		puts("\n");
    }
    return 0;
}