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

ll mp[1005][1005];

int main() {
    int n,m,t,p;
    while(scanf("%d%d%d%d",&n,&m,&t,&p)&&n&&m&&t&&p){
        int bt=1000,lft=1,tp=1000-m+1,rgt=n;
        rep(i,tp,bt){
            rep(j,1,n){
                mp[i][j]=1;
            }
        }
        int d,c,x,y;
        rep(q,1,t){
            scanf("%d%d",&d,&c);
            if(d==1){
                int tmp=c-1;
                rep(i,tp,bt){
                    rep(j,0,tmp){
                        mp[i][lft+c+j]+=mp[i][lft+c-j-1];
                        mp[i][lft+c-j-1]=0;
                    }
                }
                lft+=c;
                rgt=max(rgt,lft+c+c-1);
            }
            else{
                int tmp=c-1;
                rep(j,lft,rgt){
                    rep(i,0,tmp){
                        mp[bt-c-i][j]+=mp[bt-c+i+1][j];
                        mp[bt-c+i+1][j]=0;
                    }
                }
                bt-=c;
                tp=min(tp,bt-c-c+1);
            }
        }
        ll ans=0;
        rep(q,1,p){
            scanf("%d%d",&x,&y);
            x=lft+x;
            y=bt-y;
            printf("%lld\n",mp[y][x]);
        }
        rep(i,tp,bt){
            rep(j,lft,rgt){
                mp[i][j]=0;
            }
        }
    }
    return 0;
}