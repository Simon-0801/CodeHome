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
const int maxn = 2000 + 5;

ll a[maxn];
VI st[maxn];
map<int,int> mp;

int bsearch(int id,int num){
    int sz=st[id].size();
    int l=0,r=sz-1,pos=-1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if(st[id][mid]<=num){
            l=mid+1;
        }
        else{
            r=mid-1;
            pos=mid;
        }
    }
    if(pos==-1){
        return -1;
    }
    else{
        return sz-pos;
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--)
    {
        // int n;
        // scanf("%d",&n);
        // rep(i,1,n){
        //     scanf("%lld",a+i);
        // }
        // ll ans=0;
        // rep(j,2,n-1){
        //     mpl.clear();
        //     mpr.clear();
        //     rep(i,1,j-1){
        //         int tmp=a[j]-a[i];
        //         if(!mpl[tmp]){
        //             mpl[tmp]=1;
        //         }
        //         else{
        //             mpl[tmp]++;
        //         }
        //     }
        //     rep(k,j+1,n){
        //         int tmp=a[k]-a[j];
        //         if(!mpr[tmp]){
        //             mpr[tmp]=1;
        //         }
        //         else{
        //             mpr[tmp]++;
        //         }
        //     }
        //     for(auto &nod:mpl){
        //         if(mpr[nod.first]){
        //             ans+=1ll*nod.second*mpr[nod.first];
        //         }
        //     }
        // }
        int n,tot=0;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",a+i);
        }
        mp.clear();
        ll ans=0;
        rep(j,1,n){
            rep(k,j+1,n){
                int tmp=2*a[j]-a[k];
                if(!mp.count(tmp))  continue;
                int num=mp[tmp];
                ans+=1ll*num;
            }
            mp[a[j]]++;
        }

        printf("%lld\n",ans);
    }
    
    return 0;
}