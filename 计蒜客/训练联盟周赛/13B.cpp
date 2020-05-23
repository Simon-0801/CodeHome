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
const int maxn = 20 + 5;

char str[10];
char mp[maxn][maxn];

int main() {
    int n,m,cas=0;
    while(scanf("%d%d",&m,&n)){
        if(n==0&&m==0)  break;
        cas++;
        rep(i,0,m-1){
            rep(j,0,n-1){
                scanf("%s",str);
                mp[i][j]=str[0];
            }
        }
        printf("Matrix #%d:\n",cas);
        printf("Original:\n");
        rep(i,0,m-1){
            rep(j,0,n-1){
                printf("%c%c",mp[i][j],j==n-1?'\n':' ');
            }
        }
        printf("Snail:\n");
        int level = m / 2 + m % 2,t=0;
        for (int i = 0; i < level; i++) 
        {
            int cnt=0;
            for (int j = i; j <= n - 1 - i && t <= m*n - 1; j++)
                printf("%c",mp[i][j]),t++,cnt++;
            if(cnt)  printf("\n");
            cnt=0;
            for (int j = i + 1; j <= m - 1 - i && t <= m*n - 1; j++)
                printf("%c",mp[j][n - 1 - i]),t++,cnt++;
            if(cnt)  printf("\n");
            cnt=0;
            for (int j = n - i - 2; j >= i && t <= m*n - 1; j--)
                printf("%c",mp[m - 1 - i][j]),t++,cnt++;
            if(cnt)  printf("\n");
            cnt=0;
            for (int j = m - 2 - i; j >= i + 1 && t <= m*n - 1; j--)
                printf("%c",mp[j][i]),t++,cnt++;
            if(cnt)  printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}