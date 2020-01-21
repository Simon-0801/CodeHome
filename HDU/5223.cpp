#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

#define ll long long
#define INF 0x3f3f3f3f
 
using namespace std;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll num[1005];
int vis[1005];
int L[1005],R[1005],Ansi[1005];

int main(){
	int t;
	scanf("%d",&t);
	int n,q;
	while(t--){
		scanf("%d%d",&n,&q);
		int l,r;
		ll ansi;
		for(int i=1;i<=n;i++)  num[i]=1;
//		memset(vis,0,sizeof(vis));
		int fflag=1;
		for(int i=1;i<=q;i++){
			scanf("%d%d%lld",&L[i],&R[i],&Ansi[i]);
			
			for(int j=L[i];j<=R[i];j++){
				num[j]=(num[j]/gcd(num[j],Ansi[i])*Ansi[i]);
//				vis[j]=1;
			}
		}
//		if(fflag==0){
//			printf("Stupid BrotherK!\n");
//			continue;
//		}
		int flag=1;
		for(int i=1;i<=q;i++){
			ll g=num[L[i]];
			for(int j=L[i]+1;j<=R[i];j++){
				g=gcd(g,num[j]);
//				vis[j]=1;
			}
//			cout<<g<<endl;
			if(g!=Ansi[i]){
				flag=0;
			}
		}
//		for(int i=1;i<=n;i++){
//			if(vis[i]==0){
//				flag=0;
//				break;
//			}
//		}
		if(flag){
			for(int i=1;i<=n;i++){
				printf("%lld%c",num[i],i==n?'\n':' ');
			}
		}
		else{
			printf("Stupid BrotherK!\n");
		}
	}
	return 0;
}
