//
//  main.cpp
//  shenyang
//
//  Created by Serx on 15/9/19.
//  Copyright (c) 2015年 serx. All rights reserved.
//

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

const int INF=0x3f3f3f3f;

template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
template<class T> inline void CheckMin(T &a,T b){if(a>b) a=b;}
template<class T> inline void CheckMax(T &a,T b){if(a<b) a=b;}

long long a, b, n;

long long ans;


int main(){
    int T;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> n >> a >> b;
        if (n == 2){
            long long m1 = 0, m2 = 0, v1 = INF, v2 = INF;
            for (long long i = 1; i <= n; i++){
                long long aaa;
                scanf("%lld", &aaa);
                if (aaa < 0  && aaa < v1){
                    v2 = v1;
                    v1 = aaa;
                }else{
                    if (aaa >= m1){
                        m2 = m1;
                        m1 = aaa;
                    }
                    
                }
                
            }
            //   cout << m1 << " " << m2 << " " << v1 << endl;
            //   quicksort(g, 1, n);
            
            //        int flag1 = 0;
            //        if (v1 == INF){
            //            flag1 = 1;
            //        }
            long long lim1, lim2, lim3;
            lim1 = -v1;
            lim2 = -v2;
            if (lim1 > m1){
                lim3 = m1;
                m1 = lim1;
                lim1 = lim3;
            }else{
                if (lim1 > m2){
                    lim3 = m2;
                    m2 = lim1;
                    lim1 = lim3;
                }
            }
            
            if (lim2 > m2){
                lim3 = m2;
                m2 = lim2;
                lim2 = lim3;
            }
            
            if (a < 0 && b < 0){
                ans = a * v1 * v1 + b * v2;
            }else if (a < 0 && b > 0){
                ans = a * v1 * v1 + b * m1;
            }else if (a > 0 && b > 0){
                ans = a * m1 * m1 + b * m2;
            }else if (a > 0 && b < 0){
                ans = a * m1 * m1 + b * v1;
            }

        }else{
            long long m1 = 0, m2 = 0, v1 = INF, v2 = INF;
            int flag = 0;
            for (int i = 0; i < 2; i++){
                long long aa;
                cin >> aa;
                
                if (aa < 0 && aa < v1){
                    v1 = aa;
                    v2 = aa;
                    flag++;
                }
                if (aa > m1){
                    m1 = aa;
                    m2 = m1;
                }
                if (flag == 1){
                    
                }
            }
            
        }
        
//        
//        int flag1 = 0;
//        if (v1 != INF){
//            flag1 = 1;
//        }
//        if (flag1){
//            long long v3 = -v1;
//            if (a > 0 && b > 0){
//                if (v3 > m1){
//                    if (v3 > m1){
//                        ans = a * v3 * v3 + b * v2;
//                    }else{
//                        ans = a * v3 * v3 + b * m2;
//                    }
//                }else{
//                    ans = a * m1 * m1 +
//                }
//            }else{
//                if (a > 0 && b < 0){
//                    
//                }
//            }
//            
//        }else{
//
//            ans = a * m1 * m1 + b * m2;
//        }
        printf("Case #%d: ",T);
        cout << ans << endl;
    }
}