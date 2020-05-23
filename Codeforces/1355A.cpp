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
        ll a,k;
        scanf("%lld%lld",&a,&k);
        k--;
        while(k--){
            ll tmp=a;
            ll mx=-1,mn=10;
            while(tmp){
                mn=min(mn,tmp%10);
                mx=max(mx,tmp%10);
                tmp/=10;
            }
            if(mn==0)  break;
            a+=mn*mx;
        }
        printf("%lld\n",a);
    }
    return 0;
}