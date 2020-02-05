#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

char tab[30];
char a[maxn],b[maxn];
int nxt[maxn];
int extend[maxn];

map<char,char> mp;

void get_nxt(char b[]) 
{
    int len=strlen(b);
    nxt[0]=len;
    int i=0;
    while(i<len-1&&b[i]==b[i+1]) ++i;
    nxt[1]=i;
    i=1;
    for(int k=2;k<len;++k)
	{
        int p=i+nxt[i]-1;
        int L=nxt[k-i];
        if(k-1+L>=p) 
		{
            int j=(p-k+1)>0?(p-k+1):0;
            while(k+j<len&&b[k+j]==b[j]) ++j;
            nxt[k]=j;
            i=k;
        } 
		else nxt[k]=L;
    }
}
void get_extend(char a[],char b[]) //extend[i]保存以a[i]为起始的文本串与模式串的最大公共前缀长度 
{
    int i=0,j,po,alen=strlen(a),blen=strlen(b);
    get_nxt(b);
    while(a[i]==b[i]&&i<alen&&i<blen) i++;
    extend[0]=i;
    po=0;
    for(i=1;i<alen;i++) 
	{
        if(nxt[i-po]+i<extend[po]+po) extend[i]=nxt[i-po];
		else 
		{
            j=extend[po]+po-i;
            if(j<0) j=0;
            while(i+j<alen&&j<blen&&a[j+i]==b[j]) j++;
            extend[i]=j;
            po=i;
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",tab);
        scanf("%s",a);
        mp.clear();
        int alen=strlen(a);
        for(int i=0;i<strlen(tab);i++){
            mp[tab[i]]='a'+i;
        }
        for(int i=0;i<(alen+1)/2;i++){
            b[i]=mp[a[i]];
        }
        get_extend(a,b);
        
        int index=-1;
        for(int i=(alen+1)/2;i<alen;i++){
            if(extend[i]+i==alen){
                index=i;
                break;
            }
        }
        if(index==-1){
            for(int i=0;i<alen;i++){
                printf("%c",a[i]);
            }
            for(int i=0;i<alen;i++){
                printf("%c",mp[a[i]]);
            }
            printf("\n");
        }
        else{
            for(int i=0;i<index;i++){
                printf("%c",a[i]);
            }
            for(int i=0;i<index;i++){
                printf("%c",mp[a[i]]);
            }
            printf("\n");
        }
    }
    return 0;
}