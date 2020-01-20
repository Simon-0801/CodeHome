#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int n;
    scanf("%d",&n);
    double sum=0;
    for(int i=1;i<=n;i++){
        sum+=1.0/i;
    }
    printf("%.12f\n",sum);
    return 0;
}