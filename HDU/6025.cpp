#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

#define ll long long
#define INF 0x3f3f3f3f

using namespace std;

const int maxn=100005;

ll a[maxn];
ll g1[maxn],g2[maxn];

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		set<ll> se;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		g1[1]=a[1];
		for(int i=2;i<=n;i++){
			g1[i]=gcd(g1[i-1],a[i]);
		}
		g2[n]=a[n];
		for(int i=n-1;i>=1;i--){
			g2[i]=gcd(g2[i+1],a[i]);
		}
		ll minn;
		minn=g2[2];
		minn=max(g1[n-1],minn);
		for(int i=2;i<=n-1;i++){
			minn=max(minn,gcd(g1[i-1],g2[i+1]));
		}
		printf("%lld\n",minn);
	}
	return 0;
}
