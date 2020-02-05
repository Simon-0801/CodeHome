#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
 
#define ll long long
#define INF 0x3f3f3f3f
#define N 105
 
using namespace std;
 
const int maxn=1000005;
const ll mod=1e9+7;

char str[maxn];
int sz;
 
struct mat{
    ll m[N][N];
};
mat mul(mat a,mat b){
    mat ans;
    int i,j,k;
    for(i=1;i<=sz;i++)
        for(j=1;j<=sz;j++)
            ans.m[i][j]=0;
    for(i=1;i<=sz;i++)
        for(j=1;j<=sz;j++)
            for(k=1;k<=sz;k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j]+mod)%mod;
    return ans;
}
 
mat matqp(ll p,mat t){//二进制矩阵快速幂，此题不可用 
    mat ans;
    int i,j;
    for(i=1;i<=sz;i++)
        for(j=1;j<=sz;j++)
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
 
int main(){
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    if(n<m){
        printf("1\n");
        return 0;
    }
    mat tmp;
    memset(tmp.m,0,sizeof tmp.m);
    for(int i=2;i<=m;i++){
        tmp.m[i][i-1]=1;
    }
    tmp.m[1][1]=tmp.m[1][m]=1;
    sz=m;
    mat ans=matqp(n-m,tmp);
    ll res=0;
    for(int i=1;i<=m;i++){
        int tt;
        if(i==1)  tt=2;
        else tt=1;
        res=(res+ans.m[1][i]*tt)%mod;
    }
    printf("%I64d\n",res%mod);
    return 0;
} 