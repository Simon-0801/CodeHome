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
        ll n,k;
        scanf("%lld%lld",&n,&k);
        k=n*(n-1)/2-k+1;
        int fi,se;
        fi=1;
        int nxt=n-1;
        while(k>nxt){
            k-=nxt;
            nxt--;
            fi++;
        }
        se=k+fi;
        rep(i,1,n){
            if(i==fi||i==se)  printf("b");
            else  printf("a");
        }
        printf("\n");
    }
    return 0;
}