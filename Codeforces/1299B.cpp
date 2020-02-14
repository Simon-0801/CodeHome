#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

struct node
{
    ll x,y;
}p[maxn];


int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
    }
    node pre=p[n];
    for(int i=1;i<=n;i++){
        node now=p[i];
        p[i].x-=pre.x;
        p[i].y-=pre.y;
        pre=now;
    }
    if(n&1)  printf("NO\n");
    else{
        int mid=n/2,flag=1;
        for(int i=1;i<=mid;i++){
            if(p[i].x!=-1*p[i+mid].x||p[i].y!=-1*p[i+mid].y){
                flag=0;
                break;
            }
        }
        if(flag)  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}