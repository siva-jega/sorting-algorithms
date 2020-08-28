/**
 *  Author : Sivakumar Jegatheesan
 *  Bubble sort performs O(n)(n-1)
 * 
 * */

#include <iostream>

using namespace std;

/**
 * This function takes an array pointer and length of the array
 * prints a formatted array on the stdin
 * Returns NULL
 **/
void printarray(int *arr, int arrlength)
{
    cout << "{";
    for (int i = 0; i < arrlength; i++)
    {
        cout << arr[i];
        if (i != arrlength - 1)
            cout << ", ";
    }
    cout << "}" << endl;
}

/**
 * This function takes an array pointer and length of the array
 * sorts the array inline using array pointer
 * Returns NULL
 **/
void bubblesort(int *arr, int arrlength)
{
    for (int i = 0; i < arrlength; i++)
    {
        // Decrementing one for every iteration as the last two is already sorted
        for (int j = 0; j < arrlength - i; j++)
        {
            if (j && arr[j] < arr[j - 1])
            {
                //Swapping current elm with previous elm
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main(int arg, char **kargv)
{
    int arr[] = {99, 1, 23, 41, 25, 66, 2, 10, 41, 28, 73};
    int arrlength = sizeof(arr) / sizeof(int);
    cout << "Original :";
    printarray(arr, arrlength);
    bubblesort(arr, arrlength);
    cout << "Sorted :";
    printarray(arr, arrlength);
    return 0;
}