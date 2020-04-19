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
const int maxn = 100000 + 5;

int a[maxn];
int n;

bool check(){
    rep(i,1,n){
        rep(j,1,n){
            if(i==j)  continue;
            rep(k,1,n){
                if(k==i||k==j)  continue;
                int tmp=abs(a[i]-a[j]);
                if(tmp%a[k]!=0){
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",a+i);
    }
    if(check()){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}