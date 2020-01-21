#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll mod=4294967296;
const int maxn=10000005;

unsigned int L[maxn],R[maxn];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned int n,l,r,a,b,c,d;
		scanf("%d%d%d%d%d%d%d",&n,&l,&r,&a,&b,&c,&d);
		L[1]=l;
		R[1]=r;
		unsigned int minr=R[1],maxl=L[1];
		for(int i=2;i<=n;i++){
			L[i]=(l*a+b)%mod;
			R[i]=(r*c+d)%mod;
			if(L[i]>R[i])  swap(L[i],R[i]);
			if(R[i]<minr)  minr=R[i];
			if(L[i]>maxl)  maxl=L[i];
			l=L[i];
			r=R[i];
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(L[i]>minr&&R[i]<maxl){
				flag=1;
				break;
			}
		}
		if(flag)  printf("YES\n");
		else  printf("NO\n");
	}
	return 0;
}
