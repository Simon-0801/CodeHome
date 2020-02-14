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
const double Pi=3.1415926;


int main() {
    int n,r;
    scanf("%d%d",&n,&r);
    int i,j;
    scanf("%d%d",&i,&j);
    int st=min(i,j),en=max(i,j);
    int tmp=min(en-st,st+n-en);
    double ans=2.0*tmp*r*sin(Pi/(double)n);
    printf("%.10lf\n",ans);
    return 0;
}