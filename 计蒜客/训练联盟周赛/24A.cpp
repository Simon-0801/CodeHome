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

set<ll> st;

int main() {
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    rep(i,1,a){
        st.insert(b*c*i);
    }
    rep(i,1,b){
        st.insert(a*c*i);
    }
    rep(i,1,c){
        st.insert(b*a*i);
    }
    ll pre=0;
    printf("%d\n",st.size());
    for(auto &x:st){
        printf("%lld %lld %lld %lld\n",x-pre,(pre/(b*c)+1),(pre/(a*c)+1),(pre/(b*a)+1));
        pre=x;

    }
    return 0;
}