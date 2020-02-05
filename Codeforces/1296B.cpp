#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int t;
    ll s,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&s);
        ans=0;
        while(s>=10){
            ll tmp=s/10;
            ans+=tmp*10;
            s-=tmp*10;
            s+=tmp;
        }
        ans+=s;
        printf("%I64d\n",ans);
    }
    return 0;
}