#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll c[maxn],t[maxn];
ll d[maxn],s[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&c[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%I64d",&t[i]);
    }
    if(c[1]!=t[1]||c[n]!=t[n]){
        printf("No\n");
        return 0;
    }
    for(int i=1;i<n;i++){
        d[i]=c[i+1]-c[i];
        s[i]=t[i+1]-t[i];
    }
    sort(d+1,d+n);
    sort(s+1,s+n);
    int flag=1;
    for(int i=1;i<n;i++){
        if(d[i]!=s[i]){
            flag=0;
            break;
        }
    }
    if(flag)  printf("Yes\n");
    else printf("No\n");
    return 0;
}