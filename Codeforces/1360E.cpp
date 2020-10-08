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

char mp[maxn][maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%s",mp[i]+1);
        }
        int flag=1;
        rep(i,1,n-1){
            rep(j,1,n-1){
                if(mp[i][j]=='0')  continue;
                if(mp[i][j+1]=='0'&&mp[i+1][j]=='0'){
                    flag=0;
                }
            }
        }
        if(flag)  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}