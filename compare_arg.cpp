#include <iostream>
#include <string>

using namespace std;

int compare_args(int a, int b)
{
    return a < b ? b : a;
}

string compare_args(string a, string b)
{
    return a.length() < b.length() ? b : a;
}

int main(int arg, char **argv)
{
    cout << "biggest of 10, 22 is " << compare_args(10, 22) << endl;
    cout << "biggest of 45, 13 is " << compare_args(45, 13) << endl;
    cout << "biggest of string \"abc\" and \"defgh\" is " << compare_args("abc", "defgh") << endl;
    cout << "biggest of string \"klmno\" and \"xyz\" is " << compare_args("klmno", "xyz") << endl;
    return 0;
}