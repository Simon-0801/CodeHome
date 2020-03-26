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

int vis[20];

bool check(int num){
    int tmp=num;
    if(tmp==0&&vis[tmp])  return false;
    while(tmp){
        int n=tmp%10;
        tmp/=10;
        if(vis[n])  return false;
    }
    return true;
}

int main() {
    int n,tmp,num,cnt=0;
    scanf("%d",&n);
    mst(vis,0);
    rep(i,1,n){
        scanf("%d",&tmp);
        vis[tmp]=1;
    }
    scanf("%d",&num);
    int ans=INF;
    rep(i,0,999){
        if(check(i)){
            ans=min(ans,abs(i-num));
        }
    }
    printf("%d\n",ans);
    return 0;
}