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
const int maxn = 100000 + 5;

char a[maxn],b[maxn];

int main() {
    int n,cnt0=0,cnt1=0;
    scanf("%d",&n);
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='0')  cnt0++;
        else  cnt1++;
    }
    ll ans=0,ccnt0=0,ccnt1=0;
    for(int i=1;i<=n;i++){
        if(b[i]=='1')  continue;
        if(a[i]=='0'){
            ans+=1ll*cnt1;
            ccnt0++;
        }
        else{
            ans+=1ll*cnt0;
            ccnt1++;
        }
    }
    printf("%I64d\n",ans-ccnt1*ccnt0);
    return 0;
}