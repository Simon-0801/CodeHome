#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

int num[maxn];

int main() {
    int n;
    scanf("%d",&n);
    num[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        num[i]=num[i-1]+num[i];
    }
    int tmp,ans=1;
    if(num[n]&1)  tmp=(num[n]+1)/2;
    else tmp=num[n]/2;
    for(int i=1;i<=n;i++){
        if(num[i]>=tmp){
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}