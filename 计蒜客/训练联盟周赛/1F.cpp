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



int main() {
    ll n;
    scanf("%lld",&n);
    ll ansa,ansb;
    int flag=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ll a=n/i;
            ll b=i;
            if(a>b)  swap(a,b);
            if((a+b)%2==0&&(b-a)%2==0){
                flag=1;
                ansa=a;
                ansb=b;
            }
        }
    }
    if(flag){
        printf("%lld %lld\n",(ansa+ansb)/2,(ansb-ansa)/2);
    }
    else{
        printf("impossible\n");
    }
    return 0;
}