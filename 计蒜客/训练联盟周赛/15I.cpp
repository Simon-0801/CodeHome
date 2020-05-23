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



int main() {
    int w,s,c,k;
    scanf("%d%d%d%d",&w,&s,&c,&k);
    if(w+c>k&&s>k)
    {
        printf("NO\n");
        return 0;
    }
    if(s<k)
    {
        printf("YES\n");
        return 0;
    }
    if(w+c<k)
    {
        printf("YES\n");
        return 0;
    }
    if(w+c==k&&s<=2*k)
    {
        printf("YES\n");
        return 0;
    }
    if(s==k&&(w+c)<=2*k)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}