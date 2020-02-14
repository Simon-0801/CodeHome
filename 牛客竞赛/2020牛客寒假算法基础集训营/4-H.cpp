#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <cstdio> 
#include <map> 
#include <iomanip>
 
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
//#define INF 0x3f3f3f3f
 
using namespace std;
 
const int maxn=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
 
ll col[maxn],l[maxn],r[maxn];
ll lsum[maxn],rsum[maxn];
ll t[maxn];

void update(int x,ll num){
    for(;x<maxn;x+=(x&-x))  t[x]+=num;
}
 
ll query(int x){
    ll ans=0;
    for(;x;x-=(x&-x))  ans+=t[x];
    return ans;
}
 
int main(){
	int n;
    scanf("%d",&n);
    memset(rsum,0,sizeof rsum);
    memset(lsum,0,sizeof lsum);
    // ll tmax=0,tmin=5e5+5;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&col[i],&l[i],&r[i]);
        rsum[col[i]]++;
        // tmax=max(tmax,col[i]);
        // tmin=min(tmin,col[i]);
    }
    memset(t,0,sizeof t);
    // col[0]=0;
    // build(1,tmin,tmax);
    for(int i=1;i<=n;i++){
        ll pre=rsum[col[i]]*lsum[col[i]];
        rsum[col[i]]--;
        update(col[i],rsum[col[i]]*lsum[col[i]]-pre);
        if(i>1){
            pre=rsum[col[i-1]]*lsum[col[i-1]];
            lsum[col[i-1]]++;
            update(col[i-1],rsum[col[i-1]]*lsum[col[i-1]]-pre);
        }
        ll ans=query(r[i])-query(l[i]-1);
        printf("%lld%c",ans,i==n?'\n':' ');
    }
	return 0;
}