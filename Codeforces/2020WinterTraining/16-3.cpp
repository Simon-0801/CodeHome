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
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int fa[maxn],sum[maxn];
int n,k;
map<int,int> mp;

int find(int x){
	if(fa[x]==x)  return x;
	int root=find(fa[x]);
	sum[x]+=sum[fa[x]];	//路径压缩过程中，组内白点个数的更新 
	return fa[x]=root;
}
 
void merge(int a,int b){//两组合并
	int ffa=find(a),ffb=find(b);
    if(ffa==ffb)  return;
	fa[ffb]=ffa;
	sum[ffa]+=sum[ffb];
} 
 
void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
        sum[i]=1;//初始化每个白点自己成为一组
	}
}

ll qpow(ll num,ll p){
    ll res=1;
    while(p){
        if(p&1)  res=(res*num)%mod;
        num=(num*num)%mod;
        p>>=1;
    }
    return res%mod;
}

int main() {
    scanf("%d%d",&n,&k);
    int u,v,x;
    init();
    rep(i,1,n-1){
        scanf("%d%d%d",&u,&v,&x);
        if(x==0)  merge(u,v);
    }
    ll res=0;
    rep(i,1,n){
        int id=find(i);
        if(mp[id])  continue;
        mp[id]=1;
        res=(res+qpow(sum[id],k))%mod;
    }
    res=(qpow(n,k)-res+mod)%mod;
    printf("%lld\n",res);
    return 0;
}