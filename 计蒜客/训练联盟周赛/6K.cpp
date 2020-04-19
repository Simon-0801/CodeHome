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

priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        while(!pq.empty())  pq.pop();
        int n,a;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d",&a);
            pq.push(a);
        }
        n--;
        ll ans=0;
        while(n--){
            int x=pq.top();pq.pop();
            int y=pq.top();pq.pop();
            ans+=1ll*(x+y);
            // printf("%d\n",(x+y));
            pq.push(x+y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}