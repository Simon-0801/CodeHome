#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define INF 0x3f3f3f3f
#define mst(a,num) memset(a,num,sizeof a)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 500000 + 5;

int a[maxn],b[maxn];
ll cnt=0;

void merg(int l,int mid,int r){
    int i=l,j=mid+1;
    rep(k,l,r){
        if(j>r||i<=mid&&a[i]<=a[j])  b[k]=a[i],i++;
        else  b[k]=a[j],j++,cnt+=1ll*(mid-i+1);
    }
    rep(k,l,r){
        a[k]=b[k];
    }
}

void mergesort(int l,int r){
    if(l>=r)  return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merg(l,mid,r);
}

int main() {
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
    }
    cnt=0;
    mergesort(1,n);
    printf("%lld\n",cnt);
    return 0;
}