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



int main() {
    int w,h,d;
    scanf("%d%d%d",&w,&h,&d);
    int p=(w+h);
    if(w<=d*2||h<=d*2){
        printf("0\n");
        return 0;
    }
    printf("%d\n",(w-d*2)*(h-d*2));
    // p=p-d;
    // int tmp;
    // // if(p&1){
    // //     tmp=(p-1)/2;
    // // }
    // // else{
    // //     tmp=p/2;
    // // }
    // if(tmp&1){
    //     int l=(tmp-1)/2,r=(tmp+1)/2;
    //     printf("%d\n",l*r);
    // }
    // else{
    //     int l=(tmp)/2,r=(tmp)/2;
    //     printf("%d\n",l*r);
    // }
    return 0;
}