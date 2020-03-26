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
const int maxn = 100 + 5;

int num[maxn];
int pos[maxn];
int dp[maxn];

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",num+i);
        pos[num[i]]=i;
    }
    dp[1]=1;
    int mx=1;
    rep(i,2,n){
        int tmp=num[i];
        if(tmp==1)  dp[i]=1;
        else{
            if(pos[tmp-1]<i)  dp[i]=dp[pos[tmp-1]]+1;
            else  dp[i]=1;
        }
        mx=max(mx,dp[i]);
    }
    printf("%d\n",n-mx);
    return 0;
}