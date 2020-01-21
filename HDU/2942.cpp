#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		int num;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&num);
			a[num]++; 
		}
		int l=1,r=1000;
		int flag=1;
		while(l<=r&&a[l]==0){
			l++;
		}
		while(l<=r&&a[r]==0){
			r--;
		}
		if(n&1){
			flag=0;
		}
		int area=l+r;
		a[l]-=1;
		a[r]-=1;
		for(int i=2;i<=n/2;i++){
			while(l<=r&&a[l]==0){
				l++;
			}
//			if(a[l]&1){
//				flag=0;
//				break;
//			}
			while(l<=r&&a[r]==0){
				r--;
			}
//			if(a[r]&1){
//				flag=0;
//				break;
//			}
			if(area!=l+r){
				flag=0;
				break;
			}
			a[l]-=1;
			a[r]-=1;
		}
		if(flag)  printf("Yes\n");
		else  printf("No\n");
	}
	return 0;
} 
