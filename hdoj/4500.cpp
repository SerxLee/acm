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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};


int n, m;
int arr[22][22];
int aaa[22][22];

bool bianjie(int x, int y){
    if (x >= 0 && x <= n && y >= 0 && y <= m){
        return true;
    }
    return false;
}

int main(){
    while (cin >> n >> m){
        if (n == 0 && m == 0){
            break;
        }
        memset(aaa, 0, sizeof(aaa));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++){
            for (int j = 0;j < m; j++){
                cin >> arr[i][j];
            }
        }
        int lim_i = 0, lim_j = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int ii = 0; ii < 4; ii++){
                    lim_i = dx[ii] + i;
                    lim_j = dy[ii] + j;
                    if (bianjie(lim_i, lim_j)){
                        int ti = arr[lim_i][lim_j];
                        if (arr[i][j] < 0 && ti < 0){
                            aaa[i][j] -= abs(ti);
                        }
                        if (arr[i][j] < 0 && ti >= 0){
                            aaa[i][j] += ti;
                        }
                        if (arr[i][j] >= 0 && ti < 0){
                            aaa[i][j] += abs(ti);
                        }
                        if (arr[i][j] >= 0 && ti >= 0){
                            aaa[i][j] -= ti;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                printf("%d ", aaa[i][j]);
            }
            printf("\n");
        }
        int mx = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (aaa[i][j] >= mx){
                    if (aaa[i][j] > mx){
                        mx = aaa[i][j];
                        lim_i = i;
                        lim_j = j;
                    }else{
                        if (i < lim_i){
                            lim_i = i;
                            lim_j = j;
                        }else if (i == lim_i){
                            if (j < lim_j){
                                lim_j = j;
                            }else{
                                return 0;
                            }
                        }else{
                            return 0;
                        }
                    }
                }
            }
        }
        cout << lim_i + 1 << " " << lim_j + 1 << " "<< mx << endl;
    }
    return 0;
}