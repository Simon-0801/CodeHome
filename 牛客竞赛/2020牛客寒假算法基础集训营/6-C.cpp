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
const int maxn = 100000 + 5;

struct node
{
    int x,y,id;
    bool operator< (const node&a)const{
        return x>a.x;
    }
}p[maxn];

int dp[maxn],ans[maxn];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
        p[i].id=i;
    }
    sort(p+1,p+n+1);    //按照Xi从大到小排序
    int len=1;
    dp[1]=p[1].y;   //初始化dp[1]
    ans[p[1].id]=1;     //放入第1组
    for(int i=2;i<=n;i++){
        int l=1,r=len,res;
        if(dp[len]<p[i].y){     //自成一组
            len++;
            dp[len]=p[i].y;
            ans[p[i].id]=len;
            continue;
        }
        while(l<=r){        //二分查找dp数组中比p[i].y大的最小数
            int mid=(l+r)/2;
            if(dp[mid]>=p[i].y)  r=mid-1,res=mid;
            else  l=mid+1;
        }
        dp[res]=p[i].y;     //更新dp数组
        ans[p[i].id]=res;       //放入第res组
    }
    printf("%d\n",len);
    for(int i=1;i<=n;i++)  printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}