/**
 *  Author : Sivakumar Jegatheesan
 *  Merge sort performs O(log(n))
 *  1. Given array is split into smallest part
 *  2. Once they reach the smallest unit they are merged back
 *  3. The advantage here is both left and right are sorted array
 *  4. So we avoid the n of n iteration overy both arrays
 * */

/**
 *  Tested on g++ on ubuntu distro
 *  to build g++ mergesort.cpp -o mergesort
 * */

#include <iostream>

using namespace std;

/* A small array display utility */
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

/* Implements two sorted arrays to a new sorted array */
void merge(int *arr, int left, int mid, int right)
{
    /* Create a new left array and copy from original array */
    int newleft = mid - left + 1;
    int leftarr[newleft];
    for (int i = 0; i < newleft; i++)
        leftarr[i] = arr[left + i];

    /* Create a new right array and copy from original array */
    int newright = right - mid;
    int rightarr[newright];
    for (int j = 0; j < newright; j++)
        rightarr[j] = arr[mid + 1 + j];

    /* Counter for left, right and original arrays */
    int leftcounter = 0, rightcounter = 0, arraycounter = left;

    //sort and copy temp arrays to original when the counter is true for both
    while (leftcounter < newleft && rightcounter < newright)
    {
        if (leftarr[leftcounter] <= rightarr[rightcounter])
        {
            arr[arraycounter] = leftarr[leftcounter];
            leftcounter++; //left array elm used. Increment left counter
        }
        else
        {
            arr[arraycounter] = rightarr[rightcounter];
            rightcounter++; //right array elm copied. Increment rightcounter
        }
        arraycounter++; //One successful copy to riginal array. Increment array counter
    }

    //copy all extra elm in left array to original array if any
    while (leftcounter < newleft)
    {
        arr[arraycounter] = leftarr[leftcounter];
        leftcounter++;
        arraycounter++;
    }

    //copy all extra elm in right array to original array if any
    while (rightcounter < newright)
    {
        arr[arraycounter] = rightarr[rightcounter];
        rightcounter++;
        arraycounter++;
    }
}

/* Recursively split into smallest unit */
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        //find mid
        int mid = left + (right - left) / 2;
        //recursively find mid for the entire array till each one becomes one element
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        //sort and merge them back recursively
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {99, 1, 23, 41, 25, 66, 2, 10, 41, 28, 73};
    int arrlength = sizeof(arr) / sizeof(int);
    cout << "Original > ";
    printarray(arr, arrlength);
    mergeSort(arr, 0, arrlength - 1);
    cout << "Sorted   > ";
    printarray(arr, arrlength);
}