#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

ll h[maxn],num[maxn];

int main() {
    ll n,a,b,k;
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&k);
    for(ll i=1;i<=n;i++){
        scanf("%I64d",&h[i]);
    }
    for(ll i=1;i<=n;i++){
        ll tmp=h[i]%(a+b);
        // if(tmp==0){
        //     if(%a==0){
        //         num[i]=tmp/a-1;
        //     }
        //     else{
        //         num[i]=tmp/a;
        //     }
        // }
        if(tmp==0)  tmp=a+b;
        if(tmp%a==0){
            num[i]=tmp/a-1;
        }
        else{
            num[i]=tmp/a;
        }
    }
    sort(num+1,num+n+1);
    num[0]=0;
    for(ll i=1;i<=n;i++){
        num[i]=num[i-1]+num[i];
    }
    ll ans=n;
    for(ll i=1;i<=n;i++){
        if(num[i]>k){
            ans=i-1;
            break;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}