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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

ll n,ans=0x3f3f3f3f3f3f3f3f;

bool check(ll num){
    ll tmp=num,cnt4=0,cnt7=0;
    while(tmp){
        ll nn=tmp%10;
        tmp/=10;
        if(nn==4)  cnt4++;
        else  cnt7++;
    }
    return cnt4==cnt7;
}

void dfs(ll num){
    if(num>1e13)  return;
    if(num>=n&&check(num)){
        ans=min(ans,num);
    }
    ll tmp=num*10+4;
    dfs(tmp);
    tmp=num*10+7;
    dfs(tmp);
}

int main() {
    scanf("%I64d",&n);
    dfs(0);
    printf("%I64d\n",ans);
    return 0;
}