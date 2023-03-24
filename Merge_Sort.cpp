#include <iostream>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - s;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = s; // k is index of original array
    // copy values from original array to new array
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k];
        k++;
    }

    // Merge twwo new arrays
    k = s;
    int index1 = 0;
    int index2 = 0;
    while (index1 < len1 && index2 < len2)
    {
        /* code */
        if (arr1[index1] < arr2[index2])
        {
            arr[k] = arr1[index1];
            k++;
            index1++;
        }
        else
        {
            arr[k] = arr2[index2];
            k++;
            index2++;
        }
    }
    while (index1 < len1)
    {
        arr[k] = arr1[index1];
        k++;
        index1++;
    }
    while (index2 < len2)
    {
        arr[k] = arr2[index2];
        k++;
        index2++;
    }
}
void mergesort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;

    mergesort(arr, s, mid);

    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    int arr[11] = {5, 3, 9, 55, 65, 96, 1, 0, 22, 54, 32};
    mergesort(arr, 0, 10);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl
         << "github.com/adi1719/";
}
