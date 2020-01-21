#include <bits/stdc++.h>

using namespace std;

int a[105];
int num[105];

int main(){
	int m;
	scanf("%d",&m);
	int n,k;
	while(m--){
		scanf("%d%d",&n,&k);
		int flag=1;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>n){
				flag=0;
			}
			else num[a[i]]++;
		}
		if(!flag){
			printf("Tom\n");
			continue;
		} 
		for(int i=n;i>=1;i--){
			if(num[i])  continue;
			int tmp=i,f=0;;
			while(tmp>=0){
				if(num[tmp]){
					num[tmp]--;
					f=1;
					break;
				}
				tmp-=k;
			}
			if(f==0){
				flag=0;
				break;
			}
		}
		if(flag)  printf("Jerry\n");
		else  printf("Tom\n"); 
	}
	return 0;
}
 
