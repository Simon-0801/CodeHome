#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;



int main() {
    int t,n,tmp,odd,even;
    scanf("%d",&t);
    while (t--){
        odd=0;
        even=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp);
            if(tmp&1)  odd++;
            else  even++;
        }
        if(odd==0){
            printf("NO\n");
        }
        else if(even==0&&n%2==0){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    
    return 0;
}