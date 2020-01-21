#include <iostream>

#include <cstring>

#include <algorithm>

#include <string>

 

#define ll long long

#define INF 0x3f3f3f3f

#define N 2

 

using namespace std;

 

const int maxn=1000005;

 

ll mod=7;

char str[maxn];

 

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

 

int main(){
	
	int A,B;
	ll n;
    while(scanf("%d%d%lld",&A,&B,&n)!=EOF&&(A&&B&&n)){
    	mat mt;

	    mt.m[1][1]=A;
	
	    mt.m[1][2]=B;
	
	    mt.m[2][1]=1;
	
	    mt.m[2][2]=0;
	    
	    ll answ;
	    
	    if(n==1)  answ=1;
	    
	    if(n==2)  answ=1;
	    
	    if(n>2){
	    	mat res=matqp(n-2,mt);
	    
	    	answ=((res.m[1][1]*1+mod)%mod+(res.m[1][2]*1+mod)%mod)%mod;
		}
	    
	    printf("%lld\n",answ%mod);
	}

    

    return 0;

} 

