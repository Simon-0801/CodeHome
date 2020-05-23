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
const int maxn = 100000 + 5;

int t[10];

int main() {
    int sum=0;
    rep(i,1,4){
        int x,y;
        scanf("%d.%d",&x,&y);
        t[i]=x*100+y;
        sum+=t[i];
    }
    sort(t+1,t+5);
    int fin,x,y;
    scanf("%d.%d",&x,&y);
    fin=x*100+y;
    if((sum-t[1])<=3*fin){
        printf("infinite\n");
        return 0;
    }
    else if(sum-t[4]>3*fin){
        printf("impossible\n");
        return 0;
    }
    else{
        int tmp=fin*3-sum+t[1]+t[4];
        printf("%d.",tmp/100);
        tmp=tmp%100;
        if(tmp<10) printf("0%d",tmp);
        else printf("%d",tmp);
        puts("");
    }
    // double tmp=3.0*fin-sum+t[1]+t[4];
    // if(tmp>=t[1]&&tmp<=t[4]){
    //     printf("%.2lf\n",tmp);
    //     return 0;
    // }
    // if(sum-t[4]<=3.0*fin){
    //     printf("%.2lf\n",t[1]);
    //     return 0;
    // }
    // printf("impossible\n");
    return 0;
}