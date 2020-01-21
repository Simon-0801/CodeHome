#include <bits/stdc++.h>

using namespace std;

char s1[10],s2[10];

int getnum(char str[],int i,int j){
	int res=0;
	for(int l=i;l<=j;l++){
		res=res*10+str[l]-'0'; 
	}
	return res;
}

int main(){
	int n;
	scanf("%d",&n);
	int cas=0;
	getchar();
	while(n--){
		++cas;
		scanf("%s %s",&s1,&s2);
		printf("Case %d: ",cas);
		if(s1[0]==s2[0])  printf("= ");
		else if(s1[0]>s2[0])  printf("> ");
		else  printf("< ");
		if(s1[1]!=s2[1]){
			int flag=0;
			if(s1[2]>s2[2])  flag=1;
			else if(s1[2]<s2[2])  flag=-1;
			else{
				int num1=getnum(s1,3,4),num2=getnum(s2,3,4);
//				cout<<"1"<<num1<<" "<<num2<<endl;
				if(num1>num2)  flag=1;
				else if(num1<num2)  flag=-1;
				else flag=0;
			}
			if(flag==1)  printf(">\n");
			else if(flag==-1)  printf("<\n");
			else  printf("=\n");
		}
		else{
			int flag=0;
			if(s1[2]>s2[2])  flag=1;
			else if(s1[2]<s2[2])  flag=-1;
			else{
				int num1=getnum(s1,3,4),num2=getnum(s2,3,4);
//				cout<<"2"<<num1<<" "<<num2<<endl;
				if(num1>num2)  flag=1;
				else if(num1<num2)  flag=-1;
				else{
					if(s1[5]>s2[5])  flag=1;
					else if(s1[5]<s2[5])  flag=-1;
					else flag=0;
				}
			}
			if(flag==1)  printf(">\n");
			else if(flag==-1)  printf("<\n");
			else  printf("=\n");
		}
	}
	return 0;
}
