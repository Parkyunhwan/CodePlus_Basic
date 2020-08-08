/*
    https://www.acmicpc.net/problem/4963

    * 전형적인 DFS문제에 대각선의 경우가 추가된 문제
    * map에 대한 범위 검사 부분이 핵심이다.

    오류
    
    문제를 풀 때 언어에 대한 선택이 굉장히 중요하다고 느꼈다.
    올바른 풀이방법을 알고 있어도
    잘못된 변수 이름 선택으로 치명적인 오류를 범할 수 있었다.
    ** 확실히 구분 가는 변수를 설정하자 **

*/
#include <iostream>
#include <vector>
#include <algorithm>
enum check{SEA,LAND};
enum check1{VISIT,NOT};
enum direction{TOP,BOTTOM,LEFT,RIGHT,LT,RT,LB,RB};
using namespace std;
int w, h;
int map[50][50];
int dx[] = {0,0,-1,1,-1,1,-1,1};
int dy[] = {-1,1,0,0,-1,-1,1,1};
void DFS(int i, int j)
{
    map[i][j]=VISIT;
    for(int k=0; k<8; k++){
        if(i+dy[k] < 0 || i+dy[k] >=h || j+dx[k] < 0 || j+dx[k] >= w) continue;
        if(map[i + dy[k]][j + dx[k]] == NOT) DFS(i + dy[k], j + dx[k]);
    }
}
int main()
{

    while(1)
    {
        cin >> w >> h;
        if(w==0 && h==0) break;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
            }
        }
        int island = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]==VISIT) continue;
                    DFS(i,j);
                    island++;
            }
        }
        cout << island << "\n";

    }
}