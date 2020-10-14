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
typedef vector<int> VI;
const ll mod = 1e9 + 7;
const int maxn = 100 + 5;

char dic[maxn][25];
char str[25];

bool omit(int id){
    int len=strlen(str+1);
    int dlen=strlen(dic[id]+1);
    if(dlen!=len+1)  return false;
    int i=1,j=1;
    while(i<=dlen&&j<=len){
        if(dic[id][i]!=str[j])  break;
        i++,j++;
    }
    if(j>len)  return true;
    i++;
    while(i<=dlen&&j<=len){
        if(dic[id][i]!=str[j])  return false;
        i++,j++;
    }
    return true;
}

bool ad(int id){
    int len=strlen(str+1);
    int dlen=strlen(dic[id]+1);
    if(dlen!=len-1)  return false;
    int i=1,j=1;
    while(i<=dlen&&j<=len){
        if(dic[id][i]!=str[j])  break;
        i++,j++;
    }
    if(i>dlen)  return true;
    j++;
    while(i<=dlen&&j<=len){
        if(dic[id][i]!=str[j])  return false;
        i++,j++;
    }
    return true;
}

bool differ(int id){
    int len=strlen(str+1);
    int dlen=strlen(dic[id]+1);
    if(dlen!=len)  return false;
    int cnt=0;
    rep(i,1,len){
        if(dic[id][i]!=str[i]){
            cnt++;
        }
    }
    if(cnt==1)   return true;
    else  return false;
}

bool trans(int id){
    int len=strlen(str+1);
    int dlen=strlen(dic[id]+1);
    if(dlen!=len)  return false;
    int fi=-1,se=-1;
    rep(i,1,len){
        if(dic[id][i]!=str[i]){
            if(fi==-1){
                fi=i;
            }
            else if(se==-1){
                se=i;
            }
            else{
                return false;
            }
        }
    }
    if(fi+1==se&&dic[id][fi]==str[se]&&dic[id][se]==str[fi]){
        return true;
    }
    else  return false;
}

int main() {
    int d,n;
    scanf("%d",&d);
    rep(i,1,d){
        scanf("%s",dic[i]+1);
    }
    scanf("%d",&n);
    rep(cas,1,n){
        scanf("%s",str+1);
        printf("%s\n",str+1);
        int f=0;
        rep(i,1,d){
            if(strcmp(str+1,dic[i]+1)==0){
                f=1;
                break;
            }
        }
        if(f){
            printf("CORRECT\n\n");
            continue;
        }
        rep(i,1,d){
            if(omit(i)){
                f=1;
                printf("ONE LETTER OMITTED FROM %s\n",dic[i]+1);
            }
            else if(ad(i)){
                f=1;
                printf("ONE LETTER ADDED TO %s\n",dic[i]+1);
            }
            else if(differ(i)){
                f=1;
                printf("ONE LETTER DIFFERENT FROM %s\n",dic[i]+1);
            }
            else if(trans(i)){
                f=1;
                printf("TWO LETTERS TRANSPOSED IN %s\n",dic[i]+1);
            }
        }
        if(f==0)  printf("UNKNOWN\n");
        printf("\n");
    }
    return 0;
}