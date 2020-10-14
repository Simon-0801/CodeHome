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
const int maxn = 100000 + 5;

double a[10];

int main() {
    double sum=0.0;
    rep(i,1,6){
        scanf("%lf",a+i);
        sum+=1.0*a[i]*i;
    }
    double ans=INF,tmp;
    rep(i,1,6){
        tmp=3.5-(sum-1.0*a[i]*i);
        tmp/=a[i];
        ans=min(ans,abs(tmp-i));
    }
    printf("%.3lf\n",ans);
    return 0;
}