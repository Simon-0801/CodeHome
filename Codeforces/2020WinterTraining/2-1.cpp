#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int x,y,z,a,b,c;
    scanf("%d%d%d",&x,&y,&z);
    scanf("%d%d%d",&a,&b,&c);
    if(a>=x){
        if(a-x+b>=y){
            if(a-y+b+c-x>=z)  printf("YES\n");
            else  printf("NO\n");
        }
        else printf("NO\n");
    }
    else printf("NO\n");
    return 0;
}