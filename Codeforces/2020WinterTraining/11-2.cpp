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
    int n;
    scanf("%d",&n);
    int sz=(n+1)/2;
    if((n&1)==0)  sz++;
    int x=1,y=1;
    printf("%d\n",sz);
    rep(i,1,n){
        printf("%d %d\n",x,y);
        if(i&1)  y++;
        else  x++;
    }
    return 0;
}