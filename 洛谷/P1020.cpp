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

int a[maxn];
int dp[maxn],cnt[maxn];

int main() {
    int num,j=0;
    while(~scanf("%d",&num)){
        a[++j]=num;
    }
    int len=1;
    dp[1]=a[j];
    repd(i,j-1,1){
        if(a[i]>=dp[len]){
            ++len;
            dp[len]=a[i];
            continue;
        }
        int l=1,r=len,res;
        while(l<=r){
            int mid=(l+r)/2;
            if(dp[mid]>a[i])  r=mid-1,res=mid;
            else  l=mid+1;
        }
        dp[res]=a[i];
    }
    printf("%d\n",len);
    len=1;
    dp[1]=a[1];
    rep(i,2,j){
        if(a[i]>dp[len]){
            ++len;
            dp[len]=a[i];
            continue;
        }
        int l=1,r=len,res;
        while(l<=r){
            int mid=(l+r)/2;
            if(dp[mid]>=a[i])  r=mid-1,res=mid;
            else  l=mid+1;
        }
        dp[res]=a[i];
    }
    printf("%d\n",len);
    return 0;
}