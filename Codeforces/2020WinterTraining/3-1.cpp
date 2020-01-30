#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

char str[maxn];

bool check(char c){
    if(c=='a'||c=='o'||c=='u'||c=='i'||c=='e')  return false;
    return true;
}

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    int flag=1;
    for(int i=1;i<=len;i++){
        if(check(str[i])){
            if(str[i]=='n')  continue;
            if(i+1>len){
                flag=0;
                break;
            }
            else if(check(str[i+1])){
                flag=0;
                break;
            }
        }
    }
    if(flag)  printf("YES\n");
    else printf("NO\n");
    return 0;
}