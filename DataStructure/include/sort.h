#include <stdio.h>
#include <stdlib.h>

int QPartition(int arr[], int s, int e)
{
    int mid = arr[s];
    while (s < e)
    {
        while (arr[e] >= mid && e > s)
            --e;
        arr[s] = arr[e];
        while (arr[s] <= mid && s < e)
            ++s;
        arr[e] = arr[s];
    }

    arr[s] = mid;
    return s;
}

void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int m = QPartition(arr, s, e);
    QuickSort(arr, s, m - 1);
    QuickSort(arr, m + 1, e);
}

int findMax(int arr[], int start, int length)
{
    int i = start;
    int max = arr[start];

    for (int j = start + 1; j < length; j++)
    {
        if (max < arr[j])
        {
            max = arr[j];
            i = j;
        }
    }

    return i;
}

int findMin(int arr[], int start, int length)
{
    int i = start;
    int min = arr[start];

    for (int j = start + 1; j < length; j++)
    {
        if (min > arr[j])
        {
            min = arr[j];
            i = j;
        }
    }

    return i;
}

void SelectSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int j = findMax(arr, i, length); // 每次从未排序中找最大的值
        // int j = findMin(arr, i, length); // 每次从未排序中找最小的值
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }

    for (int i = 1; i < length; i++)
    {
        int ith = i;
        for (int j = i + 1; i <= length; j++)
        {
            if (arr[j] < arr[ith])
            { // Find min
                ith = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[ith];
        arr[ith] = temp;
    }
}

void BubbleSort(int arr[], int length)
{

    int i = 0;
    for (; i < length; i++)
    {
        for (int j = i; j < length - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int h)
{
    // if (l >= h)
    //     return;
    int temp[h - l + 1];
    int index = 0, i = l, j = m + 1;
    printf("Distance:[%d, %d, %d]\n", l, m, h);
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[index++] = arr[i++];
            printf("Add index of i %d: %d\n", i, temp[index - 1]);
        }
        else
        {
            temp[index++] = arr[j++];
            printf("Add index of j %d: %d\n", j, temp[index - 1]);
        }
    }
    while (i <= m)
    {
        temp[index++] = arr[i++];
        printf("Add index of %d: %d\n", i, temp[index - 1]);
    }
    while (j <= h)
    {
        temp[index++] = arr[j++];
        printf("Add index of %d: %d\n", j, temp[index - 1]);
    }

    for (index = 0;index < h - l + 1;)
    {
        arr[l + index] = temp[index];
        // printf("%d\n",temp[j]);
    }
}

void MergeSort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int m = (l + h - 1) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, h);
    merge(arr, l, m, h); // 此时由上两层分治到底层
}