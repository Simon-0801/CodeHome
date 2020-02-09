#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int t[maxn*4];
int fa[maxn],l[maxn],r[maxn];

void dfs(int p){
    if(t[p]==-1){
        return;
    }
    int lson=p*2,rson=p*2+1;
    if(p==1){
        fa[t[p]]=-1;
        l[t[p]]=t[lson];
        r[t[p]]=t[rson];
        fa[t[lson]]=t[p];
        fa[t[rson]]=t[p];
        dfs(lson);
        dfs(rson);
    }
    else{
        l[t[p]]=t[lson];
        r[t[p]]=t[rson];
        fa[t[lson]]=t[p];
        fa[t[rson]]=t[p];
        dfs(lson);
        dfs(rson);
    }
}

int main() {
    int n,sz=-1;
    scanf("%d",&n);
    memset(t,-1,sizeof t);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
        sz=max(sz,t[i]);
    }
    dfs(1);
    printf("The size of the tree is %d\nNode %d is the root node of the tree\n",sz,t[1]);
    for(int i=1;i<=sz;i++){
        printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",i,fa[i],l[i],r[i]);
    }
    return 0;
}