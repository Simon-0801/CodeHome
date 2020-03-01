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

int n,k,cnt=0;

void dfs(int last,int presum,int index){
    if(index>k){
        if(presum==n)  cnt++;
        return;
    }
    for(int i=last;i*(k-index+1)<=n-presum;i++){
        dfs(i,presum+i,index+1);
    }
}

int main() {
    scanf("%d%d",&n,&k);
    dfs(1,0,1);
    printf("%d\n",cnt);
    return 0;
}