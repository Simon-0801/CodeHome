#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

struct node
{
    int cnt2,cnt3,index;
}p[maxn];

int cmp(node a,node b){
    if(a.cnt3==b.cnt3)  return a.cnt2<b.cnt2;
    return a.cnt3>b.cnt3;
}


ll num[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&num[i]);
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        ll tmp=num[i];
        while(tmp%3==0){
            cnt++;
            tmp/=3;
        }
        p[i].cnt3=cnt;
        cnt=0;
        tmp=num[i];
        while(tmp%2==0){
            cnt++;
            tmp/=2;
        }
        p[i].cnt2=cnt;
        p[i].index=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        printf("%I64d%c",num[p[i].index],i==n?'\n':' ');
    }
    return 0;
}