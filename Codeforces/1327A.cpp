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
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(n<k){
            printf("NO\n");
            continue;
        }
        if((n-k)%2){
            printf("NO\n");
            continue;
        }
        ll tmp=(ll)(n-k)/2;
        ll num=1ll*(k-1)*k/2;
        // while(tmp){
        //     tmp-=num;
        //     num++;
        // }
        if(tmp>=num)  printf("YES\n");  
        else  printf("NO\n");
    }
    return 0;
}