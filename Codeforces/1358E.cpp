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
const int maxn = 500000 + 5;

ll a[maxn];
ll sum[maxn];
ll mn[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,(n+1)/2){
        scanf("%lld",a+i);
    }
    ll x;
    scanf("%lld",&x);
    rep(i,1,n){
        if(i<=(n+1)/2){
            sum[i]=sum[i-1]+a[i];
        }
        else{
            sum[i]=x+sum[i-1];
        }
    }
    ll tmp=0,mmn=0;
    rep(i,1,(n+1)/2){
        tmp+=(x-a[i]);
        mn[i]=min(tmp,mmn);
        mmn=min(tmp,mmn);
    }
    int ans=-1;
    rep(i,(n+1)/2,n){
        int id=n-i;
        if(sum[i]+mn[id]>0){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}