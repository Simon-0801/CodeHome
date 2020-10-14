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

char str[10][50]={"","Habb Yakk","Dobara","Dousa","Dorgy","Dabash","Dosh"};
char name[10][50]={"","Yakk","Doh","Seh","Ghar","Bang","Sheesh"};

int main() {
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int a,b;
        ++cas;
        scanf("%d%d",&a,&b);
        if((a==5&&b==6)||(a==6&&b==5)){
            printf("Case %d: Sheesh Beesh\n",cas);
            continue;
        }
        if(a==b){
            printf("Case %d: %s\n",cas,str[a]);
            continue;
        }
        int mx=max(a,b),mn=min(a,b);
        printf("Case %d: %s %s\n",cas,name[mx],name[mn]);
    }
    return 0;
}