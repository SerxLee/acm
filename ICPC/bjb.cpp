#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

const int N = 100010;
const int INF=0x3f3f3f3f;
const int MOD=95041567,STA=8000010;

double EPS=1e-8;
const double OO=1e15;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

stack<char> l_stack;
stack<char> r_stack;


char str_yuan[N];
int weizhi;
int m;
int kai, num, num1;
char cop[N];
int num_cop;
int ans[N];

void init(){
    while (!l_stack.empty()){
        l_stack.pop();
    }
    while (!r_stack.empty()) {
        r_stack.pop();
    }
}

void move_L(){
    char aa;
    aa = l_stack.top();
    l_stack.pop();
    r_stack.push(aa);
}

void move_R(){
    char aa;
    aa = r_stack.top();
    r_stack.pop();
    l_stack.push(aa);
}

void del(){
    if (num <= num1){
        int aa;
        aa = num;
        num = num1;
        num1 = aa;
    }
    for (int i = num1; i <= num; i++){
        l_stack.pop();
    }
}

void vvv(){
    for (int i = 0; i < num_cop; i++){
        if (l_stack.size() + r_stack.size() <= m){
            l_stack.push(cop[i]);
        }
    }
}

void chang(){
    kai = 1 - kai;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        cin >> m;
        init();
        scanf("%s", str_yuan);
        long lengh = strlen(str_yuan);
        kai = 0;
        num_cop = 0;
        for (int i = 0; i < lengh; i++){
            if (str_yuan[i] >= 'a' && str_yuan[i] <= 'z' &&  (l_stack.size() + r_stack.size()) < m){
                l_stack.push(str_yuan[i]);
            }else{
                if (str_yuan[i] == 'L' && !r_stack.empty() && !l_stack.empty()){
                    move_L();
                }
                if (str_yuan[i] == 'R' && !r_stack.empty() && !l_stack.empty()){
                    move_R();
                }
                if (str_yuan[i] == 'V'){
                    vvv();
                }
                if (str_yuan[i] == 'D' && !r_stack.empty()){
                    r_stack.pop();
                }
                if (str_yuan[i] == 'B' && !l_stack.empty()){
                    l_stack.pop();
                }
                if (str_yuan[i] == 'C' && !r_stack.empty() && !l_stack.empty()){
                    chang();
                    num = i;
                    num1 = i;
                    while (kai){
                        i++;
                        num_cop = 0;
                        if (str_yuan[i] >= 'a' && str_yuan[i] <= 'z' && (l_stack.size() + r_stack.size()) < m){
                            //num++;
                            //l_stack.push(str_yuan[i]);
                            //cop[num_cop++] = str_yuan[i];
                        }
                        if (str_yuan[i] == 'L'){
                            num--;
                            //move_L();
                            chang();
                            num_cop = 0;
                        }
                        if (str_yuan[i] == 'R'){
                            num++;
                            //move_R();
                            chang();
                            num_cop = 0;
                        }
                        if (str_yuan[i] == 'D'){
                            del();
                            chang();
                            num_cop = 0;
                        }
                        if (str_yuan[i] == 'V'){
                            chang();
                            vvv();
                        }
                        if (str_yuan[i] == 'C'){
                            chang();
                        }
                    }
                }
            }
        }
        if (l_stack.empty() && r_stack.empty()){
            cout << "NOTHING" << endl;
        }else{
            long la = l_stack.size();
            for (int i = 0; i < la; i++){
                ans[la - 1 - i] = l_stack.top();
                l_stack.pop();
            }
            for (int i = 0; i < la; i++){
                printf("%c", ans[i]);
            }
            //cout << endl;
            while (!r_stack.empty()) {
                printf("%c", r_stack.top());
                r_stack.pop();
            }
            cout << endl;
        }
    }
    return 0;
}