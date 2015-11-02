#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
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

struct node
{
	int s1, s2;
};

vector<node>  a_arr, b_arr;
vector<node> ::iterator iter;

int cmp1(const void *a, const void *b){
	struct node *c = (node *)a;
	struct node *d = (node *)b;
	if (c.s1 > d.s1){k
		return c.s1 - d.s1;
	}else{
		return d.s2 - c.s2;
	}
}

int cmp2(const void *a, const void *b){
	struct node *c = (node *)a;
	struct node *d = (node *)b;
	if (c.s1 > d.s1){
		return c.s1 - d.s1;
	}else{
		return d.s2 - c.s2;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		struct node lim;
		cin >> lim.s1 >> lim.s2;
		if (lim.s1 == 0){
			break;
		}
		if (lim.s1 > lim.s2){
			a_arr.push_back(lim);
		}else{
			b_arr.push_back(lim);
		}
		qsort(a_arr.begin(), a_arr.end(), cmp);
		qsort(b_arr.begin(), b_arr.end(), cmp2);
		for (vector<node> ::iterator iter = a_arr.begin(); iter != a_arr.end(); iter++){
			cout << iter.s1 << " " << iter.s2 << endl;
		}
	}

}