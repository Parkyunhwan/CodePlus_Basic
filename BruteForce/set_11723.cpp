/*
    1. all같은 예외의 입력경우를 처리 하기 위해 두번째 입력을 뒤로 미룬다.

       str과 num을 한번에 입력 받지 않고 num의 입력은 경우에 따라 나눈다.

    * Time Over 문제 해결
    * 
    * ios_base::sync_with_stdio(0) 추가를 통한 입출력속도 향상 --> 성공 
    * cin.tie(NULL) 
    *  - 두가지 적용 시 printf puts 같은 c의 입출력은 쓸 수 없다고 한다 -
    * 
    ** 좀 더 빠른 속도를 위해선
    *  memset을 통해 값을 바꾼다??
    *  -> for문이나 fill과 유의미한 차이가 없다고 한다
    * https://kevinthegrey.tistory.com/158 [비트마스크 해결방법] - 참고 할 만 하다.
*/
#include <iostream>
#include <string>
using namespace std;
int S[21]={0,};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
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