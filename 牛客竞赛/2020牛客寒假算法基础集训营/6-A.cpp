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
const int maxn = 100000 + 5;

int a[maxn],b[maxn],sum[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int index=0;
    for(int i=n,j=n-k+1;i>=n-k+1,j<=n;i--,j++){
        sum[++index]=a[i]+b[j];
    }
    sort(sum+1,sum+index+1);
    printf("%d\n",sum[1]);
    return 0;
}