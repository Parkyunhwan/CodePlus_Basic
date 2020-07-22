/*
    https://www.acmicpc.net/problem/15658
    * 재귀 함수는 완전 탐색이라는 무식하게 모두 세는 방식을 사용하여 알고리즘을 짤 때 좋다.
    
*/


#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{

    int N;
    int c=0;
    int oper[4];
    int A[100];
    int *combi;
    int sum = 0;
    int min_sum = INT_MAX;
    int max_sum = INT_MIN;
    cin >> N;
    combi = new int[4*N];
    for(int i=0; i < N; i++)
        cin >> A[i];
    
    for(int i=0; i < 4; i++)
        cin >> oper[i];

    for(int i=0; i < 4; i++){
        for(int j=0; j < oper[i]; j++){
            combi[c] = i;
            c++;
        }
    }

        do{
            sum = A[0];
            for(int j=0; j < N-1; j++){
                // printf("%d\n",A[j+1]);
                // printf("%d\n",combi[j]);
                switch(combi[j])
                {
                    case 0:
                        sum = sum + A[j+1];
                        break;
                    case 1:
                        sum = sum - A[j+1];
                        //printf("case 1 : %d\n", sum);
                        break;
                    case 2:
                        sum = sum * A[j+1];
                        break;
                    case 3:
                        sum = sum / A[j+1];
                        break;
                    
                }
            }

            min_sum = min(min_sum, sum);
            max_sum = max(max_sum, sum);
                        //printf("z %d\n",sum);

        }while( next_permutation(combi, combi + c ) );
        printf("%d\n",max_sum);
        printf("%d\n",min_sum);
}