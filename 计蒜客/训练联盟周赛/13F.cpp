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
const int maxn = 55 + 5;

map<int,int> mp;
int flag[maxn],vis[maxn];
int pos[maxn];

int main() {
    int n,r,cas=0,pid,po,cnt;
    while(scanf("%d%d",&n,&r)){
        if(n==0&&r==0)  break;
        cas++;
        printf("Program %d\n",cas);
        mp.clear();
        po=1;
        cnt=0;
        mst(flag,0);
        mst(vis,0);
        mst(pos,0);
        rep(q,1,r){
            scanf("%d",&pid);
            if(!pos[pid]){
                int em=0;
                rep(i,1,n){
                    if(!vis[i]){
                        em=i;
                        break;
                    }
                }
                if(em){
                    vis[em]=pid;
                    pos[pid]=em;
                    flag[em]=1;
                }
                else{
                    while(flag[po]){
                        flag[po]=0;
                        if(po==n)  po=1;
                        else po++;
                    }
                    pos[vis[po]]=0;
                    pos[pid]=po;
                    flag[po]=1;
                    vis[po]=pid;
                    em=po;
                    if(po==n) po=1;
                    else  po++;
                }
                printf("Page %d loaded into cell %d.\n",pid,em);
                cnt++;
            }
            else{
                flag[pos[pid]]=1;
                printf("Access page %d in cell %d.\n",pid,pos[pid]);
            }
        }
        printf("There are a total of %d page faults.\n\n",cnt);
    }
    return 0;
}