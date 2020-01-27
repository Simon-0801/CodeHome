#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

struct node{
    int st,en;
    int pd;
}p[maxn];

int cmp(node a,node b){
    return a.en<b.en;
}

int dp[maxn];

int main() {
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p[i].st,&p[i].en,&p[i].pd);
        p[i].en+=r;
    }
    sort(p+1,p+m+1,cmp);
    p[0].st=p[0].en=0;
    p[0].pd=0;
    memset(dp,0,sizeof dp);
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){
            if(p[j].en<=p[i].st){
                dp[i]=max(dp[j]+p[i].pd,dp[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}