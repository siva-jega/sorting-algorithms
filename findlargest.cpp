#include <iostream>
using namespace std;

template <typename T>
T findlargest(T *arr, int arrlength)
{
    T res = 0;
    for (int i = 0; i < arrlength; i++)
    {
        if (res < arr[i])
        {
            res = arr[i];
        }
    }
    return res;
}

int main(int arg, char **argv)
{
    int arr[] = {99, 1, 23, 41, 25, 66, 2, 10, 41, 28, 73};
    int arrlength = sizeof(arr) / sizeof(int);
    cout << "Biggest number from {99, 1, 23, 41, 25, 66, 2, 10, 41, 28, 73} is " << findlargest(arr, arrlength) << endl;
    return 0;
}