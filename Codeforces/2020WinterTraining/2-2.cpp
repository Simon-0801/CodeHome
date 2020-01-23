#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 5;

ll num[maxn],cp[maxn];
map<ll,int> mp;


int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&num[i]);
        cp[i]=num[i];
    }
    sort(num+1,num+1+n);
    ll sum=0;
    for(int i=1;i<=m*k;i++){
        mp[num[n-i+1]]++;
        sum+=num[n-i+1];
    }
    printf("%I64d\n",sum);
    int cnt=0;
    k--;
    for(int i=1;i<=n;i++){
        if(mp[cp[i]]){
            mp[cp[i]]--;
            cnt++;
        }
        if(cnt==m){
            printf("%d",i);
            cnt=0;
            k--;
            if(k)  printf(" ");
            else{
                printf("\n");
                break;
            }
        }
    }
    return 0;
}