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
const int maxn = 1000 + 5;

ll song[maxn][15];
ll dp[maxn][15];
ll t;

ll getdif(ll a,ll b){
    ll res;
    if(a<b){
        res=(b-a-1);
        res=min(res,(a+t-b+1));
    }
    else if(a==b){
        res=1;
        res=min(res,(t+1));
    }
    else{
        res=a-b+1;
        res=min(res,t-a+b-1);
    }
    return res;
}

int main() {
    scanf("%lld",&t);
    int s;
    scanf("%d",&s);
    rep(i,1,s){
       scanf("%lld",&song[i][0]);
       rep(j,1,song[i][0]){
           scanf("%lld",&song[i][j]);
       } 
    }
    song[0][0]=1;
    song[0][1]=1;
    rep(i,1,song[1][0]){
        int tid=song[1][i];
        dp[1][i]=getdif(t,tid);
    }
    rep(i,2,s){
        int mx=song[i][0];
        rep(j,1,mx){
            dp[i][j]=1e18;
            rep(k,1,song[i-1][0]){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+getdif(song[i-1][k],song[i][j]));
            }
        }
    }
    ll ans=1e18;
    rep(i,1,song[s][0]){
        ans=min(ans,dp[s][i]);
    }
    printf("%lld\n",ans);
    return 0;
}