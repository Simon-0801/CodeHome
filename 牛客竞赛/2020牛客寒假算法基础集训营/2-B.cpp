#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

char str[maxn];

int main() {
    int n,cnt1=0,cnt6=0;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='6')  cnt6++;
        if(str[i]=='1')  cnt1++;
    }
    if(cnt6>=2&&cnt1>=1)  printf("%d\n",min(cnt6-1,cnt1));
    else  printf("0\n");
    return 0;
}