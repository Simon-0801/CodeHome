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
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ansh,ansm;
    a=a*60+b;
    c=c*60+d;
    ansh=c-a;
    ansm=ansh%60;
    ansh/=60;
    printf("%d %d\n",ansh,ansm);
    return 0;
}