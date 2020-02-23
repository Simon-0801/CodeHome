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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 200000 + 5;

int a[maxn];
int num[maxn],cnt[maxn];

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int tmp=a[i],j=0;tmp;j++,tmp/=2){
            num[tmp]+=j;
            cnt[tmp]++;
            if(cnt[tmp]==k)  ans=min(ans,num[tmp]);
        }
    }
    printf("%d\n",ans);
    return 0;
}