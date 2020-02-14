#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll num[maxn<<1];

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n*2;i++){
            scanf("%lld",&num[i]);
        }
        sort(num+1,num+1+2*n);
        printf("%lld\n",num[n+1]-num[n]);
    }
    return 0;
}