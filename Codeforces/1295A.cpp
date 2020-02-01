#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
	int t;
	int n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int num = n/2;
		string ss = string(num,'1');
		if(n%2)
			ss[0] = '7';
		cout<<ss<<endl;
	}
	return 0;
}