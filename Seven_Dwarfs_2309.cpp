#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int num = 9;
bool Select[num]={false,};
int *Dwarfs;
vector<int> v;
void realDwarfs(int idx,int cnt)
{
    int sum = 0;

    if(cnt == 7){
        for(int i=0; i<num; i++)
        {
            if(Select[i]==true)
                sum+=Dwarfs[i];
        }
        if(sum==100)
        {
            for(int i=0; i < num; i++){
                if(Select[i]==true)
                    v.push_back(Dwarfs[i]);
            }
        }
        return;
    }

    for(int i=idx; i<num; i++)
    {
        if(Select[i]==true) continue;
        Select[i]=true;

        realDwarfs(i,cnt+1);
        Select[i]=false;
    }
}

int main()
{
    Dwarfs=new int[num];
    for(int i=0; i<num; i++)
         cin >> Dwarfs[i];
    // for(int i=0; i < num; i++)
    //     cout << Dwarfs[i];
    
    realDwarfs(0,0);
    //cout << "AA" << endl;
    v.resize(7);
    sort(v.begin(), v.end());
    for(auto &i : v)
        cout << i << endl;
}