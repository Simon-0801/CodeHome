#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1500 + 5;

char ch[35];
char cmap[5]={'S','E','T'};
int num[maxn][35];
map<string,int> mp;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",ch);
        string s=ch;
        mp[s]=1;
        for(int j=0;j<k;j++){
            if(ch[j]=='S')  num[i][j]=0;
            else if(ch[j]=='E')  num[i][j]=1;
            else num[i][j]=2;
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int l=0;l<k;l++){
                if(num[i][l]==num[j][l]){
                    ch[l]=cmap[num[i][l]];
                }
                else{
                    int tmp=3-(num[i][l]+num[j][l]);
                    ch[l]=cmap[tmp];
                }
            }
            string s=ch;
            if(mp[s])  cnt++;
        }
    }
    printf("%I64d\n",cnt/3);
    return 0;
}