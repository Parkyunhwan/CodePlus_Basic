/*
    생각
    1. 도시들을 번호로 배열에 넣어둔다.
    2. 모든 순열에 대해 경로의 비용을 구해 그 중 최솟값을 구한다.
    구현
    1. 경로 중 비용이 0인 곳이 있다면 그 경로는 가지 못하는 구간
    2. 돌아오는 경로도 계산해주어야 한다.
*/
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
using namespace std;
int W[11][11]={0,};
int arr[10];

int ts(int n)
{   
    int min_value=INT_MAX;
    // 정방향으로 모든 도시를 거치는 최솟값의 경우를 모두 시도함
    do{
        bool flag=true;
        int value = 0;
        for(int i = 0; i < n-1; i++){
            if(W[arr[i]][arr[i+1]]==0){
                flag = false;
                break;
            }
            else
                value+=W[arr[i]][arr[i+1]];
        }
        if(flag && ( W[arr[n-1]][arr[0]]!=0 )){
            value+=W[ arr[n-1]][ arr[0] ];
            min_value=min(min_value, value);
        }

    }while(next_permutation(arr, arr+n));
    return min_value;
}
int main()
{
    int n;
    int cost;
    cin >> n;
    for(int i=0; i < n; i++){
        arr[i] = i;
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
            cin >> W[i][j];
    }
    cost = ts(n);
    printf("%d\n",cost);
}
//////////////