#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int N = 10000010;
const int M = 100010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;
const double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}
template<class T> inline void swap(T& a, T& b){T c(a); a = b; b = c;}

//end

int main(){
//    char buffer[200];
    string seekword = "marshtomp", replaceword = "fjxmlhx", str1,str2;
//    char seekchar[20];
//    char replacechar[20];
    
    //输入长英文句子，带空格  getline(cin, str1)
    while (getline(cin, str1)){
        str2 = str1;                            //str2 为小写字符串
//        strcpy(seekchar, seekword.c_str());
//        strcpy(replacechar, replaceword.c_str());
        int seeklengh = seekword.length();
        
        int index = 0;
        bool mark = true;
        
        while (mark) {
            transform(str2.begin(),str2.end(),str2.begin(),::tolower);        //大小写转换
            index = str2.find(seekword, index);
    //        cout << index <<endl;
            if (index == string::npos){
                mark = false;
            }else{
                str1.replace(index, seeklengh, replaceword);
                str2 = str1;
            }
        }
        cout << str1 << endl;
    }
    return 0;
}