#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

// int num[maxn];

int main() {
    int t,n,num,sum,cnt;
    scanf("%d",&t);
    while(t--){
        sum=0,cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            sum+=num;
            if(num==0)  cnt++;
        }
        if(sum+cnt==0)  cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}