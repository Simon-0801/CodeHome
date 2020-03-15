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
const int maxn = 40000 + 5;

int phi[maxn];

void euler(int n){
    rep(i,2,n)  phi[i]=i;
    rep(i,2,n){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

int main() {
    int n;scanf("%d",&n);
    if(n==1){
        printf("0\n");
        return 0;
    }
    euler(n);
    int sum=0;
    rep(i,2,n-1)  sum+=phi[i];
    printf("%d\n",sum*2+3);
    return 0;
}