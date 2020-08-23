#include <iostream>

using namespace std;
long long d[100001];
long long overlap[100001][4];
int main()
{
    int num;
    cin >> num;
    overlap[1][1]=1;
    overlap[2][2]=1;
    overlap[3][1]=1;
    overlap[3][2]=1;
    overlap[3][3]=1;
    d[1]=1; d[2]=1; d[3]=3;
    for(int i=0; i<num; i++)
    {
        int N;
        cin >> N;
        for(int i=4; i<=N; i++){
            long long sum = overlap[i-1][1] + overlap[i-2][2] + overlap[i-3][3];
            d[i] =( (d[i-1] + d[i-2] + d[i-3]) - sum )%1000000009;
            //cout << overlap[i-1][1] << overlap[i-2][2] << overlap[i-3][3] << "\n";
            overlap[i][1] = (d[i-1] - overlap[i-1][1])%1000000009;
            overlap[i][2] = (d[i-2] - overlap[i-2][2])%1000000009;
            overlap[i][3] = (d[i-3] - overlap[i-3][3])%1000000009;
        }
        cout << d[N] << "\n";
    }
}