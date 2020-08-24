#include <iostream>

using namespace std;
long long stair[101][10];
int main()
{
    int N;
    cin >> N;
    for(int i=1; i<=9; i++)
        stair[1][i]=1;

    for(int i=2; i<=N;i++){
        for(int j=0; j<=9; j++){
            if(j==0) stair[i][j] = stair[i-1][1];
            else if(j==9) stair[i][j] = stair[i-1][8];
            else
            {
                stair[i][j] = (stair[i-1][j-1] + stair[i-1][j+1])%1000000000;
            }
            
        }
    }
    cout << (stair[N][0]+stair[N][1]+stair[N][2]+stair[N][3]+stair[N][4]+
    stair[N][5]+stair[N][6]+stair[N][7]+stair[N][8]+stair[N][9])%1000000000 << "\n";
}   