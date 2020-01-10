#include <iostream>
#define MAX 500
using namespace std;
int Visit[MAX][MAX];
int Answer;
int M, N;
int** arr;
int dy[] = {0,  0, 1, -1};
int dx[] = {1, -1, 0,  0}; // 방향 설정
int Bigger(int a,int b){if(a>b)return a; return b;}

void tetromino(int x, int y,int cnt,int sum)
{
	Visit[x][y] = true;
	if(cnt == 3)
	{
		Answer = Bigger(Answer, sum);
	}

	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if(Visit[nx][ny] == true) continue;

		tetromino(nx, ny, cnt+1, sum + arr[nx][ny]);
		Visit[nx][ny] = true;
	}
}

void Shape1(int x, int y)
{
	int Tmp_Sum = 0;
	Tmp_Sum = arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x-1][y+1];
	Answer = Bigger(Tmp_Sum, Answer);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); // 속도 부스
	cin >> M >> N;
	arr = new int*[M];
	for(int i=0; i < M; i++)
	{
		arr[i] = new int[N];
	}

	for(int i=0; i < M; i++)
	{
		for(int j=0; j < M; j++)
		{
			int in;
			cin >> in;
			arr[i][j]=in;
		}
	}

	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            memset(Visit, false, sizeof(Visit));
            tetromino(i, j, 0, arr[i][j]);
            if (i - 1 >= 0 && j + 2 < M) Shape1(i, j);
        }
    }

		
}

