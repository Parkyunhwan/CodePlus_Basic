/*
    20-07-08
    9095 1,2,3 더하기

    생각단계
    1. 현재 순열의 다음 순열은 그 다음 큰 숫자이다.
    2. 그 다음 큰 숫자가 없다면 -1 을 출력한다.

    구현단계

*/
#include <iostream>
using namespace std;
bool next_permutation(int *a, int n)
{
    int i = n - 1;
    while(i > 0 && a[i] <= a[i-1])
        i--;
    if(i <= 0)
        return false;
    int j = n-1;
    while(a[i-1] >= a[j])
        j--;
    swap(a[i-1],a[j]);
    j = n-1;
    while(i < j){
        swap(a[i],a[j]);
        i +=1;
        j -=1;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;

    int *v = new int[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    if(next_permutation(v,n)){
        for(int i = 0; i<n; i++)
            cout << v[i] << ' ';
    }
    else{
        cout << "-1";
    }

    return 0;

}