#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

long long getnum(long long v, ll n){
	long long ans = 0;
	long long d = 1;
	while(v <= n){
		ans += min(d,n-v+1);
		v *= 2;
		d *= 2;
	}
	return ans;
}

// ll getnum(ll num,ll n){
//     ll t1=(ll)log2(n)+1;
//     ll t2=(ll)log2(num)+1;
//     ll res=(1<<(t1-t2))-1;
//     ll tmp=(n>>(t1-t2));
//     if(tmp<num){
//         return res;
//     }
//     else{
//         return (((1<<(t1-t2))-1)&n)+1+res;
//     }
// }


int main(){
    int t;
    // scanf("%d",&t);
    // while(t--){
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll l=0,r=(n-1)/2,mid;
        ll tmax=1;
        while(l<=r){
            mid=(l+r)>>1;
            ll tmp=getnum(mid*2+1,n);
            if(tmp>=k){
                l=mid+1;
                tmax=max(tmax,mid*2+1);
            }
            else{
                r=mid-1;
            }
        }
        l=1,r=n/2;
        while(l<=r){
            mid=(l+r)>>1;
            ll tmp=getnum(mid*2,n)+getnum(mid*2+1,n);
            if(tmp>=k){
                l=mid+1;
                tmax=max(tmax,mid*2);
            }
            else{
                r=mid-1;
            }
        }
        printf("%lld\n",tmax);
    // }
    return 0;
}