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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 200000 + 5;

vector<int> G[maxn];
int time;
int in[maxn],out[maxn],num[maxn];

inline void dfs(int x, int fa) {
	in[x] = ++time; //进入的时间戳
	num[time] = x;  //生成新的线性结构
	for(int i = 0; i < G[x].size(); i++) {
		int cnt = G[x][i];
		if(cnt == fa) continue;
		dfs(cnt, x);
	}
	out[x] = time;  //出去的时间戳
}

int main() {
    int n,q,tmp,u,k;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        scanf("%d",&tmp);
        G[tmp].push_back(i);
    }
    time=0;
    dfs(1,-1);
    while(q--){
        scanf("%d%d",&u,&k);
        int nn=out[u]-in[u]+1;
        if(nn<k)  printf("-1\n");
        else printf("%d\n",num[in[u]+k-1]);
    }
    return 0;
}