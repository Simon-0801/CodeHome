#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

ll a[maxn],k[maxn];

int main() {
    int n,q;
    scanf("%d%d",&n,&q);
    a[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        a[i]=a[i-1]+a[i];
    }
    k[0]=0;
    for(int i=1;i<=q;i++){
        scanf("%I64d",&k[i]);
    }
    ll pre=0;
    for(int i=1;i<=q;i++){
        ll tmp=k[i]+pre;
        int index=lower_bound(a+1,a+n+1,tmp)-a;
        if(index>n){
            printf("%d\n",n);
            pre=0;
        }
        else{
            if(a[index]==tmp){
                if(index==n){
                    printf("%d\n",n);
                    pre=0;
                }
                else{
                    printf("%d\n",n-index);;
                    pre=tmp;
                }
            }  
            else{
                printf("%d\n",n-index+1);
                pre=tmp;
            }
        }
    }
    return 0;
}