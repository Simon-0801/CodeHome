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
const int maxn = 50 + 5;

int mp[maxn][maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        if(n*a==m*b){
            printf("YES\n");
            mst(mp,0);
            int pos=0;
            rep(i,0,n-1){
                rep(j,0,a-1){
                    mp[i][pos++]=1;
                    pos%=m;
                }
            }
            rep(i,0,n-1){
                rep(j,0,m-1){
                    printf("%d",mp[i][j]);
                }
                printf("\n");
            }
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}