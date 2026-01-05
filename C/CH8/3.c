#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define M 3

int a[N];
int b[M] = {1, 2, 3};

void gen_random(int upper_bound){
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        a[i] = rand() % upper_bound;
    }
}

void print_random(){
    int i;
    for(i=0; i<N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 交换两个元素
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 打印数组
void print_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 递归生成全排列
void permute(int arr[], int start, int end){
    if(start == end){
        print_array(arr, end + 1);
    } else {
        for(int i = start; i <= end; i++){
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]); // 回溯
        }
    }
}

void print_all_arrangements(){
    printf("数组 b 的全排列:\n");
    permute(b, 0, M - 1);
}
int main(){
    // 打印数组 b 的全排列
    print_all_arrangements();
    
    printf("\n原始直方图代码:\n");
    int i;
    int histogram[10] = {0};
    gen_random(10);
    for(i=0; i<N; i++){
        histogram[a[i]]++;
    }
    printf("0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n");
    for(i=0; i<N; i++){
        for(int j=0; j<10; j++){
            if(histogram[j]!=0)
                printf("*\t");
            else{
                printf(" \t");
                continue;
            }
            histogram[j]--;
        }
        printf("\n");
    }
    return 0;
}