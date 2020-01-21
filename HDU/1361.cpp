#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int st[50];

int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		int l;
		int top=0;
		int pre=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			for(int j=1;j<=l-pre;j++){
				st[++top]=1;
			}
			st[++top]=2;
			pre=l;
		} 
		stack<int> s;
		for(int i=top;i>=1;i--){
			if(st[i]==1)  continue;
			int rcnt=0;
			int lcnt=0;
			for(int j=i;j>=1;j--){
				if(st[j]==1)  lcnt++;
				if(st[j]==2)  rcnt++;
				if(lcnt==rcnt){
					s.push(rcnt);
					break;
				}
			}
		}
		int len=s.size();
		while(len--){
			printf("%d%c",s.top(),len==0?'\n':' ');
			s.pop();
		}
	}
	return 0;
} 
