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

int a[maxn];
PII b[maxn];
int tot=0;

void dfs(int l,int r){
    if(l>r)  return;
    int mid=(l+r)>>1;
    b[++tot]=PII(r-l+1,mid);
    dfs(l,mid-1);
    dfs(mid+1,r);
}

int cmp(PII a,PII b){
    if(a.first==b.first)  return a.second<b.second;
    return a.first>b.first;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        tot=0;
        dfs(1,n);
        sort(b+1,b+1+n,cmp);
        rep(i,1,n){
            a[b[i].second]=i;
        }
        rep(i,1,n){
            printf("%d ",a[i]);
        }
        puts("");
    }
    return 0;
}