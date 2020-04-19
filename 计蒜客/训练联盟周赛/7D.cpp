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

int cnt1[maxn],cnt2[maxn];

int main() {
    int n,tmp;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&tmp);
        cnt1[tmp]++;
    }
    rep(i,1,n){
        scanf("%d",&tmp);
        cnt2[tmp]++;
    }
    int pa=0;
    rep(i,1,99999){
        if(cnt1[i]&&cnt2[i]){
            pa+=min(cnt1[i],cnt2[i]);
        }
    }
    printf("%d\n",n-pa);
    return 0;
}