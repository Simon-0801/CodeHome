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

char str[105];
map<char,PII> mp;

int main() {
    int h,w;
    while(scanf("%d%d",&h,&w)&&h&&w){
        mp.clear();
        rep(i,1,h){
            scanf("%s",str+1);
            rep(j,1,w){
                if(str[j]=='_')  continue;
                mp[str[j]]=PII(i,j);
            }
        }
        scanf("%s",str+1);
        int len=strlen(str+1);
        PII pre=PII(1,1);
        int ans=0;
        rep(i,1,len){
            PII now=mp[str[i]];
            ans+=abs(pre.first-now.first)+abs(pre.second-now.second)+1;
            pre=now;
        }
        printf("%d\n",ans);
    }
    return 0;
}