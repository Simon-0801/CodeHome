#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 10000000;

int vis[maxn+5];

int main() {
    int n,ansi,ansj;
    scanf("%d",&n);
    ll a,minlcm=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a);
        if(vis[a]&&minlcm>a){
            minlcm=a;
            ansi=vis[a];
            ansj=i;
        }
        vis[a]=i;
    }
    for(ll i=1;i<=maxn;i++){
        ll tmp=0;
        for(ll j=i;j<=maxn;j+=i){
            if(vis[j]){
                if(tmp==0)  tmp=j;
                else{
                    if(minlcm>tmp*j/i){
                        minlcm=tmp*j/i;
                        ansi=vis[tmp];
                        ansj=vis[j];
                    }
                }
            }
        }
    }
    printf("%d %d\n",min(ansi,ansj),max(ansi,ansj));
    return 0;
}