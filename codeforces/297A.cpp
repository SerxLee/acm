#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int n;
char aa[200010];
map<char , int> mymap;
map<char , int> mymap2;
int ans;


int main(){
    while (cin >> n){
        cin >> aa;
        ans = 0;
        int len = strlen(aa);
        for (int i = 0; i < len; i++){
            if (aa[i] >= 'a' && aa[i] <= 'z'){
                mymap2[aa[i]-'a']++;
            }else{
                if (mymap2[aa[i]-'A'] < 1){
                    ans++;
                }else{
                    mymap2[aa[i]-'A']--;
                }
            }
        }
//        for (int i = 0; i < len; i++){
//            if (aa[i] >= 'A' && aa[i] <= 'Z'){
//                char bb = tolower(aa[i]);
//                if (mymap[aa[i]] > i && mymap2[bb] > 0) {
//                    mymap2[bb]--;
//                }else{
//                    ans++;
//                    cout << ans << endl;
//                }
//            }
//        }
        cout << ans << endl;
    }
    return 0;
}