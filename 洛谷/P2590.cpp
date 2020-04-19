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
const int maxn = 30000 + 5;

vector<int> edge[maxn];

int son[maxn],siz[maxn],dep[maxn],fa[maxn],top[maxn],dfn[maxn],rnk[maxn];
int cnt;

void dfs1(int x) {
    son[x] = -1;
    siz[x] = 1;
    for(auto &nod:edge[x]){
        if (!dep[nod]) {
            dep[nod] = dep[x] + 1;
            fa[nod] = x;
            dfs1(nod);
            siz[x] += siz[nod];
            if (son[x] == -1 || siz[nod] > siz[son[x]]) son[x] = nod;
        }
    }
}

void dfs2(int x,int t) {
    top[x] = t;
    cnt++;
    dfn[x] = cnt;
    rnk[cnt] = x;
    if (son[x] == -1) return;
    dfs2(son[x], t);  // 优先对重儿子进行 DFS，可以保证同一条重链上的点 DFS 序连续
    for(auto &nod:edge[x]){
        if (nod != son[x] && nod != fa[x]) dfs2(nod, nod);
    }
}

int w[maxn];

struct segtree{
	int l,r;
	ll sum;		//sum维护该区间内整数和 
    ll mx;
};
 
segtree t[maxn*4];
 
void pushup(int p){//区间合并，向上拓展 
	t[p].sum=t[2*p].sum+t[2*p+1].sum;
    t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
}
 
void build(int p,int l,int r){//建树 
	int mid=(l+r)/2;
	t[p].l=l;
	t[p].r=r;
	if(l==r){
		t[p].sum=t[p].mx=w[rnk[l]];
		return;
	}
	build(p*2,l,mid);
	build(2*p+1,mid+1,r);
	pushup(p);
}
 
ll stquerysum(int p,int L,int R){
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].sum;
	}
	int lson=p*2;
	int rson=p*2+1;
	ll tsum=0;
	int mid=(t[p].l+t[p].r)/2; 
	if(L<=mid){		//如果左侧还有区间 
		tsum+=stquerysum(lson,L,R);
	}
	if(R>mid){ 		//如果右侧还有区间
		tsum+=stquerysum(rson,L,R);
	} 
	return tsum;
} 
 
ll stquerymax(int p,int L,int R){
	if(L<=t[p].l&&R>=t[p].r){
		return t[p].mx;
	}
	int lson=p*2;
	int rson=p*2+1;
	ll tmax=-INF;
	int mid=(t[p].l+t[p].r)/2; 
	if(L<=mid){		//如果左侧还有区间 
		tmax=max(tmax,stquerymax(lson,L,R));
	}
	if(R>mid){ 		//如果右侧还有区间
		tmax=max(tmax,stquerymax(rson,L,R));
	} 
	return tmax;
}  
 
void stupdate(int p,int pos,ll num){
	int lson=p*2,rson=p*2+1;
	if(t[p].l==t[p].r){
		t[p].sum=num;		
		t[p].mx=num;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(pos<=mid){
		stupdate(lson,pos,num);
	} 
	if(pos>mid){
		stupdate(rson,pos,num);
	}
	pushup(p);//子节点更新返回后要更新父节点 
}


//树链剖分维护树上路径信息
ll querysum(int x,int y){
    ll res=0;
    int tpx=top[x],tpy=top[y];
    while(tpx!=tpy){
        if(dep[tpx]>=dep[tpy]){
            res+=stquerysum(1,dfn[tpx],dfn[x]);
            x=fa[tpx];
        }
        else{
            res+=stquerysum(1,dfn[tpy],dfn[y]);
            y=fa[tpy];
        }
        tpx=top[x];
        tpy=top[y];
    }
    if(dfn[x]<dfn[y]){
        res+=stquerysum(1,dfn[x],dfn[y]);
    }
    else{
        res+=stquerysum(1,dfn[y],dfn[x]);
    }
    return res;
}

ll querymax(int x,int y){
    ll res=-INF;
    int tpx=top[x],tpy=top[y];
    while(tpx!=tpy){
        if(dep[tpx]>=dep[tpy]){
            res=max(res,stquerymax(1,dfn[tpx],dfn[x]));
            x=fa[tpx];
        }
        else{
            res=max(res,stquerymax(1,dfn[tpy],dfn[y]));
            y=fa[tpy];
        }
        tpx=top[x];
        tpy=top[y];
    }
    if(dfn[x]<dfn[y]){
        res=max(res,stquerymax(1,dfn[x],dfn[y]));
    }
    else{
        res=max(res,stquerymax(1,dfn[y],dfn[x]));
    }
    return res;
}

char op[50];

int main() {
    int n,u,v,q,num;
    scanf("%d",&n);
    rep(i,1,n-1){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    rep(i,1,n)  scanf("%d",w+i);
    dep[1]=1;
    dfs1(1);
    dfs2(1,1);
    scanf("%d",&q);
    build(1,1,n);
    while(q--){
        scanf("%s",op);
        if(op[0]=='C'){
            scanf("%d%d",&u,&num);
            stupdate(1,dfn[u],num);
        }
        else{
            if(op[1]=='M'){
                scanf("%d%d",&u,&v);
                ll res=querymax(u,v);
                printf("%lld\n",res);
            }
            else{
                scanf("%d%d",&u,&v);
                ll res=querysum(u,v);
                printf("%lld\n",res);
            }
        }
    }
    return 0;
}