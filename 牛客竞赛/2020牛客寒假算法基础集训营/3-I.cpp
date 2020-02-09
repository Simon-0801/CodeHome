#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

struct node
{
    ll cnt[8];
    ll sum;
    int flag;
}dp[65];

node move(int m){
    if(m==1){
        dp[m].cnt[2]=1;
        dp[m].sum=1;
        dp[m].flag=1;
        return dp[m];
    }
    if(dp[m].flag)
        return dp[m];
    dp[m].flag=1;
    node tmp=move(m-1);
    dp[m].sum+=2*tmp.sum+1;
    dp[m].cnt[1]+=dp[m-1].cnt[2];
    dp[m].cnt[2]+=dp[m-1].cnt[1];
    dp[m].cnt[3]+=dp[m-1].cnt[5];
    dp[m].cnt[4]+=dp[m-1].cnt[6];
    dp[m].cnt[5]+=dp[m-1].cnt[3];
    dp[m].cnt[6]+=dp[m-1].cnt[4];
    dp[m].cnt[2]++;
    dp[m].cnt[1]+=dp[m-1].cnt[3];
    dp[m].cnt[2]+=dp[m-1].cnt[4];
    dp[m].cnt[3]+=dp[m-1].cnt[1];
    dp[m].cnt[4]+=dp[m-1].cnt[2];
    dp[m].cnt[5]+=dp[m-1].cnt[6];
    dp[m].cnt[6]+=dp[m-1].cnt[5];
    return dp[m];
}


int main() {
    int n;
    scanf("%d",&n);
    node ans=move(n);
    printf("A->B:%lld\nA->C:%lld\nB->A:%lld\nB->C:%lld\nC->A:%lld\nC->B:%lld\nSUM:%lld\n",dp[n].cnt[1],dp[n].cnt[2],dp[n].cnt[3],dp[n].cnt[4],dp[n].cnt[5],dp[n].cnt[6],dp[n].sum);
    return 0;
}