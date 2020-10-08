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
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a*b<=c){
            printf("1 -1\n");
        }
        else{
            if(a<c){
                printf("1 %lld\n",b);
            }
            else{
                printf("-1 %lld\n",b);
            }
        }
    }
    return 0;
}