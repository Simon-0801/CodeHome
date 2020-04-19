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
    int a,b,num;
    scanf("%d%d%d",&a,&b,&num);
    while(num--){
        if(a>b){
            a=a/2;
        }
        else{
            b=b/2;
        }
    }
    if(a<b)  swap(a,b);
    printf("%d %d\n",a,b);
    return 0;
}