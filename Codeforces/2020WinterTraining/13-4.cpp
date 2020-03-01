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
    if(a>b)  swap(a,b);
    // if(b%a){
    //     printf("NO\n");
    //     return 0;
    // }
    int flag=0;
    int ansi,ansj;
    rep(i,1,a-1){
        rep(j,1,a-1){
            if(i==j)  continue;
            if(i*i+j*j==a*a&&(i*b)%a==0&&(j*b)%a==0&&j!=(i*b)/a){
                flag=1;
                ansi=i;
                ansj=j;
                break;
            }
        }
    }
    if(flag==0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        printf("0 0\n");
        printf("%d %d\n",ansi,ansj);
        ansi=(b*ansi)/a;
        ansj=(b*ansj)/a;
        printf("%d %d\n",-1*ansj,ansi);
    }
    return 0;
}