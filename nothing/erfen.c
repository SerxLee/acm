#include <stdio.h>


int erfen(int a[],int start,int end,int k)
{
    int mid;
    mid =(start+end )/2;
    if (start>=end  &&  a[start]!=k) {
        return -1;
    }
    
    if (k==a[mid]){
        return mid ;
            
    }
    else{
        if (k<a[mid]) {
            return erfen(a, start, mid-1, k);
        }
            
    return erfen(a, mid+1, end, k);
            
        
    }
}

