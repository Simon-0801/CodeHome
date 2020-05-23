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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100 + 5;

int a[maxn],b[maxn],c[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        rep(i,1,n){
            scanf("%d",a+i);
        }
        rep(i,1,n){
            scanf("%d",b+i);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int tot=0;
        rep(i,1,k){
            c[++tot]=a[i];
        }
        repd(i,n,n-k+1){
            c[++tot]=b[i];
        }
        sort(c+1,c+tot+1);
        int sum=0;
        rep(i,k+1,n){
            sum+=a[i];
        }
        rep(i,k+1,tot){
            sum+=c[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}