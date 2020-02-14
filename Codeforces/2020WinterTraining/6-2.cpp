#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int num[15];
int flag;

int f(int n){
    memset(num,-1,sizeof num);
    int i=0;
    while(n){
        num[i]=n%10;
        n/=10;
        i++;
    }
    return i;
}

int getnum(){
    int len=-1;
    for(int i=0;i<15;i++){
        if(num[i]!=-1){
            len=i;
        }
    }
    if(num[len]==0)  return -1;
    int i=len,res=0;
    while(i>=0){
        if(num[i]==-1){
            i--;
            continue;
        }
        res*=10;
        res+=num[i];
        i--;
    }
    return res;
}

void dfs(int index,int cnt){
    int nn=getnum();
    if(nn==-1)  return;
    int tmp=sqrt(nn);
    if(tmp*tmp==nn)  flag=min(flag,cnt);
    if(index<0)  return;
    int tt=num[index];
    num[index]=-1;
    dfs(index-1,cnt+1);
    num[index]=tt;
    dfs(index-1,cnt);
}

int main() {
    int n;
    scanf("%d",&n);
    int len=f(n);
    flag=0x3f3f3f3f;
    dfs(len-1,0);
    printf("%d\n",flag==0x3f3f3f3f?-1:flag);
    return 0;
}