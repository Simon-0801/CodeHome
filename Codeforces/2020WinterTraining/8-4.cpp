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

char str[maxn];

int main() {
    ll n,q,u;
    scanf("%I64d%I64d",&n,&q);
    while(q--){
        scanf("%I64d",&u);
        scanf("%s",str+1);
        int len=strlen(str+1);
        ll ans=u,root=(n+1)/2;
        for(int i=1;i<=len;i++){
            if(str[i]=='L'){
                ll tmp=(ans&(-ans));
                if(tmp==1)  continue;
                ans-=tmp;
                tmp>>=1;
                ans+=tmp;
            }
            else if(str[i]=='R'){
                ll tmp=(ans&(-ans));
                if(tmp==1)  continue;
                tmp>>=1;
                ans+=tmp;
            }
            else{
                if(ans==root)  continue;
                ll tmp=(ans&(-ans));
                ans-=tmp;
                tmp<<=1;
                ans=(ans|tmp);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}