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
const int maxn = 100000 + 5;

struct node
{
    char name[10];
    ll c;
    bool operator< (const node& a) const{
        return c<a.c;
    }
};

node emp[maxn];

int main() {
    ll n,d,k;
    scanf("%lld%lld%lld",&n,&d,&k);
    rep(i,1,n){
        scanf("%s%lld",emp[i].name,&emp[i].c);
    }
    sort(emp+1,emp+n+1);
    ll tot=0;
    repd(i,n,n-k+1){
        tot+=emp[i].c;
    }
    if(tot<d){
        printf("impossible\n");
        return 0;
    }
    printf("%lld\n",k);
    repd(i,n,n-k+1){
        printf("%s, YOU ARE FIRED!\n",emp[i].name);
    }
    return 0;
}