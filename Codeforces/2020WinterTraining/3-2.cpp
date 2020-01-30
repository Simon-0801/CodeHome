#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;
const ll mod = 998244353;

char str[maxn];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    ll index=1,ans=1;
    for(int i=2;i<=n;i++){
        if(str[i]!=str[i-1]){
            index=i-1;
            break;
        }
    }
    ans=(ans+index)%mod;
    index=1;
    for(int i=n-1;i>=1;i--){
        if(str[i]!=str[i+1]){
            index=n-i;
            break;
        }
    }
    ans=(ans+index)%mod;
    if(str[1]==str[n]){
        char c=str[1];
        ll l=0,r=0;
        for(int i=1;i<=n;i++){
            if(str[i]==c){
                l++;
            }
            else{
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(str[i]==c){
                r++;
            }
            else{
                break;
            }
        }
        ans=(ans+l*r%mod)%mod;
    }
    printf("%I64d\n",ans%mod);
    return 0;
}