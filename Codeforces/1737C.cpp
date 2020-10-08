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

char str[maxn];
map<int,int> mp;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str+1);
        int len=strlen(str+1);
        int cntp=0,cntm=0,mn=INF;
        ll ans=0;
        mp.clear();
        rep(i,1,len){
            if(str[i]=='-')  cntm++;
            else  cntp++;
            mn=min(mn,cntp-cntm);
            if(cntp-cntm<0){
                int tmp=cntm-cntp;
                tmp--;
                if(mp.count(tmp)==0){
                    mp[tmp]=i;
                }
            }
        }
        if(mn>=0){
            ans=len;
            printf("%lld\n",ans);
        }
        else{
            mn=-mn;
            ans=len;
            for(auto &x:mp){
                ans+=1ll*x.second;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}