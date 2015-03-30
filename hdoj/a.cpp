#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int t;
map<int , int> mymap;

int main(){
	cin >> t;
	while (t--){
		int n ,x, k, lim_a, lim_b;
		cin >> n >> x >> k;
		for (int i = 0; i < n; i++){
			cin >> lim_a >> lim_b;
			if (!mymap[lim_b]){
				mymap[lim_b] = lim_a;
			}else{
				if (mymap[lim_b] < lim_a){
					mymap[lim_b] = lim_a;
				}
			}
		}
		if (mymap[k] != 0 && mymap[k] >= x){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	} 
	return 0;
}