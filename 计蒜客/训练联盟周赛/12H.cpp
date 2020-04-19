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
const int maxn = 200 + 5;

char str[maxn*maxn];
char mp[maxn][maxn],ans[maxn][maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len=strlen(str);
        int n=(int)sqrt(len);
        if(n*n!=len)  n++;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(i*n+j<len){
                    mp[i][j]=str[i*n+j];
                }
                else{
                    mp[i][j]='*';
                }
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
                ans[i][j]=mp[n-1-j][i];
            }
        }
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(ans[i][j]=='*')  continue;
                printf("%c",ans[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}