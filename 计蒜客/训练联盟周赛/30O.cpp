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
    ll n;
    scanf("%lld",&n);
    ll tmp=n*(n-1)/2;
    if(tmp%2){
        tmp/=2;
        tmp++;
    }
    else{
        tmp/=2;
    }
    ll t=1+4*(n*n-2*tmp-n);
    ll x=ceil((1.0+sqrt((double)t))/2.0);

    // if(x*(x-1)>=t){
    //     while(x*(x-1)>=t)  x--;
    //     x++;
    // }
    // else{
    //     while(x*(x-1)<t)  x++;
    // }
    if((n-1+x)*(n-x)<2*tmp)  printf("%lld\n",n-x+1);
    else  printf("%lld\n",n-x);
    return 0;
}