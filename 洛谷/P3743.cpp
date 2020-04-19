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
#define eps 1e-6
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int a[maxn],b[maxn];
int n,p;

bool check(double num){
    double tmp=0;
    rep(i,1,n){
        if(b[i]-a[i]*num<0){
            tmp+=(a[i]*num-b[i])/(1.0*p);
        }
    }
    if(tmp<=num)  return true;
    else  return false;
}

int main() {
    scanf("%d%d",&n,&p);
    ll sum=0,sumb=0;
    rep(i,1,n){
        scanf("%d%d",a+i,b+i);
        sum+=1ll*a[i];
        sumb+=1ll*b[i];
    }
    if(sum<=p){
        printf("-1\n");
        return 0;
    }
    double mx=sumb/(1.0*(sum-p));
    mx+=1.0;
    double l=0,r=mx,ans;
    while(abs(l-r)>eps){
        double mid=(l+r)/2.0;
        if(check(mid)){
            ans=mid;
            l=mid+eps;
        }
        else{
            r=mid-eps;
        }
    }
    printf("%.6lf\n",ans);
    return 0;
}