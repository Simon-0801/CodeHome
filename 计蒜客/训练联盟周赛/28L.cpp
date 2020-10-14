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

int a[maxn];
int vis[maxn];
ll num[maxn],mx[maxn];
int tot;

int main() {
    int n,k,tmp;
    ll b;
    tot=0;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%d",a+i);
        vis[a[i]]=1;
    }
    rep(i,1,n){
        scanf("%lld",&b);
        tmp=a[i];
        if(mx[tmp]==0){
            mx[tmp]=b;
        }
        else{
            if(mx[tmp]>b){
                num[++tot]=b;
            }
            else{
                num[++tot]=mx[tmp];
                mx[tmp]=b;
            }
        }
    }
    int lft=0;
    rep(i,1,k){
        if(!vis[i])  lft++;
    }
    sort(num+1,num+tot+1);
    ll ans=0;
    rep(i,1,lft){
        ans+=num[i];
    }
    printf("%lld\n",ans);
    return 0;
}