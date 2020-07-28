/*
    https://www.acmicpc.net/problem/13023
*/
#include <iostream>
#include <vector>
using namespace std;
int N,M;
bool flag;
int result=1;
vector<int> v[2000];
int main()
{
    int a,b;
    cin >> N >> M;

    for(int i=0; i < M; i++){
        cout << i << "\n";
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            flag = false;
            for(int k=0; k<v[i].size(); k++){
                if(v[i][k]==j){
                    flag = true;
                }
            }
            if(flag==false){
                result = 0;
                i=N; j=N;
            }
        }
    }
    cout << "result : " << result << "\n";
}