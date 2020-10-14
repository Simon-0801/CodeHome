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
const int maxn = 100 + 5;

struct node
{
    int r,g,b;
};

node p[maxn][3];
char str[10];
int num[10];
int mp1[maxn][maxn],mp2[maxn][maxn];

PII solve(int x,int y){
    rep(i,0,2){
        rep(j,0,2){
            if(abs(p[x][i].r-p[y][j].r)+abs(p[x][i].g-p[y][j].g)+abs(p[x][i].b-p[y][j].b)>=128){
                return PII(i+1,j+1);
            }
        }
    }
    return PII(0,0);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            rep(j,0,2){
                scanf("%s",str);
                rep(k,0,5){
                    if(str[k]<='9'&&str[k]>='0')  num[k]=str[k]-'0';
                    else  num[k]=str[k]-'A'+10;
                }
                int tmp=num[0]*16+num[1];
                p[i][j].r=tmp;
                tmp=num[2]*16+num[3];
                p[i][j].g=tmp;
                tmp=num[4]*16+num[5];
                p[i][j].b=tmp;
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                if(i==j){
                    mp1[i][j]=mp2[i][j]=0;
                    continue;
                }
                PII res=solve(i,j);
                if(res.first==0){
                    mp1[i][j]=0;
                    mp2[j][i]=0;
                }
                else{
                    mp1[i][j]=res.first;
                    mp2[j][i]=res.second;
                }
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                printf("%d ",mp1[i][j]);
            }
            puts("");
        }
        rep(i,1,n){
            rep(j,1,n){
                printf("%d ",mp2[i][j]);
            }
            puts("");
        }
    }
    return 0;
}