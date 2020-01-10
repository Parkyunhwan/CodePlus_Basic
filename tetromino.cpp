#include <iostream>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int** arr = new int*[M];
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

		
}

