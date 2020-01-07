#include <iostream>

using namespace std;
int gcd(int a, int b)
{
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}
int lcm(int a,int b)
{
    return a * b / gcd(a,b);
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << endl << lcm(a,b) << endl;
}

//최대공약수는 재귀 나머지를 통해 해결한다.

//최소공배수는 두 값 곱사기 최대 공약수 이다.