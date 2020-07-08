/*
    20-07-08
    14500 테트로미노

    생각단계
    1. 만들 수 있는 도형을 생각해보자 - 19개
    2. 각 도형에 대해 적용시켜보자
    3. 최댓값을 구해보자.

    구현단계
    1. 블럭을 모양별로 지정
    2. 시작지점을 모든 블럭으로 바꿔가며 반복
    3. 블럭의 모양마다의 값을 최댓값과 비교
    4. 최댓값 산출

*/
#include <iostream>
using namespace std;
int answer = 0;
int N,M;
int paper[500][500];
const int block[19][4][2] = {
    { {0,0}, {0,1}, {1,0}, {1,1} }, // ㅁ
    { {0,0}, {0,1}, {0,2}, {0,3} }, // ㅡ
    { {0,0}, {1,0}, {2,0}, {3,0} },
    { {0,0}, {0,1}, {0,2}, {1,0} }, // ㄴ
    { {0,2}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {1,0}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,2} },
    { {0,0}, {1,0}, {2,0}, {2,1} },
    { {0,0}, {0,1}, {1,1}, {2,1} },
    { {0,0}, {0,1}, {1,0}, {2,0} },
    { {0,1}, {1,1}, {2,0}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,1} }, // Z
    { {0,1}, {1,0}, {1,1}, {2,0} },
    { {0,1}, {0,2}, {1,0}, {1,1} },
    { {0,0}, {0,1}, {1,1}, {1,2} },
    { {0,0}, {0,1}, {0,2}, {1,1} }, // ㅗ
    { {0,1}, {1,0}, {1,1}, {1,2} },
    { {0,1}, {1,0}, {1,1}, {2,1} },
    { {0,0}, {1,0}, {1,1}, {2,0} }
};
void tetromino(int x, int y)
{
    for(int b=0; b<19; b++)
    {
        int result=0;
        for(int t=0; t<4; t++){
            int nx = x + block[b][t][0];
            int ny = y + block[b][t][1];
            if(0 <= nx && nx < N && 0 <= ny && ny < M)
                result += paper[nx][ny];
        }

        if(answer < result) answer = result;
    }
}

int main()
{
    scanf("%d %d" , &N,&M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> paper[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            tetromino(i, j);
        }
    }
    printf("%d\n",answer);
}
