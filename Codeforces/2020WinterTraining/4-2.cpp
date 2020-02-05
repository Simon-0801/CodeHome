#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 300000 + 5;

struct node
{
    ll num;
    int index;
}a[maxn];

int cmp(node a,node b){
    return a.num<b.num;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i].num);
        a[i].index=i;
    }
    sort(a+1,a+n+1,cmp);
    int tl=a[n].index,tr=a[n].index;
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=n-1;i>=1;i--){
        ll tmp1,tmp2;
        if(tl!=a[i].index){
            tmp1=a[i].num/(abs(tl-a[i].index));
        }
        if(tr!=a[i].index){
            tmp2=a[i].num/(abs(tr-a[i].index));
        }
        tl=min(tl,a[i].index);
        tr=max(tr,a[i].index);
        ans=min(ans,min(tmp1,tmp2));
    }
    printf("%I64d\n",ans);
    return 0;
}