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
const ll mod = 1e9 + 7;
const int maxn = 100000 + 5;

char a[50],b[50];

char mp[5][20]={"abcdefghi","jklmnopqr","stuvwxyz"};

bool check(int x,int y){
    if(x==0&&y<=8&&y>=0)  return true;
    if(x==1&&y<=8&&y>=0)  return true;
    if(x==2&&y<=7&&y>=0)  return true;
    return false;
}

// bool jud(int x,int y,char c){
//     if(mp[x][y]==c)  return true;
//     if(check(x,y+1))
// }

int main() {
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",a,b);
        int lena=strlen(a),lenb=strlen(b);
        string ta=a,tb=b;
        if(ta==tb){
            printf("1\n");
            continue;
        }
        if(lena==lenb){
            int f=1;

            rep(i,0,lena-1){
                int num=a[i]-'a';
                int x1=num/9,y1=num%9;
                num=b[i]-'a';
                int x2=num/9,y2=num%9;
                if(abs(x1-x2)<=1&&abs(y1-y2)<=1){
                    continue;
                }
                else{
                    f=0;
                    break;
                }
            }
            if(f)  printf("2\n");
            else  printf("3\n");
        }
        else{
            printf("3\n");
        }
    }
    return 0;
}