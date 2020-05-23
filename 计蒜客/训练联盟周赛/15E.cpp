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

ll fac[maxn];

void init(){
    mst(fac,-1);
    fac[0]=1;
    rep(i,1,10000){
        fac[i]=fac[i-1]*i;
        if(fac[i]>1e18){
            fac[i]=-1;
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    init();
    double ans=0;
    rep(i,0,n){
        if(fac[i]==-1)  break;
        ans+=1.0/fac[i];
    }
    printf("%.16lf",ans);
    return 0;
}