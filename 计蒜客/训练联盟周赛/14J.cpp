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
const ll mod = 1e5 + 7;
const int maxn = 100000 + 5;

const int N=2;

struct mat{
    ll m[N+1][N+1];
};
mat mul(mat a,mat b){
    mat ans;
    int i,j,k;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            ans.m[i][j]=0;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            for(k=1;k<=N;k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j]+mod)%mod;
    return ans;
}
 
mat matqp(ll p,mat t){//二进制矩阵快速幂，此题不可用 
    mat ans;
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            if(i==j)ans.m[i][j]=1;
            else ans.m[i][j]=0;
    while(p)
    {
        if(p&1)
            ans=mul(ans,t);
        t=mul(t,t);
        p=p>>1;
    }
    return ans; 
}

int main() {
    int n;
    scanf("%d",&n);
    mat mt;
    mt.m[1][1]=1;
    mt.m[1][2]=1;
    mt.m[2][1]=1;
    mt.m[2][2]=0;
    mat res=matqp(2*n-3,mt);
    ll ans=res.m[1][1]*1%mod+res.m[1][2]*1%mod;
    ans%=mod;
    ans=(ans*n)%mod;
    printf("%lld\n",ans);
    return 0;
}