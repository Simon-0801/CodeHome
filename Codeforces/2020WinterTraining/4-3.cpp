#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int num[35]={0,0,1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401,
22369621};

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main() {
    // for(int i=2;i<=30;i++){
    //     int tmp=(1<<i)-1;
    //     int ans=0;
    //     for(int j=1;j<tmp;j++){
    //         ans=max(ans,gcd(tmp^j,tmp&j));
    //     }
    //     printf("%d   %d\n",tmp,ans);
    // }
    int q,a;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&a);
        int tmp=log2(a+1);
        // for(int i=1;i<=25;i++){
        //     if(1<<i)
        // }
        if((1<<tmp)==a+1){
            printf("%d\n",num[tmp]);
        }
        else{
            printf("%d\n",((1<<(tmp+1))-1));
        }
    }
    return 0;
}