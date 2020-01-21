
#include <iostream>

#include <cstring>

#include <algorithm>

#include <string>

 

#define ll long long

#define INF 0x3f3f3f3f

#define N 3

 

using namespace std;

 

const int maxn=1000005;

 

ll mod=1e9+7;

//char str[maxn];

 

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

//    ll x0,x1,a,b;
//
//    scanf("%lld%lld%lld%lld",&x0,&x1,&a,&b);
//
//    scanf("%s",str);
//
//    scanf("%lld",&mod);
//
//    int len=strlen(str);
//
//    int l=len-1;
//
//    while(l>=0){//这里将str数组中代表的整数减一 
//
//	if(str[l]=='0'){
//
//		str[l]='9';
//
//		l--;
//
//		continue;
//
//	}
//
//	else{
//
//		str[l]--;
//
//		break;
//
//	}
//
//    }

	int t;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		mat mt;

    mt.m[1][1]=1;

    mt.m[1][2]=0;
    mt.m[1][3]=1;

    mt.m[2][1]=1;

    mt.m[2][2]=0;
	mt.m[2][3]=0; 
	mt.m[3][1]=0;
	mt.m[3][2]=1;
	mt.m[3][3]=0;
	
	if(n==2){
		printf("3\n");
		continue;
	}
	if(n==3){
		printf("4\n");
		continue;
	}
	if(n==4){
		printf("6\n");
		continue;
	}
	
	mat res=matqp(n-4,mt);
	
	ll answ=((res.m[1][1]*6+mod)%mod+(res.m[1][2]*4+mod)%mod+(res.m[1][3]*3+mod)%mod)%mod;
	
	printf("%lld\n",answ%mod);
	
	}
    //构造初始矩阵 

    

    

    

    

    return 0;

} 

