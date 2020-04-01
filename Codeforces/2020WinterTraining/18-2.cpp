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

int main() {
    int n,tmp;
    scanf("%d",&n);
    int cnt=0;
    ll sum=0;
    int mn=INF;
    rep(i,1,n){
        scanf("%d",&tmp);
        if(tmp>0){
            sum+=1ll*tmp;
            if(tmp&1){
                mn=min(mn,tmp);
            }
        }
        if(tmp<0){
            tmp=-tmp;
            if(tmp&1){
                mn=min(mn,tmp);
            }
        }
    }
    if(sum&1){
        printf("%lld\n",sum);
    }
    else{
        sum-=mn;
        printf("%lld\n",sum);
    }
    return 0;
}