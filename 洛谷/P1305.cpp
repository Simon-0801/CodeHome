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
const int maxn = 30 + 5;

char str[10];

struct node
{
    char l,r;
}p[maxn];

map<char,int> pos;
map<char,int> vis;

void dfs(char root){
    if(root=='*')  return;
    printf("%c",root);
    int po=pos[root];
    dfs(p[po].l);
    dfs(p[po].r);
}

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%s",str+1);
        p[i].l=str[2];
        p[i].r=str[3];
        pos[str[1]]=i;
        if(str[2]!='*')  vis[str[2]]=1;
        if(str[3]!='*')  vis[str[3]]=1;
    }
    char root;
    for(auto &x:pos){
        if(!vis[x.first]){
            root=x.first;
            break;
        }
    }
    dfs(root);
    return 0;
}