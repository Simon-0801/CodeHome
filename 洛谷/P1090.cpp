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
const int maxn = 10000 + 5;

int a[maxn];
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        pq.push(a[i]);
    }
    int ans=0;
    if(n==1){
        printf("%d\n",a[1]);
        return 0;
    }
    n--;
    while(n--){
        int tmp1,tmp2;
        tmp1=pq.top();
        pq.pop();
        tmp2=pq.top();
        pq.pop();
        ans+=tmp1+tmp2;
        pq.push(tmp1+tmp2);
    }
    printf("%d\n",ans);
    return 0;
}