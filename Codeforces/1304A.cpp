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



int main() {
    int t;
    ll x,y,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b);
        ll tmp=y-x;
        if(tmp%(a+b)==0)  printf("%I64d\n",tmp/(a+b));
        else  printf("-1\n");
    }
    return 0;
}