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

int num[maxn];
int sum[maxn];

int main() {
    int m;
    scanf("%d",&m);
    int flag=0;
    rep(i,1,m){
        num[i]=1;
    }
    sum[0]=0;
    int ans=0;
    rep(i,1,m){
        int tmp=i;
        while(tmp%5==0){
            tmp/=5;
            num[i]++;
        }
        sum[i]=sum[i-1]+num[i];
        if(sum[i]==m){
            ans=i*5;
            break;
        }
        if(sum[i]>m){
            break;
        }
    }
    if(ans){
        printf("5\n");
        rep(i,0,4){
            printf("%d ",ans+i);
        }
    }
    else printf("0");
    return 0;
}