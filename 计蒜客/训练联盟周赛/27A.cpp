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

ll fib[75];

int main() {
    int t;
    scanf("%d",&t);
    // fib[0]=fib[1]=1;
    // rep(i,2,71){
    //     fib[i]=fib[i-1]+fib[i-2];
    // }
    // printf("%lld\n",fib[70]);
    int cas=0;
    while(t--){
        cas++;
        int x,y,n,m;
        scanf("%d%d%d%d",&x,&n,&y,&m);
        if(n==0||m==0){
            printf("Case %d: %lld\n",cas,1ll*(x+y));
            continue;
        }
        ll a=x,b=0;
        rep(i,1,n){
            if(a>b){
                b+=a;
            }
            else{
                a+=b;
            }
        }
        if(a<b)  swap(a,b);
        ll g=__gcd(a+y,b);
        printf("Case %d: %lld\n",cas,g);
    }
    return 0;
}