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

int a[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int tmp=0,cnt=0;
    for(int i=1;i<=n;i++){
        tmp+=a[i];
        if(tmp>m){
            cnt++;
            tmp=a[i];
        }
    }
    if(tmp<=m)  cnt++;
    printf("%d\n",cnt);
    return 0;
}