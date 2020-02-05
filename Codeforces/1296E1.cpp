#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

int l[205];
int r[205];


int main() {
	int n;
	scanf("%d",&n);
	string str;
	cin>>str;
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	for(int i=0; i<n; i++) {
		for(int j=0;j<i;j++)
		{
			if(str[j] > str[i])
			{
				l[i] = j;
				break;
			}
		}
		for(int j=n-1;j>i;j--)
		{
			if(str[i] > str[j])
			{
				r[i] = j;
				break;
			}
		}
		if(r[i] != -1&& l[i] != -1)
		{
			printf("NO\n");
			return 0;
		}
	}
	string ans = string(n,'0');
	for(int i=1;i<n;i++)
	{
		if(l[i] != -1)
		{
			ans[i] = '1';
		}
	}
	printf("YES\n");
	cout<<ans<<endl;
	return 0;
}