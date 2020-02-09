#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
 
#define ll long long
#define INF 0x3f3f3f3f
#define N 3
 
using namespace std;
 
const int maxn=1000005;
const ll mod=1e9+6;
const ll mod2=1e9+7;

// char str[maxn];
 
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
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j]%mod+mod)%mod;
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
 
mat dmatqp(char* n,mat a){//十进制矩阵快速幂（类比二进制写） 
    mat ans;
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            if(i==j)ans.m[i][j]=1;
            else ans.m[i][j]=0;
    int len=strlen(n);
    for(i=len-1;i>=0;i--){
	int num=n[i]-'0';
	for(j=1;j<=num;j++)  ans=mul(ans,a);//这里处理的是每一位的系数 
	mat tmp=a;
	for(j=1;j<=9;j++)  a=mul(a,tmp);//这里计算下一位的基数 
    }
	return ans;
}

ll getFib(ll n){
    if(n==1||n==2)  return 1;
    mat mt;
    mt.m[1][1]=1;
    mt.m[1][2]=1;
    mt.m[1][3]=0;
    mt.m[2][1]=1;
    mt.m[2][2]=0;
    mt.m[2][3]=0;
    mt.m[3][1]=0;
    mt.m[3][2]=0;
    mt.m[3][3]=0;
    mat tmp=matqp(n-2,mt);
    mat ans;
    ans.m[1][1]=1;
    ans.m[2][1]=1;
    ans.m[3][1]=0;
    ans.m[1][2]=0;
    ans.m[2][2]=0;
    ans.m[3][2]=0;
    ans.m[1][3]=0;
    ans.m[2][3]=0;
    ans.m[3][3]=0;
    ans=mul(tmp,ans);
    return (tmp.m[1][1]+tmp.m[1][2])%mod;
}

ll getBFib(ll n){
    if(n==1)  return 1;
    if(n==2)  return 2;
    mat mt;
    mt.m[1][1]=1;
    mt.m[1][2]=1;
    mt.m[1][3]=1;
    mt.m[2][1]=1;
    mt.m[2][2]=0;
    mt.m[2][3]=0;
    mt.m[3][1]=0;
    mt.m[3][2]=0;
    mt.m[3][3]=1;
    mat tmp=matqp(n-2,mt);
    mat ans;
    ans.m[1][1]=2;
    ans.m[2][1]=1;
    ans.m[3][1]=1;
    ans.m[2][1]=0;
    ans.m[2][2]=0;
    ans.m[2][3]=0;
    ans.m[3][1]=0;
    ans.m[3][2]=0;
    ans.m[3][3]=0;
    ans=mul(tmp,ans);
    return (tmp.m[1][1]*2+tmp.m[1][2]+tmp.m[1][3])%mod;
}

ll qpow(ll num,ll p){
    if(num==1||p==0)  return 1;
    if(num==0)  return 0;
    ll ans=1;
    while(p){
        if(p&1)  ans=(ans*num)%mod2;
        num=(num*num)%mod2;
        p>>=1;
    }
    return ans%mod2;
}
 
int main(){
    ll n,x,y,a,b;
    scanf("%lld%lld%lld%lld%lld",&n,&x,&y,&a,&b);
    if(n==1){
        printf("%lld\n",x%mod2);
        return 0;
    }
    if(n==2){
        printf("%lld\n",y%mod2);
        return 0;
    }
    if(x%mod2==0||y%mod2==0||a%mod2==0){
        printf("0\n");
        return 0;
    }
    ll xpow=getFib(n-2);
    ll ypow=getFib(n-1);
    ll bpow=getBFib(n-2);
    a=qpow(a%mod2,b);
    // b=b*bpow%mod;
    ll tmpx=qpow(x%mod2,xpow);
    ll tmpy=qpow(y%mod2,ypow);
    ll tmp=qpow(a%mod2,bpow);
    ll ans=tmpx*tmpy%mod2*tmp%mod2;
    printf("%lld\n",ans%mod2);
    return 0;
} 