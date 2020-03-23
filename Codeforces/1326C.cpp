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
const ll mod = 998244353;
const int maxn = 200000 + 5;

vector<int> v;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int tmp;
    rep(i,1,n){
        scanf("%d",&tmp);
        if(tmp<=n&&tmp>n-k){
            v.push_back(i);
        }
    }
    ll ans=1;
    int len=v.size();
    rep(i,1,len-1){
        ans=(1ll*ans*(v[i]-v[i-1]))%mod;
    }
    ll sum=1ll*(n-k+1+n)*k/2ll;
    printf("%lld %lld\n",sum,ans%mod);
    return 0;
}