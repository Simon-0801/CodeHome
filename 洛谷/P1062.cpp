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

ll dfs(int n,int k){
    if(n==0)  return 0;
    if(n==1)  return 1;
    int j=0,sum=0;
    while(sum<n){
        sum+=(1<<j);
        j++;
    }
    j--;
    sum-=(1<<j);
    n-=sum;
    n--;
    return (ll)pow(k,j)+dfs(n,k);
}

int main() {
    int k,n;
    scanf("%d%d",&k,&n);
    ll ans=dfs(n,k);
    printf("%lld\n",ans);
    return 0;
}