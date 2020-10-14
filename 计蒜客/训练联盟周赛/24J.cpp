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

const int EARTH_RADIUS=6371009;
const double pi=3.1415926535898;
 
double rad(double d)
{
    return d * pi /180.0;
}
ll RealDistance(double lat1,double lng1,double lat2,double lng2)//lat1第一个点纬度,lng1第一个点经度,lat2第二个点纬度,lng2第二个点经度
{
	
	double a;
   	double b;
   	double radLat1 = rad(lat1);
   double radLat2 = rad(lat2);
   a = radLat1 - radLat2;
   b = rad(lng1) - rad(lng2);
   double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
   double x=2.0*EARTH_RADIUS*EARTH_RADIUS*(1.0-cos(s));
   x=sqrt(x);
    s = s * EARTH_RADIUS;
    double dif=fabs(x-s);
    ll res=(ll)(dif+0.5);
    // s = s * 1000;
    
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    double a,b,c,d;
    rep(i,1,n){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        printf("%lld\n",RealDistance(a,b,c,d));
    }
    return 0;
}