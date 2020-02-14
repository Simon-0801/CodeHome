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
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
// const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;
const int LEN = 6;

char str[10];
int mod;
int num1[100],num2[100],sum[100];
int len2;

int Hash(char str[])
{
    int res = 0;
    for (int i = 0; i < LEN; i++)
    {
        res = (res * 26 + str[i] - 'a'); 
    }
    return res;
}

int getnum(int n){
    int index=0;
    while(n){
        num2[index]=n%26;
        n/=26;
        index++;
    }
    return index;
}

void trans(char a[]){
    for(int i=0;i<LEN;i++){
        num1[i]=str[i]-'a';
    }
}

int add(){
    int tmp=max(LEN,len2),jin=0;
    for(int i=0;i<tmp;i++){
        int tsum=num1[i]+num2[i]+jin;
        sum[i]=tsum%26;
        jin=tsum/26;
    }
    int index=tmp;
    while(jin){
        sum[index]=jin%26;
        jin/=26;
        index++;
    }
    return index;
}

int main() {
    while(scanf("%s %d",str,&mod)!=EOF){
        mst(num1,0);
        mst(num2,0);
        mst(sum,0);
        trans(str);
        reverse(num1,num1+LEN);
        len2=getnum(mod);
        int sumlen=add();
        if(sumlen>6)  printf("-1\n");
        else{
            for(int i=sumlen-1;i>=0;i--){
                char c=sum[i]+'a';
                printf("%c",c);
            }
            printf("\n");
        }
    }
    return 0;
}