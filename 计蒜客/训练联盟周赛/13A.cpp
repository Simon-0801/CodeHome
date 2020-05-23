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
char str[10];
vector<char> ansup,ansdown;

int main() {
    int n,q,cas=0,line;
    while(scanf("%d",&n)&&n){
        cas++;
        rep(i,1,n){
            rep(j,1,n){
                scanf("%s",str);
                mp[i][j]=str[0];
            }
        }
        printf("Input matrix #%d:\n",cas);
        rep(i,1,n){
            rep(j,1,n){
                printf("%c%c",mp[i][j],j==n?'\n':' ');
            }
        }
        scanf("%d",&q);
        rep(i,1,q){
            scanf("%d",&line);
            printf("Symmetric diagonals %d:\n",line);
            line--;
            if(line==0){
               rep(i,1,n){
                    int j=i+line;
                    if(j>=1&&j<=n){
                        printf("%c%c",mp[i][j],i==n?'\n':' ');
                    }
                } 
                continue;
            }
            ansup.clear();
            ansdown.clear();
            rep(i,1,n){
                int j=i+line;
                if(j>=1&&j<=n){
                    ansup.push_back(mp[i][j]);
                }
            }
            rep(i,1,n){
                int j=i-line;
                if(j>=1&&j<=n){
                    ansdown.push_back(mp[i][j]);
                }
            }
            int len=ansup.size();
            rep(i,0,len-1){
                printf("%c%c",ansup[i],i==len-1?'\n':' ');
            }
            rep(i,0,len-1){
                printf("%c%c",ansdown[i],i==len-1?'\n':' ');
            }
        }
        printf("\n");
    }
    return 0;
}