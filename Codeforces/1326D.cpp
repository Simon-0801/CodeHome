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
const int maxn = 1e6 + 5;

char a[maxn],b[maxn];
char s[maxn];
int slen;
char s_new[maxn*2];
int p[maxn*2];
int nxt[maxn];
int n;
 
//KMP计算字符串自身的next数组
void cal_nxt(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&a[i]!=a[j+1])  j=nxt[j];
        if(a[i]==a[j+1])  j++;
        nxt[i]=j;
    }
}

int Init() {//形成新的字符串 
    int len=strlen(s);//len是输入字符串的长度
    slen=len;
    s_new[0]='$';//处理边界，防止越界 
    s_new[1]='#';
    int j=2; 
    for(int i=0;i<len;i++) {
        s_new[j++]=s[i];
        s_new[j++]='#';
    } 
    s_new[j]='\0';//处理边界，防止越界（容易忘记） 
    return j;// 返回s_new的长度 
}

int Manacher() {//返回最长回文串 
    int len=Init();//取得新字符串的长度， 完成向s_new的转换
    int max_len=-1;//最长回文长度
    int id;
    int mx=0;
    for(int i=1;i<=len;i++) {
        if(i<mx)
            p[i]=min(p[2*id-i],mx-i);//上面图片就是这里的讲解 
        else p[i]=1;
        while(s_new[i-p[i]]==s_new[i+p[i]])//不需边界判断，因为左有'$'，右有'\0'标记；
            p[i]++;//mx对此回文中点的贡献已经结束，现在是正常寻找扩大半径
        if(mx<i+p[i]) {//每走移动一个回文中点，都要和mx比较，使mx是最大，提高p[i]=min(p[2*id-i],mx-i)效率 
            id=i;//更新id 
            mx=i+p[i];//更新mx 
        }
        max_len=max(max_len,p[i]-1); 
    } 
    return max_len; 
}

bool chk(int l, int r) {
    int mid = (l * 2 + r * 2) >> 1;
    return p[mid] - 1 >= r - l + 1;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        // mst(a,0);
        // mst(b,0);
        // mst(p,0);
        // mst(s_new,0);
        // mst(s,0);
        scanf("%s",a+1);
        n=strlen(a+1);
        int l = 1, r = n;
        while(l <= r && a[l] == a[r]) ++l, --r;
        if(l > r) {
            cout << (a + 1) << '\n';
            continue;   
        }
        // strcpy(b,a+1);
        // reverse(b,b+n);
        // int tmpl=n;
        // rep(i,1,n){
        //     if(a[i]!=b[i-1]){
        //         tmpl=i-1;
        //         break;
        //     }
        // }
        // if(tmpl>n/2){
        //     tmpl=n/2;
        // }
        // if(tmpl>=n/2){
        //     printf("%s\n",a+1);
        //     continue;
        // }
        // cal_nxt();
        for(int i = l; i <= r; i++) s[i - l] = a[i];
        s[r - l + 1] = '\0';
        // strncpy(s,a+l,r-l+1);
        // printf("%s\n",s);
        Manacher();
        int tmaxl=0,tmaxr=0;
        rep(i,0,slen-1){
            if(chk(1,i+1)){
                if(i+1>tmaxl){
                    tmaxl=i+1;
                }
            }
            if(chk(i+1,slen)){
                if(slen-i>tmaxr){
                    tmaxr=slen-i;
                }
            }
            // if(i&1){
            //     int tmp=p[i]-1;
            //     tmp>>=1;
            //     if(tmp==i/2){
            //         tmaxl=max(tmaxl,tmp*2);
            //     }
            // }
            // else{
            //     int tmp=p[i]-1;
            //     tmp>>=1;
            //     if(tmp==i/2-1){
            //         tmaxl=max(tmaxl,tmp*2+1);
            //     }
            // }
        }
        // rep(i,2,slen*2){
        //     if(i&1){
        //         int tmp=p[i]-1;
        //         tmp>>=1;
        //         if(tmp+i/2==slen){
        //             tmaxr=max(tmaxr,tmp*2);
        //         }
        //     }
        //     else{
        //         int tmp=p[i]-1;
        //         tmp>>=1;
        //         if(tmp+i/2==slen){
        //             tmaxr=max(tmaxr,tmp*2+1);
        //         }
        //     }
        // }
        l--,r++;;
        if(tmaxl>tmaxr){
            l=tmaxl+l;
            // printf("%d %d\n",l,r);
            rep(i,1,l){
                printf("%c",a[i]);
            }
            rep(i,r,n){
                printf("%c",a[i]);
            }
            printf("\n");
        }
        else{
            r=r-tmaxr;
            // printf("%d %d\n",l,r);
            rep(i,1,l){
                printf("%c",a[i]);
            }
            rep(i,r,n){
                printf("%c",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}