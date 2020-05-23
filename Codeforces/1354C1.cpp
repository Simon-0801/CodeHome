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
#define PI 3.141592653589
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



int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n&1){
            double deg=1.0*PI/2.0/n;
            double ans=0.5/sin(deg);
            ans*=2.0;
            printf("%.9lf\n",ans);
        }
        else{
            double deg=1.0*PI/2.0/n;
            double ans=0.5/tan(deg);
            ans*=2.0;
            printf("%.9lf\n",ans);
        }
    }
    return 0;
}