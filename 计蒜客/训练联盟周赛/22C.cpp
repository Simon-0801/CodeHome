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
const int maxn = 1000000 + 5;

char str[110];
int vis[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(cas,1,n){
        scanf("%s",str+1);
        int len=strlen(str+1);
        if(str[1]!='-'&&len<=7){
            int tmp=0;
            rep(i,1,len){
                tmp*=10;
                tmp+=str[i]-'0';
            }
            if(tmp>=0&&tmp<=n-1){
                vis[tmp]=1;
            }
        }
    }
    int pre=-1;
    rep(i,0,n){
        if(!vis[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}