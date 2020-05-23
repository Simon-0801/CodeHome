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
const int maxn = 1000000 + 5;

int main() {
    ll n,m;
    scanf("%lld%lld",&n,&m);
    n--;
    ll sum=2*(m-n);
    if(n==0)  sum--;
    // rep(i,2,(ll)(sqrt(n-1))){
    //     ll tmp=(n-1)%i;
    //     ll num=(n-1-tmp)/i;
    //     sum1=sum1+Bignum(2ll*(num-i)+1);
    //     // sum1+=2ll*(num-i);
    //     // if(i*i>=1&&i*i<=n-1)  sum1--;
    // }
    // Bignum sum2(2*m-1);
    rep(i,2,(ll)sqrt(m)){
        ll tmp=(n)%i;
        ll num1=(n-tmp)/i;
        tmp=(m)%i;
        ll num2=(m-tmp)/i;
        ll sum1=2ll*(num1-(i-2)-1);
        sum1--;
        ll sum2=2ll*(num2-(i-2)-1);
        sum2--;
        if(sum1<0)  sum1=0;
        sum+=(sum2-sum1);
        // if(i*i>=1&&i*i<=m)  sum2--;
    }
    // sum2=sum2-sum1;
    // sum2.print();
    printf("%lld\n",sum);
    return 0;
}