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

ll a[maxn],b[maxn];

int main() {
    int t;
    ll n,m,sum=0,ans=0;
    scanf("%d",&t);
    while(t--){
        sum=0;
        ans=0;
        b[0]=0;
        scanf("%I64d%I64d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++){
            b[i]=b[i-1]+a[i];
        }
        if(b[m]<n){
            printf("-1\n");
            continue;
        }
        for(int i=m;i>0;i--){
            if(n>=a[i]){
                n-=a[i];
            }
            while(n>b[i-1]){
                a[i]/=2;
                ans++;
                if(n>=a[i])  n-=a[i];
            }
            if(n==0)  break;
        }
        if(n)  printf("-1\n");
        else  printf("%I64d\n",ans);
    }
    return 0;
}