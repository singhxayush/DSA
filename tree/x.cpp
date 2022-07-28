#include<iostream>
using namespace std;
int main()
{
    system("add .");
    system("status");
    cout<<"Enter Message :";
    string s; cin>>s;
    string com = "git commit -a" + s;
    system(com.c_str());
}