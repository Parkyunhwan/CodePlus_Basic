/*
    생각
    1. 받은 값들을 sort한다
    2. sort한 값들로 모든 순열의 경우를 계산한다.
    3. 그 중 최댓값을 선택한다.

    구현
    1. abs와 max
    2. next_permutation을 활용한 구현
*/
#include <iostream> 
#include <algorithm>
using namespace std;
int max_num=0;
void get_max(int *arr, int n)
{
    int k;
    int sum=0;
    for(int i=0; i < n - 1; i++){
        k=abs(arr[i] - arr[i+1]);
        sum += k;
    }
    max_num = max(sum, max_num);
    return;    
}
int main()
{
    int n;
    int *arr;
    cin >> n;
    arr=new int[n];
    for(int i=0; i < n; i++)
        cin >> arr[i];
    sort(arr,arr+n);  
    do{
        get_max(arr, n);
    }while(next_permutation(arr,arr+n));

    printf("%d\n",max_num);
}