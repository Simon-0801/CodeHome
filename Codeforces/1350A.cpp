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



int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        if(n&1){
            int f=0;
            for(ll i=3;i*i<=n;i+=2){
                if(n%i==0){
                    n+=i;
                    f=1;
                    break;
                }
            }
            if(!f)  n+=n;
            n+=(k-1)*2;
            printf("%lld\n",n);
        }
        else{
            n+=k*2;
            printf("%lld\n",n);
        }
    }
    return 0;
}