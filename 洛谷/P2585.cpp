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
const int maxn = 500000 + 5;

char str[maxn];
int dpmx[maxn][5],dpmn[maxn][5];

int dfs(int x){
    if(str[x]=='0'){
        dpmx[x][0]=1;
        dpmx[x][1]=dpmx[x][2]=0;
        dpmn[x][0]=1;
        dpmn[x][1]=dpmn[x][2]=0;
        return x;
    }
    else if(str[x]=='1'){
        int en=dfs(x+1);
        dpmx[x][0]=max(dpmx[x+1][1],dpmx[x+1][2])+1;
        dpmx[x][1]=max(dpmx[x+1][0],dpmx[x+1][2]);
        dpmx[x][2]=max(dpmx[x+1][0],dpmx[x+1][1]);
        dpmn[x][0]=min(dpmn[x+1][1],dpmn[x+1][2])+1;
        dpmn[x][1]=min(dpmn[x+1][0],dpmn[x+1][2]);
        dpmn[x][2]=min(dpmn[x+1][0],dpmn[x+1][1]);
        return en;
    }
    else{
        int en1=dfs(x+1);
        int en2=dfs(en1+1);
        dpmx[x][0]=max(dpmx[x+1][1]+dpmx[en1+1][2],dpmx[x+1][2]+dpmx[en1+1][1])+1;
        dpmx[x][1]=max(dpmx[x+1][0]+dpmx[en1+1][2],dpmx[x+1][2]+dpmx[en1+1][0]);
        dpmx[x][2]=max(dpmx[x+1][1]+dpmx[en1+1][0],dpmx[x+1][0]+dpmx[en1+1][1]);
        dpmn[x][0]=min(dpmn[x+1][1]+dpmn[en1+1][2],dpmn[x+1][2]+dpmn[en1+1][1])+1;
        dpmn[x][1]=min(dpmn[x+1][0]+dpmn[en1+1][2],dpmn[x+1][2]+dpmn[en1+1][0]);
        dpmn[x][2]=min(dpmn[x+1][1]+dpmn[en1+1][0],dpmn[x+1][0]+dpmn[en1+1][1]);
        return en2;
    }
}

int main() {
    scanf("%s",str+1);
    dfs(1);
    int mx=max(dpmx[1][0],max(dpmx[1][1],dpmx[1][2]));
    int mn=min(dpmn[1][0],min(dpmn[1][1],dpmn[1][2]));
    printf("%d %d\n",mx,mn);
    return 0;
}