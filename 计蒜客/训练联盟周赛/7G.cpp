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
const int maxn = 200000 + 5;

char str[maxn];
int p[maxn];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    ll ans=0;
    int pre=-1;
    rep(i,1,n){
        if(str[i]=='0'){
            p[i]=pre;
        }
        else{
            p[i]=i;
            pre=i;
        }
    }
    rep(i,1,n){
        if(p[i]==-1)  continue;
        if(p[i]==i){
            ll tmp=1ll*(1+i)*i/2;
            ans=(ans+i*tmp)%mod;
        }
        else{
            ll tmp=1ll*(i-p[i]+1+i)*(i-(i-p[i]+1)+1)/2;
            ans=(ans+p[i]*tmp)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}