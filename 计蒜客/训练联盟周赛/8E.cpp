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
#define eps 1e-9
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;



int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        int w,b,d,s;
        scanf("%d%d%d%d",&w,&b,&d,&s);
        int t;
        scanf("%d",&t);
        int ans=0;
        double x,y;
        while(t--){
            scanf("%lf%lf",&x,&y);
            double len=x*x+y*y;
            double angle=atan2(y,x);
            if(len<=b*b){
                ans+=50;
                continue;
            }
            if(angle<0)  angle+=2*M_PI;
            int pt=(int)((w*angle)/(2*M_PI)+eps);
            pt++;
            if(len<=d*d){
                ans+=2*pt;
            }
            else if(len<=s*s){
                ans+=pt;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}