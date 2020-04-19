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
const int maxn = 1000 + 5;

char str[maxn][15];

struct node{
    int from,to;
    int len;
} pp[maxn*maxn];
int tot;

vector<PII> ans;

bool comp(struct node a,struct node b){
    return a.len<b.len;
}

int f[maxn];
void init(int n){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    return;
}
int Find(int x){
    if(f[x]==x) return f[x];
    else{
        return f[x]=Find(f[x]);
    }
}
bool same(int x,int y){
    int f1=Find(x);
    int f2=Find(y);
    return f1==f2;
}
void Merge(int x,int y){
    int f1=Find(x);
    int f2=Find(y);
    if(f1!=f2)
    {
        f[f2]=f1;
    }
    return;
}

int solve(char a[],char b[]){
    int len=strlen(a),res=0;
    rep(i,0,len-1){
        if(a[i]!=b[i])  res++;
    }
    return res;
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%s",str[i]+1);
    }
    tot=0;
    rep(i,1,n){
        rep(j,i+1,n){
            int tmp=solve(str[i]+1,str[j]+1);
            pp[++tot].from=i;
            pp[tot].to=j;
            pp[tot].len=tmp;
            pp[++tot].from=j;
            pp[tot].to=i;
            pp[tot].len=tmp;
        }
    }
    sort(pp+1,pp+1+tot,comp);//排序 自定按边长短 从小到大排序
    init(n);
    int s=0,chang=0;
    for(int i=1;i<=tot;i++){
        if(s==n-1) break;//已经选了n-1条边跳出
        if(same(pp[i].from,pp[i].to)) continue;//两个点在一个集合中
        Merge(pp[i].from,pp[i].to);//合并两个点
        chang+=pp[i].len;//长度累加
        ans.push_back(PII(pp[i].from,pp[i].to));
        s+=1;//条数累加
    }
    printf("%d\n",chang);
    for(auto &nod:ans){
        printf("%d %d\n",nod.first-1,nod.second-1);
    }
    return 0;
}