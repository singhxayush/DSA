///// RUN FILE C++ /////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string FILE_NAME;
    cin >> FILE_NAME;

    system("< fn.txt");

    string CPP_FILE_NAME = FILE_NAME + ".cpp";
    system(("g++ " + CPP_FILE_NAME).c_str());
    system(("./a.out > op.txt"));
}