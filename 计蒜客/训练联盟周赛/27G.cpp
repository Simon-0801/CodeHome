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
    rep(cas,1,t){
        ll h,l;
        scanf("%lld%lld",&h,&l);
        ll tmp=log2(l);
        ll tsum=(1ll<<tmp),ans;
        if(tsum==l){
            ans=(h-tmp)*tsum+((1<<(tmp+1))-1);
        }
        else{
            tmp++;
            ll lft=((1<<tmp)-l);
            ans=0;
            ans+=((1<<tmp)-1)+l+(h-tmp)*l;
        }
        printf("Case %d: %lld\n",cas,ans);
    }
    return 0;
}