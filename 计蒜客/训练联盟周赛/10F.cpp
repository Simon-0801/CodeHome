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

int f[maxn][maxn],l[maxn][maxn];

struct node
{
    int x,y,z;
};

vector<node> mx,mn;
queue<int> p,q;

int main() {
    int n,m,h;
    scanf("%d%d%d",&n,&m,&h);
    rep(i,1,n){
        rep(j,1,m){
            scanf("%1d",&f[i][j]);
        }
    }
    rep(i,1,n){
        rep(j,1,h){
            scanf("%1d",&l[i][j]);
        }
    }
    int flag=1;
    rep(i,1,n){
        rep(j,1,m){
            if(f[i][j]){
                int ff=0;
                rep(k,1,h){
                    if(l[i][k]){
                        ff=1;
                        break;
                    }
                }
                if(!ff){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag)  break;
        rep(k,1,h){
            if(l[i][k]){
                int ff=0;
                rep(j,1,m){
                    if(f[i][j]){
                        ff=1;
                        break;
                    }
                }
                if(!ff){
                    flag=0;
                    break;
                }
            }
        }
        if(!flag)  break;
    }
    if(!flag){
        printf("-1\n");
        return 0;
    }
    node tmp;
    rep(i,1,n){
        rep(j,1,m){
            if(!f[i][j])  continue;
            rep(k,1,h){
                if(l[i][k]){
                    tmp.x=i;
                    tmp.y=j;
                    tmp.z=k;
                    mx.push_back(tmp);
                }
            }
        }
    }
    rep(i,1,n){
        tmp.x=i;
        rep(j,1,m){
            if(f[i][j]){
                p.push(j);
            }
        }
        rep(k,1,h){
            if(l[i][k]){
                q.push(k);
            }
        }
        while(p.size()>q.size()){
            tmp.y=p.front();
            tmp.z=q.front();
            p.pop();
            mn.push_back(tmp);
        }
        while(p.size()<q.size()){
            tmp.y=p.front();
            tmp.z=q.front();
            q.pop();
            mn.push_back(tmp);
        }
        while(p.size()&&q.size()){
            tmp.y=p.front();
            tmp.z=q.front();
            p.pop();
            q.pop();
            mn.push_back(tmp);
        }
    }
    printf("%d\n",mx.size());
    for(auto &nod:mx){
        printf("%d %d %d\n",nod.x-1,nod.y-1,nod.z-1);
    }
    printf("%d\n",mn.size());
    for(auto &nod:mn){
        printf("%d %d %d\n",nod.x-1,nod.y-1,nod.z-1);
    }
    return 0;
}