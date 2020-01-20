#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll x[maxn],y[maxn];

int main() {
    ll x0,y0,ax,ay,bx,by;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&x0,&y0,&ax,&ay,&bx,&by);
    ll xs,ys,t;
    scanf("%I64d%I64d%I64d",&xs,&ys,&t);
    x[0]=x0;
    y[0]=y0;
    ll tot=0;
    while(1){
        ll index=++tot;
        x[index]=x[index-1]*ax+bx;
        y[index]=y[index-1]*ay+by;
        if(x[index]-xs>t||y[index]-ys>t)  break;
    }
    ll mmax=0;
    for(int i=0;i<tot;i++){
        for(int j=0;j<tot;j++){
            if(abs(x[i]-xs)+abs(y[i]-ys)+abs(x[i]-x[j])+abs(y[i]-y[j])<=t){
                mmax=max(mmax,(ll)abs(i-j)+1);
            }
        }
    }
    printf("%I64d\n",mmax);
    return 0;
}