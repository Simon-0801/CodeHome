#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 500 + 5;

struct node
{
    int x,y;
}p[maxn];


int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i)  continue;
            node a;
            a.x=(p[j].x-p[i].x);
            a.y=(p[j].y-p[i].y);
            for(int k=j+1;k<=n;k++){
                if(k==i||k==j)  continue;
                node b;
                b.x=(p[k].x-p[i].x);
                b.y=(p[k].y-p[i].y);
                if(a.x*b.x+a.y*b.y<0&&a.x*b.y!=a.y*b.x)  cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}