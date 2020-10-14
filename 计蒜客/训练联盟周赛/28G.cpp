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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int a[30];
ll cnt;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ll k;
        cnt=0;
        scanf("%lld",&k);
        rep(i,1,7){
            scanf("%d",a+i);
            a[i+14]=a[i+7]=a[i];
            if(a[i]==1)  cnt++;
        }
        a[0]=0;
        rep(i,1,21)  a[i]+=a[i-1];
        ll times=k/cnt;
        ll lft=k%cnt,tt;
        ll tmp=1e18;
        if(times==0){
            rep(st,1,7){
                rep(i,st,21){
                    if(a[i]==a[st-1]+k){
                        tmp=min(tmp,1ll*(i-st+1));
                        break;
                    }
                }
            }
            printf("%lld\n",tmp);
            continue;
        }
        ll ans=(times-1)*7;
        k-=(times-1)*cnt;
        rep(st,1,7){
            rep(i,st,21){
                if(a[i]==a[st-1]+k){
                    tmp=min(tmp,1ll*(i-st+1));
                    break;
                }
            }
        }
        ans+=tmp;
        printf("%lld\n",ans);
    }
    return 0;
}