#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int res=0,cnt=0;
		for(int i=2;i<=n;i++){
			int a;
			scanf("%d",&a);
			if(i-1>res&&a==1){
				res+=2;
				
//				cnt++;
//				if(cnt==1) res+=2;
//				else if(cnt&1){
//					res+=2;
//				}
			}
		} 
		if((n&1)==0&&res==n) printf("Yes\n");
		else printf("No\n");
//		int res=1;
//		for(int i=2;i<=n;i++){
//			int a;
//			scanf("%d",&a);
//			if(a==2||res==0){
//				res++;
//			}
//			else{
//				res--;
//			}
//		}
//		if(res==0) printf("Yes\n");
//		else  printf("No\n");
	}
	return 0;
}
