#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
 
 
 
int main() {
    int t,a,b,c,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&n);
        int sum=a+b+c+n;
        if(sum%3==0){
            sum/=3;
            if(sum>=a&&sum>=b&&sum>=c){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else printf("NO\n");
    }
    return 0;
}