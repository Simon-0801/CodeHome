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
const int maxn = 100 + 5;

int a[maxn];

int main() {
    int n,sum=0;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sum/=n;
    int cnt=0;
    rep(i,2,n){
        if(a[i-1]>sum){
            a[i]+=a[i-1]-sum;
            cnt++;
        }
        else if(a[i-1]<sum){
            a[i]-=sum-a[i-1];
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}