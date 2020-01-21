#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

const ll mod=1e9+7;

ll power(ll a,ll b,ll p){
	ll ans=1%p;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%p;
		a=a*a%p;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum=(sum+power(i,k,mod))%mod;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
