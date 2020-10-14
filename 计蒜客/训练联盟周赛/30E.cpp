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



int main() {
    int n,x;
    double v;
    scanf("%d%d%lf",&n,&x,&v);
    int l,r;
    double vi;
    double sum=0.0;
    int suml=0;
    rep(i,1,n){
        scanf("%d%d%lf",&l,&r,&vi);
        sum=sum+1.0*(r-l)*vi;
        suml=suml+(r-l);
    }
    double vy=-sum/(0.0+x);
    if(v*v-vy*vy<=0){
        printf("Too hard\n");
        return 0;
    }
    double vx=sqrt(v*v-vy*vy);
    if(1.0*x/vx>2.0*x/v){
        printf("Too hard\n");
        return 0;
    }
    printf("%.3lf\n",1.0*x/vx);
    return 0;
}