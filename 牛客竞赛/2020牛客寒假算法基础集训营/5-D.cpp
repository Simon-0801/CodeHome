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
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        double ans=0;
        double ta=a,tb=b;
        while(1){
            double nxta;
            if(ta<0)  nxta=-pow(-ta,1.0/3.0);
            else nxta=pow(ta,1.0/3.0);
            if(abs(nxta-tb)+1.0<abs(ta-tb)){
                ans+=1.0;
                ta=nxta;
            }
            else{
                ans+=abs(ta-tb);
                break;
            }
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}