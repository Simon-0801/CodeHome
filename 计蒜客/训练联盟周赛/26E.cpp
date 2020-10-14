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

int gcd(int a,int b){
    if(a==0)  return b;
    if(b==0)  return a;
    return __gcd(a,b);
}

int main() {
    int t,x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(gcd(abs(x1),abs(y1))==gcd(abs(x2),abs(y2))){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}