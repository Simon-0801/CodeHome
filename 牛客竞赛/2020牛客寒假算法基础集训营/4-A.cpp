#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll Fib[105];

int main() {
    Fib[0]=0;
    Fib[1]=1;
    Fib[2]=2;
    for(int i=3;i<=100;i++){
        Fib[i]=Fib[i-1]+Fib[i-2];
    }
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",Fib[n]+Fib[n+1]);
    }
    return 0;
}