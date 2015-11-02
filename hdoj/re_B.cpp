#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <str100ng>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

#define maxn 100006

using namespace std;

char a[maxn];
int b[maxn];

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> a;
		int lengh = strlen(a);
		memset(b, 0, sizeof(b));
		for (int i = lengh - 1; i >= 0; i--){
			b[lengh - 1 - i] = a[i] - '0';
		}
		bool flag = 1;
		while(flag){
			b[0]++;
			for (int i = 0; i < lengh; i++){
				if (b[i] >= 10){
					b[i + 1]++;
					b[i] %= 10;
				}
			}
			if (b[lengh] > 0){
				lengh++;
			}
			int sum = 0;
			for (int i = 0; i < lengh; i++){
				sum += b[i];
			}
			if (sum % 10 == 0){
				for (j = lengh - 1; j >= 0; j--){
					cout << b[j];
				}
				cout << endl;
				flag = 0;
			}
		}
	}
	return 0;
}