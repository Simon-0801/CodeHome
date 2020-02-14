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

int num[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  scanf("%d",&num[i]);
    int flag=0,tmp=num[9],cnt=0;
    for(int i=1;i<=n;i++){
        if(i==9)  continue;
        if(num[i]>tmp)  cnt++;
    }
    if(cnt<=2||5*tmp>=4*m)  printf("Yes\n");
    else printf("No\n");
    return 0;
}