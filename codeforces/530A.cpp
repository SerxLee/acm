#include <cstdio>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

double a, b, c;

int main(){
	while (cin >> a >> b >> c){
		double x1, x2;
		double abc =  sqrt(b * b - 4 * a * c);
		if (!abc){
			x1 = (-b + abc) / (2 * a);
			cout << x1 << endl;
 		}else{
 			x1 = (-b + abc) / (2 * a);
 			x2 = (-b - abc) / (2 * a);
 			cout << x1 << " " << x2 << endl;
 		}
	}
	return 0;
}