#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 50000 + 5;

vector<int> edge[maxn];
bool vis[maxn];
int st[maxn],en[maxn];
char str[10];
int cnt;

void dfs(int v){
    cnt++;
    st[v]=cnt;
    int len=edge[v].size();
    for(int i=0;i<len;i++){
        dfs(edge[v][i]);
    }
    en[v]=cnt;
}

struct node
{
    int l,r;
    int task;
    int tag;
}t[maxn*4];

void pushdown(int p){
    if(t[p].l==t[p].r)  return;
    if(t[p].tag!=-1){
        int lson=p*2,rson=p*2+1;
        t[lson].tag=t[p].tag;
        t[lson].task=t[p].tag;
        t[rson].tag=t[p].tag;
        t[rson].task=t[p].tag;
        t[p].tag=-1;
    }
}

void build(int p,int l,int r){
    t[p].l=l;
    t[p].r=r;
    t[p].tag=-1;
    t[p].task=-1;
    if(l==r)  return;
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}

void update(int p,int l,int r,int task){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].task=task;
        t[p].tag=task;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(r<=mid){
        update(p*2,l,r,task);
    }
    else if(l>mid){
        update(p*2+1,l,r,task);
    }
    else{
        update(p*2,l,mid,task);
        update(p*2+1,mid+1,r,task);
    }
}

int query(int p,int x){
    if(t[p].l==t[p].r){
        return t[p].task;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(x<=mid)  return query(p*2,x);
    else  return query(p*2+1,x);
}


int main() {
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        ++cas;
        printf("Case #%d:\n",cas);
        int n,m,u,v,root,x,y;
        scanf("%d",&n);
        cnt=0;
        memset(vis,false,sizeof vis);
        for(int i=1;i<=n;i++){
            edge[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&u,&v);
            edge[v].push_back(u);
            vis[u]=true;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                root=i;
                break;
            }
        }
        dfs(root);
        build(1,1,n);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%s",str);
            if(str[0]=='C'){
                scanf("%d",&x);
                printf("%d\n",query(1,st[x]));
            }
            else{
                scanf("%d%d",&x,&y);
                update(1,st[x],en[x],y);
            }
        }
    }
    return 0;
}