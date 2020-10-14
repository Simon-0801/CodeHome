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
    int t,cas=0;
    scanf("%d",&t);
    while (t--)
    {
        ++cas;
        int g,p;
        scanf("%d%d",&g,&p);
        printf("Team #%d\nGames: %d\nPoints: %d\nPossible records:\n",cas,g,p);
        repd(w,g,0){
            rep(t,0,g-w){
                int l=g-w-t;
                if(3*w+t==p){
                    printf("%d-%d-%d\n",w,t,l);
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}