#include <string>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

string s, t;
long long  sum_Y = 0, sum_W = 0;
map<char , long long> mymap;
map<char , long long>::iterator iter;
map<char , long long > mymap2;

int main(){
    cin >> s >> t;
    for (long long  i = 0; i < t.size(); i ++){
        mymap[t[i]] += 1;
    }
    for (long long  i = 0; i < s.size(); i ++){
        mymap2[s[i]] += 1;
    }
    
//    for (iter = mymap.begin(); iter != mymap.end(); iter++){
//        cout << iter->first << " :" <<iter->second << " ";
//    }
//    cout << endl;
    for (int i = 0; i < s.size(); i++){
        if (mymap.find(s[i]) != mymap.end()){
            if (mymap[s[i]] >= mymap2[s[i]]){
                mymap[s[i]] -= mymap2[s[i]];
                sum_Y += mymap2[s[i]];
                mymap2[s[i]] = 0;
            }else{
                mymap2[s[i]] -= mymap[s[i]];
                sum_Y += mymap[s[i]];
                mymap[s[i]] = 0;
            }
        }
    }
    for (long long i= 0; i < s.size(); i++){
        if (mymap2[s[i]] > 0){
            char lim_a = s[i];
            if (s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 32;
            }else{
                s[i] = s[i] + 32;
            }
            if (mymap[s[i]] > 0){
                mymap[s[i]]--;
                mymap2[lim_a]--;
                sum_W++;
            }
        }
    }
    cout << sum_Y << " " << sum_W << endl;
    return 0;
}