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

ll a[maxn];
ll sub[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        ll ans=0,tmp;
        rep(i,1,n){
            scanf("%lld",a+i);
            if(i&1)  ans+=a[i];
        }
        tmp=ans;
        int tot=0;
        sub[0]=0;
        for(int i=1;i+1<=n;i+=2){
            sub[++tot]=a[i+1]-a[i];
            sub[tot]+=sub[tot-1];
        }
        ll mx=-1e18,mn=0;
        rep(i,1,tot){
            mx=max(sub[i]-mn,mx);
            mn=min(mn,sub[i]);
        }
        if(mx>0){
            tmp+=mx;
        }
        tot=0;
        for(int i=2;i+1<=n;i+=2){
            sub[++tot]=a[i]-a[i+1];
            sub[tot]+=sub[tot-1];
        }
        mx=-1e18,mn=0;
        rep(i,1,tot){
            mx=max(sub[i]-mn,mx);
            mn=min(mn,sub[i]);
        }
        if(mx<=0){
            ans=tmp;
        }
        else if(tmp<ans+mx){
            ans+=mx;
        }
        else{
            ans=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}