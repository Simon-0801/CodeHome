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
    int n,a,b,c;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        int cnt=0;
        if(a>=10)  cnt++;
        if(b>=10)  cnt++;
        if(c>=10)  cnt++;
        printf("%d %d %d\n",a,b,c);
        if(cnt==0){
            printf("zilch\n\n");
        }
        else if(cnt==1){
            printf("double\n\n");
        }
        else if(cnt==2){
            printf("double-double\n\n");
        }
        else {
            printf("triple-double\n\n");
        }
    }
    return 0;
}