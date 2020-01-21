#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;

struct node
{
    int x,y;
    int h;
};

node b[100];
int dp[100];

int cmp(node a,node b){
    return a.x*a.y<b.x*b.y;
}

int main() {
    int n,cas=0;
    while(scanf("%d",&n)&&n){
        ++cas;
        int cnt=0,x,y,z;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            node tmp;
            tmp.x=max(x,y);
            tmp.y=min(x,y);
            tmp.h=z;
            b[++cnt]=tmp;
            tmp.x=max(x,z);
            tmp.y=min(x,z);
            tmp.h=y;
            b[++cnt]=tmp;
            tmp.x=max(y,z);
            tmp.y=min(y,z);
            tmp.h=x;
            b[++cnt]=tmp;
        }
        sort(b+1,b+cnt+1,cmp);
        // dp[1]=b[1].h;
        int ans=b[1].h;
        for(int i=2;i<=cnt;i++){
            int tmax=0;
            for(int j=1;j<i;j++){
                if(b[j].x<b[i].x&&b[j].y<b[i].y){
                    tmax=max(tmax,b[j].h);
                }
            }
            b[i].h+=tmax;
            ans=max(ans,b[i].h);
        }
        printf("Case %d: maximum height = %d\n",cas,ans);
    }
    return 0;
}