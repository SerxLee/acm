#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void guibin(int a[], int start, int end) {
    int i, j, k, mid;
    int b[20];
    if (start == end) {
        return;
    }
    mid = (start + end) / 2;
    guibin(a, start, mid);
    guibin(a, mid + 1, end);
    i = start;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        }else{
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= end) {
        b[k++] = a[j++];
    }
    for (i = 0; i <= end - start; i++) {
        a[start + i] = b[i];
    }
    return;
}

int main(){
    int a[20];
    int i;
    srand((int)time(0));
    for (i=0; i<20; i++) {
        a[i]=rand()%(100-1)+1;
        
    }
    guibin(a , 0, 19);
    for (i = 0; i < 20; i++) {
        printf("%d ", a[i]);
    }
}

====================================================================
 // 归并排序中的合并算法
void Merge(int array[], int start, int mid, int end){
　　　 int temp1[10], temp2[10];
　　　 int n1, n2;
　　　 n1 = mid - start + 1;
　　　 n2 = end - mid;
　　　 // 拷贝前半部分数组
　　　 for (int i = 0; i < n1; i++)
　　　 {
　　　　　　　 temp1[i] = array[start + i];
　　　 }
　　　 // 拷贝后半部分数组
　　　 for (int i = 0; i < n2; i++)
　　　 {
　　　　　　　 temp2[i] = array[mid + i + 1];
　　　 }
　　　 // 把后面的元素设置的很大
　　　 temp1[n1] = temp2[n2] = 1000;
　　　 // 逐个扫描两部分数组然后放到相应的位置去
　　　 for (int k = start, i = 0, j = 0; k <= end; k++){
　　　　　　　 if (temp1[i] <= temp2[j])
　　　　　　　 {
　　　　　　　　　　　 array[k] = temp1[i];
　　　　　　　　　　　 i++;
　　　　　　　 }
　　　　　　　 else
　　　　　　　 {
　　　　　　　　　　　 array[k] = temp2[j];
　　　　　　　　　　　 j++;
　　　　　　　 }
　　　 }
}
// 归并排序
void MergeSort(int array[], int start, int end){
　　　 if (start < end){
　　　　　　　 int i;
　　　　　　　 i = (end + start) / 2;
　　　　　　　 // 对前半部分进行排序
　　　　　　　 MergeSort(array, start, i);
　　　　　　　 // 对后半部分进行排序
　　　　　　　 MergeSort(array, i + 1, end);
　　　　　　　 // 合并前后两部分
　　　　　　　 Merge(array, start, i, end);
　　　 }
}