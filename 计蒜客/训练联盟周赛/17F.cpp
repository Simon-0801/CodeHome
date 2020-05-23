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

map<int,int> mp;
vector<PII> edge[maxn];

int fa[maxn],sum[maxn];
int n;

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

void dfs(int x,int fa){
    for(auto &nod:edge[x]){
        int v=nod.first;
        if(v==fa) continue;
        cout<<x<<' '<<v<<' '<<nod.second<<'\n';
        dfs(v,x);
    }
}


int main() {
    scanf("%d",&n);
    init();
    rep(i,1,n){
        int m,num;
        scanf("%d",&m);
        rep(j,1,m){
            scanf("%d",&num);
            if(mp[num]){
                int fu=find(i),fv=find(mp[num]);
                if(fu==fv)  continue;
                fa[fu]=fv;
                edge[i].push_back(make_pair(mp[num],num));
                edge[mp[num]].push_back(make_pair(i,num));
            }
            else{
                mp[num]=i;
            }
        }
    }
    int f=1;
    rep(i,1,n){
        if(find(1)!=find(i)){
            f=0;
            break;
        }
    }
    if(!f)  printf("impossible\n");
    else{
        dfs(1,0);
    }
    return 0;
}