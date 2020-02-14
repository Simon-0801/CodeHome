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

// int a[maxn];

int main() {
    int n,sum=0,a,mmax=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        sum+=a;
        mmax=max(mmax,a);
    }
    sum*=2;
    sum++;
    if(sum%n==0)  printf("%d\n",max(sum/n,mmax));
    else  printf("%d\n",max(mmax,sum/n+1));
    return 0;
}