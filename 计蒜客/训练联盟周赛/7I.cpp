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
const int maxn = 200000 + 5;

int fa[maxn],sum[maxn];
int edge[maxn];
int num[maxn];
int n,m;
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

int main() {
    scanf("%d%d",&n,&m);
    int u,v;
    init();
    rep(i,1,m){
        scanf("%d%d",&u,&v);
        merge(u,v);
        edge[u]++;
        edge[v]++;
    }
    int f=0;
    int root=find(1);
    if(sum[root]==n){
        int cnt=0;
        rep(i,1,n){
            if(edge[i]%2){
                cnt++;
            }
        }
        if(cnt==0||cnt==2)  printf("YES\n");
        else{
            printf("NO\n%d\n",cnt/2);
        }
    }
    else{
        mst(num,-1);
        mp.clear();
        int tot=0;
        rep(i,1,n){
            int ff=find(i);
            if(ff==i)  continue;
            if(!mp[ff]){
                tot++;
                num[tot]=0;
                if(edge[i]%2)  num[tot]++;
            }
            else{
                if(edge[i]%2)  num[mp[ff]]++;
            }
        }
        int ans=0;
        rep(i,1,tot){
            if(num[i]==0||num[i]==2)  ans++;
            else  ans+=num[i]/2;
        }
        printf("NO\n%d\n",ans);
    }
    return 0;
}