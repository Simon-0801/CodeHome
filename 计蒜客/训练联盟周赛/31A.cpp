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
const int maxn = 1000 + 5;

int sum[maxn];

int main() {
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m){
        mst(sum,0);
        int tmp;
        rep(i,1,m){
            rep(j,1,n){
                scanf("%d",&tmp);
                sum[j]+=tmp;
            }
        }
        int mx=0;
        rep(i,1,n){
            mx=max(mx,sum[i]);
        }
        printf("%d\n",mx);
    }
    return 0;
}