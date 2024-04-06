#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> &bit)
{
    for(int i:bit)
    {
        cout << i;
    }
    cout << endl;
}

void Try(vector<int> &bit, int n)
{
    for(int j = 0; j <= 1; j++)
    {
        bit.push_back(j);
        if(bit.size() == n)
        {
            print(bit);
        }
        else
            Try(bit, n);    
        bit.pop_back(); 
    }
}

int main()
{
    vector<int> bit;
    int n;
    cin >> n;
    
    Try(bit, n);
    
    return 0;
}
