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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const ll mod = 1e9 + 7;
const int maxn = 200000 + 5;

char str[maxn];
int a[maxn],b[maxn];

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)  a[i]=i,b[i]=n-i+1;
        int i=1,j=1;
        while(i<n&&j<n){
            while(j<n&&str[i]==str[j])  j++;
            if(str[i]=='>')  reverse(a+i,a+j+1);
            else  reverse(b+i,b+j+1);
            i=j;
        }
        for(int i=1;i<=n;i++)  printf("%d%c",b[i],i==n?'\n':' ');
        for(int i=1;i<=n;i++)  printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}