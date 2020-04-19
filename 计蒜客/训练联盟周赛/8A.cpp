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
    int a,b;
    scanf("%d%d",&a,&b);
    int n,c,ans;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&c);
        if(c<=1000){
            ans=c*a;
        }
        else{
            ans=1000*a+(c-1000)*b;
        }
        printf("%d %d\n",c,ans);
    }
    return 0;
}