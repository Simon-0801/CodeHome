#include<stdio.h>
#include<stdlib.h>
#include<iomanip>      // 字符串与数字进行转化要引用的库
#include<iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int e[10];

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}
int main(){
    e[0] = 1;
    for(int i=1; i<10; i++)
        e[i] = e[i-1]*10;
    string str;
    int tot;
    cin>>str>>tot;
    int k = str.find('.');      // 小数点的位置
    int cou = str.length()- 1 - k;   //得到小数的位数
    int lef=cou-tot;
    ll inte = atoll(str.substr(0, k).c_str());
    // str.substr(a, b)    从原字符串中得到下标a a+b之间长度为b的一段字符串
    // atoi(str.c_str()) 将str转化为整型数
    // 同样的函数还有 atof(), atoll() 分别是转化为float以及long long int
    ll deci = atoll(str.substr(k+1, str.length()).c_str());
    ll lefnum=atoll(str.substr(k+1,lef).c_str());
    deci-=lefnum;

    ll mu=0,zi=deci;
    int st=0;
    while(st<tot){
        mu*=10;
        mu+=9;
        st++;
    }
    st=0;
    while(st<lef){
        mu*=10;
        st++;
    }

    // zi=mu*inte+zi;

    ll g = __gcd(mu, zi);
    mu/=g;
    zi/=g;
    // int su = deci / g;
    // int sd = (e[cou]-1) / g;

    cout<<(mu*inte+zi)<<"/"<<(mu)<<endl;
}
