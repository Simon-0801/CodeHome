#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 5;

ll num[maxn];
int p[maxn],c[maxn];
int m;

void getcnt(int n){
    m=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            p[++m]=i;
            c[m]=0;
            while(n%i==0){
                n/=i;
                c[m]++;
            }
        }
    }
    if(n>1){
        p[++m]=n;
        c[m]=1;
    }
    num[n]=1;
    for(int i=1;i<=m;i++){
        num[n]*=(2*c[i]+1);
    }
}

ll ret(ll x)
{
	ll ans = 2;
	if(x == 1) return 1;
	for(ll i = 2; i <= sqrt(x); i++)
	{
		if(x % i == 0)
		{
			ans++;
			if(i != x/i) ans++;
		}
	}
	return ans;
}

int main() {
    ll n;
    scanf("%lld",&n);
    ll mx=sqrt(n);
    for(ll i=1;i<=mx;i++){
        num[i]=i*i;
    }
    ll ans=0;
    for(ll i=1;i<=mx;i++){
        ans+=ret(num[i]);
    }
    printf("%lld\n",ans);
    return 0;
}