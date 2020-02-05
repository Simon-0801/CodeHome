#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int n,tmp;
    scanf("%d",&n);
    ll sum=(ll)n*(n+1)/2;
    for(int i=1;i<n;i++){
        scanf("%d",&tmp);
        sum-=tmp;
    }
    printf("%lld\n",sum);
    return 0;
}