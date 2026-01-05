#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 20

int a[N];

typedef struct {
    int value;
    int index;
} MinInfo;

MinInfo findMin(int left, int right)
{
    MinInfo res;
    res.value = a[left];
    res.index = left;
    
    for(int i = left + 1; i <= right; i++){
        if(a[i] < res.value){
            res.value = a[i];
            res.index = i;
        }
    }
    return res;
}

MinInfo findSecondMin(int left, int right)
{
    MinInfo min1 = {a[left], left};
    MinInfo min2 = {INT_MAX, -1};
    
    for(int i = left + 1; i <= right; i++){
        if(a[i] < min1.value){
            min2 = min1;
            min1.value = a[i];
            min1.index = i;
        } else if(a[i] < min2.value && a[i] != min1.value){
            min2.value = a[i];
            min2.index = i;
        }
    }
    return min2;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int start, int end)
{
    int pivot = a[end];
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[end]);
    return i + 1;
}

int order_statistic(int start, int end, int k)
{
    if(k > 0 && k <= end - start + 1){
        int pos = partition(start, end);
        int i = pos - start + 1;
        if(i == k){
            return a[pos];
        }
        else if(i > k){
            return order_statistic(start, pos - 1, k);
        }else{
            return order_statistic(pos + 1, end, k - i);
        }
    }
    return -1;
}
int main(){
    srand(time(NULL));
    
    for(int i = 0; i < N; i++) a[i] = rand() % 100;
    
    printf("随机数组: ");
    for(int i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
    int n = sizeof(a)/sizeof(a[0]);
    int k = 5;
    int result = order_statistic(0, n - 1, k);
    if(result != -1)
        printf("数组中第 %d 小的元素是: %d\n", k, result);
    else
        printf("无效的 k 值\n");
    
    MinInfo res = findMin(0, N - 1);
    printf("最小值: %d, 索引: %d\n", res.value, res.index);
    
    MinInfo res2 = findSecondMin(0, N - 1);
    printf("第二小值: %d, 索引: %d\n", res2.value, res2.index);
    
    return 0;
}
