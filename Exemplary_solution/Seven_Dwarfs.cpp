//9개 중 7명의 키를 합했을 때 100 이 되는 경우를 찾는 문제
//9C2 이므로 36가지 경우가 발생 2중 포문을 통한 완전 탐색을 실시 한다.

#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int n,result = 0;

#define MAX 987654321;
bool check = false;
int main()
{
    for(int i = 1; i < 9; i++)
    {
        cin >> arr[i];
        result += arr[i];
    }

    for(int i = 1; i <= 9; i++)
    {
        for(int j=i+1; j <=9; j++)
        {
            if(result - arr[i] - arr[j] == 100)
            {
                arr[i] = MAX;
                arr[j] = MAX;
                check = true;
                break;
            }
        }
        if(check)
            break;
    }
    sort(arr,arr+10);
    for(in)
}

