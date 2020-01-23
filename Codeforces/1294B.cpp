#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

struct Point
{
    int x,y;
}p[maxn];

int cmp(Point a,Point b){
    if(a.x==b.x)  return a.y<b.y;
    return a.x<b.x;
}

// vector<char> v;

int main() {
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        // v.clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p+1,p+n+1,cmp);
        int flag=0;
        for(int i=2;i<=n;i++){
            if(p[i].x>p[i-1].x&&p[i].y<p[i-1].y){
                flag=1;
                break;
            }
        }
        if(flag)  printf("NO\n");
        else{
            printf("YES\n");
            for(int i=1;i<=p[1].x;i++){
                printf("R");
            }
            for(int j=1;j<=p[1].y;j++){
                printf("U");
            }
            for(int i=2;i<=n;i++){
                for(int l=p[i-1].x;l<p[i].x;l++){
                    printf("R");
                }
                for(int j=p[i-1].y;j<p[i].y;j++){
                    printf("U");
                }
            }
            printf("\n");
        }
    }
    return 0;
}