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

vector<ll> ans;

void solve(ll num){
    if(num==1){
        ans.push_back(num);
        return;
    }
    if(num&1){
        ll mid=((num+1)>>1);
        ans.push_back(mid);
        solve(mid-1);
    }
    else{
        ll mid=(num>>1);
        ans.push_back(mid);
        solve(mid);
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        ll k;
        scanf("%lld",&k);
        ans.clear();
        solve(k);
        ll sz=ans.size();
        printf("%lld\n",sz);
        rep(i,0,sz-1){
            printf("%lld%c",ans[i],i==sz-1?'\n':' ');
        }
    }
    return 0;
}