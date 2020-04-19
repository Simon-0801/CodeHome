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

ll v[maxn],t[maxn];
ll sum[maxn];
ll times[maxn],lef[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld",v+i);
    }
    rep(i,1,n){
        scanf("%lld",t+i);
    }
    sum[0]=0;
    rep(i,1,n){
        sum[i]=sum[i-1]+t[i];
    }
    rep(i,1,n){
        ll tmp=sum[i-1]+v[i];
        auto it=lower_bound(sum,sum+n+1,tmp);
        if(it==sum+n+1){
            times[n+1]--;
            times[i]++;
        }
        else{
            ll f=*it;
            int pos=it-sum;
            if(tmp==f){
                times[pos+1]--;
                times[i]++;
            }
            else{
                lef[pos]+=tmp-sum[pos-1];
                times[pos]--;
                times[i]++;
            }
        }
    }
    times[0]=0;
    rep(i,1,n){
        times[i]=times[i-1]+times[i];
    }
    rep(i,1,n){
        ll ans=times[i]*t[i]+lef[i];
        printf("%lld%c",ans,i==n?'\n':' ');
    }
    return 0;
}