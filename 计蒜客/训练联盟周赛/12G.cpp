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
const int maxn = 5000 + 5;

int a[maxn];
int ans=0;

void dfs(int l,int r){
    if(l==r){                       //剩一个人没过去
        ans+=a[l];
        return;
    }
    if(r-l==1){                     //剩两个人没过去
        ans+=max(a[l],a[r]);
        return;
    }
    if(r-l==2){                     //剩三个人没过去
        ans+=a[r]+a[l]+a[r-1];
        return;
    }
    if(2*a[l+1]>=a[l]+a[r-1]){      //分情况递归求解
        ans+=a[r]+a[l]+a[r-1]+a[l];
        dfs(l,r-2);
    }
    else{
        ans+=a[l+1]+a[l]+a[r]+a[l+1];
        dfs(l,r-2);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",a+i);
    }
    sort(a+1,a+n+1);                //先排序保证最快的是前两个
    dfs(1,n);
    printf("%d\n",ans);
    return 0;
}