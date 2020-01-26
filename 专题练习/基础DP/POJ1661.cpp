#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;

int dp[maxn][2];

struct platform
{
    int xl,xr,h;
}p[maxn];

int cmp(platform a,platform b){
    return a.h<b.h;
}

int main() {
    int t,n,x,y,mx;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&y,&mx);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&p[i].xl,&p[i].xr,&p[i].h);
        }
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n+1;i++){
            dp[i][0]=dp[i][1]=INF;
        }
        p[n+1].h=y;
        p[n+1].xl=p[0].xr=x;
        for(int i=1;i<=n+1;i++){
            int lpos=-1,rpos=-1;
            for(int j=i-1;j>=1;j--){
                if(p[j].xl<=p[i].xl&&p[j].xr>=p[i].xl){
                    lpos=j;
                    break;
                }
            }
            for(int j=i-1;j>=0;j--){
                if(p[j].xl<=p[i].xr&&p[j].xr>=p[i].xr){
                    rpos=j;
                    break;
                }
            }
            if(lpos==-1&&p[i].h<=mx){
                dp[i][0]=p[i].h;
            }
            if(rpos==-1&&p[i].h<=mx){
                dp[i][1]=p[i].h;
            }
            if(lpos!=-1&&p[i].h-p[lpos].h<=mx){
                dp[i][0]=min(dp[lpos][0]+p[i].xl-p[lpos].xl,dp[lpos][1]+p[lpos].xr-p[i].xl)+p[i].h-p[lpos].h;
            }
            if(rpos!=-1&&p[i].h-p[rpos].h<=mx){
                dp[i][1]=min(dp[rpos][0]+p[i].xr-p[rpos].xl,dp[rpos][1]+p[rpos].xr-p[i].xr)+p[i].h-p[rpos].h;
            }
        }
        printf("%d\n",dp[n+1][0]);
    }
    return 0;
}