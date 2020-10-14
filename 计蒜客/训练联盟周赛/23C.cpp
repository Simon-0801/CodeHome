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

int p[10];

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        rep(i,0,4){
            scanf("%d",p+i);
        }
        while(1){
            int id=-1;
            int mn=INF;
            rep(i,0,4){
                if(p[i]<mn){
                    mn=p[i];
                    id=i;
                }
            }
            if(mn>=0)  break;
            p[id]=-mn;
            p[(id+1)%5]+=mn;
            p[(id-1+5)%5]+=mn;
        }
        printf("Pentagon #%d:\n",cas);
        rep(i,0,4){
            printf("%d%c",p[i],i==4?'\n':' ');
        }
        printf("\n");
    }
    return 0;
}