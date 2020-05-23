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
        ll a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(c<=d){
            if(a<=b){
                printf("%lld\n",b);
            }
            else{
                printf("-1\n");
            }
        }
        else{
            if(a<=b){
                printf("%lld\n",b);
                continue;
            }
            ll ans=b;
            ll tmp=a-b;
            ll tms=tmp/(c-d);
            if(tmp%(c-d)==0){
                ans+=tms*c;
            }
            else{
                ans+=(1+tms)*c;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}