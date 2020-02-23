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
    ll a[5];
    double ans[5];
    scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
    sort(a+1,a+4);
    if(a[1]+a[2]<=a[3])  printf("wtnl\n");
    else{
        double p=0.5*(a[1]+a[2]+a[3]);
        ans[1]=p-a[1];
        ans[2]=p-a[2];
        ans[3]=p-a[3];
        sort(ans+1,ans+4);
        printf("Yes\n");
        for(int i=1;i<=3;i++){
            printf("%.2lf%c",ans[i],i==3?'\n':' ');
        }
    }
    return 0;
}