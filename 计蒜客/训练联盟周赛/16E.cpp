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
const ll mod = 11092019;
const int maxn = 100000 + 5;

char str[maxn];
int cnt[30];

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    rep(i,1,len){
        cnt[str[i]-'a'+1]++;
    }
    ll ans=1;
    rep(i,1,26){
        ans=(ans*(cnt[i]+1))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}