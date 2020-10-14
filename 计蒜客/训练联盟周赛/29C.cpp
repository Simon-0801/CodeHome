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
    ll num;
    while(scanf("%lld",&num)&&num){
        ll st,len=0;
        num*=2;
        for(ll i=1;i*i<=num;i++){
            if(num%i==0){
                ll x=i;
                ll y=num/i;
                ll a;
                if((x+y-1)%2==0){
                    a=x-(x+y-1)/2;
                    if(a>=1){
                        if(y>len){
                            st=a;
                            len=y;
                        }
                    }
                }
                x=num/i;
                y=i;
                if((x+y-1)%2==0){
                    a=x-(x+y-1)/2;
                    if(a>=1){
                        if(y>len){
                            st=a;
                            len=y;
                        }
                    }
                }
            }
        }
        printf("%lld %lld\n",st,len);
    }
    return 0;
}