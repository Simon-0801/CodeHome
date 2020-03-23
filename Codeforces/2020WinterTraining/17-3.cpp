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
const int maxn = 150000 + 5;

int cnt[maxn];

int main() {
    int n,tmp;
    scanf("%d",&n);
    mst(cnt,0);
    int ans=0;
    rep(i,1,n){
        scanf("%d",&tmp);
        cnt[tmp]++;
    }
    rep(i,1,maxn-4){
        if(cnt[i-1]){
            cnt[i-1]--;
            ans++;
        }
        else if(cnt[i]){
            cnt[i]--;
            ans++;
        }
        else if(cnt[i+1]){
            cnt[i+1]--;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}