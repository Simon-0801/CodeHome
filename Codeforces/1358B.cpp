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
const int maxn = 200000 + 5;

int cnt[maxn];
map<int,int> mp;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,tmp,mx=-1;
        scanf("%d",&n);
        // mst(cnt,0);
        mp.clear();
        rep(i,1,n){
            scanf("%d",&tmp);
            mp[tmp]++;
            mx=max(mx,tmp);
        }
        int sum=0;
        for(auto &nod:mp){
            sum+=nod.second;
            nod.second=sum;
        }
        int ans=0;
        for(auto &nod:mp){
            if(nod.second>=nod.first){
                ans=max(ans,nod.second);
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}