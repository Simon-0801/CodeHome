#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int n,m,k;
int vis[maxn],cnt[maxn];

void primes(int n){
    memset(vis,0,sizeof vis);
    for(int i=2;i<=n;i++){
        if(vis[i])  continue;
        for(int j=i;j<=n/i;j++)  vis[i*j]=1;
    }
}

int ret(int x)
{
	int ans = 0;
	if(x == 1) return 0;
	for(int i = 1; i*i<=x; i++)
	{
		if(x % i == 0)
		{
			if(vis[i])  ans++;
			if(i != x/i&&vis[x/i]) ans++;
		}
	}
	return ans;
}

int main() {
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof cnt);
    primes(n);
    for(int i=1;i<=n;i++){
        cnt[ret(i)]++;
    }
    while(m--){
        scanf("%d",&k);
        printf("%d\n",cnt[k]);
    }
    return 0;
}