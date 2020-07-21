/*
    발생 오류 
    T의 범위를 배열의 크기로 착각해서 굉장히 오류를 찾기 힘들었다.
    배열 크기 오버플로우 오류 발생.
 */
#include <iostream>
#include <algorithm>
using namespace std;

int T[15];
int P[15];
int combi[15];
int max_sum=0;
int sum1;
int T_cum = 0;
int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &T[i], &P[i]);
    for(int i = 0; i < N; i++){
        combi[i] = 1;
        do{
            T_cum = 0;
            sum1 = 0;
            for(int i = 0; i < N; i++){
                if(combi[i]==1){
                    T_cum = i + T[i];
                    if(T_cum <= N){
                        sum1 = sum1 + P[i];

                    }
                    i=T_cum - 1;
                }
            }

        max_sum = max(sum1,max_sum);
        }while(prev_permutation(combi, combi+N));

    }
    cout << max_sum << "\n";
}