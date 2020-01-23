#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 4e5 + 5;

int num[maxn] = {0};

int main() {
	int q,x;
	scanf("%d%d",&q,&x);
	int y;
	int re;
	int tmp = 0;
	int fl = 0;
	for(int i=0; i<q; i++) {
		scanf("%d",&y);
		re = y % x;
		num[re]++;
		if(tmp == re) {
			int p = re;
			while(p < x && num[p] >= num[re]) p++;

			if(p == x) {
				p = 0;
				while(p<=re && num[p] > num[re]) p++;
			}
			tmp = p;
			cout<<num[p] * x + p <<endl;
		} else {
			cout<<num[tmp] * x + tmp <<endl;
		}
	}

}