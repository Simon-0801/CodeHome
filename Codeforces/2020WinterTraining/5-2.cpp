#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

struct node
{
    int i,j;
};

vector<node> v;
ll num[maxn];

int main() {
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    ll mul = n/m; //n有多少个m 
	ll res = n - m*mul;
	
	for(int i=0;i<m;i++)
		num[i] = mul;
	for(int i=1;i<=res;i++)
		++num[i];
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            if((i*i+j*j)%m==0){
                node tmp;
                tmp.i=i;
                tmp.j=j;
                if(i==j){
                    v.push_back(tmp);
                }
                else{
                    v.push_back(tmp);
                    tmp.i=j;
                    tmp.j=i;
                    v.push_back(tmp);
                }
            }
        }
    }
    int len=v.size();
    ll ans=0;
    for(int i=0;i<len;i++){
        // ll tmp1=(n-v[i].i)/m,tmp2=(n-v[i].j)/m;
        ans+=num[v[i].i]*num[v[i].j];
    }
    printf("%I64d\n",ans);
    return 0;
}