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
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

int n,cnt=0;
map<int,int> mp1,mp2,mp3;
int res[15];
ll fix;

void dfs(int row,ll col,ll l1,ll l2){
    if(row>n){
        ++cnt;
        if(cnt<=3){
            rep(i,1,n){
                printf("%d%c",res[i],i==n?'\n':' ');
            }
        }
        return;
    }
    l2=l2&fix;
    ll pos=~(col|l1|l2);
    pos=fix&pos;
    while(pos){
        ll p=pos&(-pos);
        // p=p&fix;
        res[row]=log2(p)+1;
        dfs(row+1,col|p,(l1|p)<<1,(l2|p)>>1);
        pos-=p;
        res[row]=0;
    }
    // rep(i,1,n){
    //     if(mp1[i]||mp2[i+row]||mp3[i-row])  continue;
    //     mp1[i]=mp2[i+row]=mp3[i-row]=1;
    //     res[row]=i;
    //     dfs(row+1);
    //     res[row]=0;
    //     mp1[i]=mp2[i+row]=mp3[i-row]=0;
    // }
}

int main() {
    scanf("%d",&n);
    mst(res,0);
    fix=(1<<n)-1;
    dfs(1,0,0,0);
    printf("%d\n",cnt);
    return 0;
}