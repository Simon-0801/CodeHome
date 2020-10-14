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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 1000000 + 5;



int main() {
    double k,p,x;
    scanf("%lf%lf%lf", &k, &p, &x);
    double ans = INF;
    for (int i = 1; i <= maxn; ++i)
    {
        double day = (k * 1.0 / i);
        ans = min(ans, x * i + p * day);
    }
    printf("%.3f\n", ans);
    return 0;
}