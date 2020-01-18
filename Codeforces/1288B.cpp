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
    scanf("%d",&t);
    ll a,b;
    while(t--){
        scanf("%I64d%I64d",&a,&b);
        ll tmp=9,cnt=0;
        while(tmp<=b){
            tmp=tmp*10+9;
            cnt++;
        }
        printf("%I64d\n",cnt*a);
    }
    return 0;
}