#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int n,x,a,b;
    scanf("%d%d%d%d",&n,&x,&a,&b);
    double ans=n*((double)x/100.0*a+(100-x)/100.0*b);
    printf("%.2lf\n",ans);
    return 0;
}