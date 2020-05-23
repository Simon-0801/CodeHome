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

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,tmp,mx=0;
        scanf("%d",&n);
        // mst(cnt,0);
        rep(i,1,n){
            scanf("%d",&tmp);
            cnt[tmp]++;
            mx=max(mx,tmp);
        }
        int lef=0,ans=0;
        rep(i,1,mx){
            tmp=(lef+cnt[i])/i;
            ans+=tmp;
            lef=(lef+cnt[i])-i*tmp;
            cnt[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}