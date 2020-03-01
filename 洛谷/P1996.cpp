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
const int maxn = 100 + 5;

int vis[maxn];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int tmp=1,in=n,cnt=1;
    while(in){
        if(vis[tmp]){
            tmp++;
            if(tmp>n)  tmp=1;
            continue;
        }
        if(cnt==m){
            printf("%d ",tmp);
            vis[tmp]=1;
            in--;
            cnt=1;
            tmp++;
            if(tmp>n)  tmp=1;
            continue;
        }
        tmp++;
        if(tmp>n)  tmp=1;
        cnt++;
    }
    return 0;
}