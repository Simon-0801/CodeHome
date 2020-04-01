#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int l[55];

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        printf("CD #%d:\n",cas);
        int t,k,sum=0;
        scanf("%d%d",&t,&k);
        rep(i,1,t){
            scanf("%d",l+i);
            sum+=l[i];
        }
        int fav=l[k];
        int d,s;
        scanf("%d",&d);
        rep(day,1,d){
            scanf("%d",&s);
            int ans=0,pre=0,tmp;
            rep(i,1,s){
                if(i&1){
                    scanf("%d",&tmp);
                    ans+=tmp;
                    pre=tmp%fav;
                }
                else{
                    scanf("%d",&tmp);
                    if(pre==0){
                        int times=tmp/sum;
                        ans+=times*fav;
                        int lef=tmp%sum;
                        if(lef>=(sum-fav)){
                            ans+=lef-(sum-fav);
                        }
                        continue;
                    }
                    if(tmp<=(fav-pre)){
                        ans+=tmp;
                    }
                    else{
                        ans+=(fav-pre);
                        tmp-=(fav-pre);
                        int times=tmp/sum;
                        ans+=times*fav;
                        int lef=tmp%sum;
                        if(lef>=(sum-fav)){
                            ans+=lef-(sum-fav);
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}