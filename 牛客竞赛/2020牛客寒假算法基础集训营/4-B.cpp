#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;

char str[maxn];
vector<char> v;

int main() {
    scanf("%s",str+1);
    int len=strlen(str+1);
    if(len==0){
        printf("Yes\n");
        return 0;
    }
    int flag=1;
    for(int i=1;i<=len;i++){
        if(str[i]=='['||str[i]=='('||str[i]=='{'){
            v.push_back(str[i]);
        }
        else{
            if(v.size()==0){
                flag=0;
                break;
            }
            else{
                char tmp=v.back();
                if((str[i]==']'&&tmp!='[')||(str[i]==')'&&tmp!='(')||(str[i]=='}'&&tmp!='{')){
                    flag=0;
                    break;
                }
                v.pop_back();
            }
        }
    }
    if(flag&&v.size()==0)  printf("Yes\n");
    else printf("No\n");
    return 0;
}