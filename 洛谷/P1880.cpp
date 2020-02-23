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
const int maxn = 200 + 5;

int n;
int a[maxn],sum[maxn];
int dpmax[maxn][maxn],dpmin[maxn][maxn];

int main() {
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    sum[0]=0;
    rep(i,1,2*n){
        // dpmax[i][i]=dpmin[i][i]=a[i];
        sum[i]=sum[i-1]+a[i];
    }
    rep(len,2,n){
        rep(l,1,2*n+1-len){
            int r=l+len-1;
            // if(len==2){
            //     dpmax[l][r]=dpmax[l][l]+dpmax[r][r];
            //     dpmin[l][r]=dpmin[l][l]+dpmin[r][r];
            //     continue;
            // }
            // dpmax[l][r]=dpmax[l][l]+dpmax[l+1][r]+sum[r]-sum[l-1];
            // dpmin[l][r]=dpmin[l][l]+dpmin[l+1][r]+sum[r]-sum[l-1];
            dpmin[l][r]=INF;
            rep(k,l+1,r){
                dpmax[l][r]=max(dpmax[l][k-1]+dpmax[k][r]+sum[r]-sum[l-1],dpmax[l][r]);
                dpmin[l][r]=min(dpmin[l][k-1]+dpmin[k][r]+sum[r]-sum[l-1],dpmin[l][r]);
            }
        }
    }
    int maxans=-1,minans=INF;
    rep(i,1,n){
        maxans=max(maxans,dpmax[i][i+n-1]);
        minans=min(minans,dpmin[i][i+n-1]);
    }
    printf("%d\n%d\n",minans,maxans);
    return 0;
}