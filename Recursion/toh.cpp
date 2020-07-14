#include<bits/stdc++.h>
using namespace std;


void move(int n, char src, char helper, char dest)
{
    // Base case
    if(n==0) return;

    // Recursive case
    // moving n-1 disk from src to dest
    move(n-1,src,dest,helper);
    cout<<"Shifting disk "<<n<<" "<<src <<" "<<dest<<endl;
    // moving all disk from helper to dest
    move(n-1,helper,src,dest);
}


int main()
{
    int n;
    cin>>n;

    move(n,'A','B','C');
}
