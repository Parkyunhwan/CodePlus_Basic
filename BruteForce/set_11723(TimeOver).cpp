/*
    all같은 예외의 입력 경우를 처리 하기 위해 두번째 입력을 뒤로 미룬다.

    str과 num을 한번에 입력 받지 않고 num의 입력은 경우에 따라 나눈다.
*/
#include <iostream>
#include <string>
using namespace std;
int S[21]={0,};
int main()
{
    int M;
    int num;
    cin >> M;
    string str;
    while(M--){
        cin >> str;
        //cout << "s, num :" << str << " " << num << "\n";
        if(str == "add"){
            cin >> num;
            S[num] = 1;
        }
        else if(str == "remove"){
            cin >> num;
            S[num] = 0;
        }
        else if(str == "check"){
            cin >> num;
            if(S[num]==1)
                cout << "1\n";
            else
            {
                cout << "0\n";
            }
        }
        else if(str == "toggle"){
            cin >> num;
            if(S[num]==1)
                S[num]=0;
            else
            {
                S[num]=1;
            }
        }
        else if(str == "all"){
            for(int i=0; i<21; i++)
                S[i] = 1;
        }    
        else if(str == "empty"){
            for(int i=0; i<21; i++)
                S[i] = 0;
        }
    }

}