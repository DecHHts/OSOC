#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int a[N];

int partition(int start, int end)
{
    int pivot = a[start];
    int left = start + 1;
    int right = end;
    
    // 使用双指针法进行分割
    while(left <= right){
        // 从左边找第一个>=pivot的元素
        while(left <= right && a[left] < pivot){
            left++;
        }
        // 从右边找第一个<=pivot的元素
        while(left <= right && a[right] > pivot){
            right--;
        }
        
        // 如果还未相遇，交换两个元素
        if(left < right){
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
    
    // 将pivot放到正确位置
    int temp = a[start];
    a[start] = a[right];
    a[right] = temp;
    
    return right;
}

void quicksort(int start, int end)
{
    int mid;
    if(end>start){
        mid = partition(start, end);
        quicksort(start, mid-1);
        quicksort(mid+1, end);
    }
}
void print_array(){
    printf("数组: ");
    for(int i = 0; i < N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void gen_random(int upper_bound){
    for(int i = 0; i < N; i++){
        a[i] = rand() % upper_bound;
    }
}

int main(){
    srand(time(NULL));
    gen_random(100);
    
    printf("排序前:\n");
    print_array();
    
    quicksort(0, N - 1);
    
    printf("\n排序后:\n");
    print_array();
    
    return 0;
}