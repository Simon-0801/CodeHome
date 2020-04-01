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
const int maxn = 1000000 + 5;

ll num[maxn];
int cnt[maxn*10];

int main() {
    int n,p;
    scanf("%d",&n);
    rep(cas,1,n){
        scanf("%d",&p);
        mst(cnt,0);
        ll mx=-1,ans=0;
        rep(i,1,p){
            scanf("%lld",num+i);
            cnt[num[i]]++;
            mx=max(mx,num[i]);
        }
        if(cnt[0]){
            ans+=1ll*(p-cnt[0])*cnt[0];
        }
        if(cnt[1]){
            ans+=1ll*(p-cnt[1]-cnt[0])*cnt[1];
        }
        rep(i,2,mx/2){
            if(cnt[i]){
                for(int k=i+i;k<=mx;k+=i){
                    if(cnt[k]){
                        ans+=1ll*cnt[i]*cnt[k];
                    }
                }
            }
        }
        printf("Test case #%d: %lld\n\n",cas,ans);
    }
    return 0;
}