#include <stdio.h>
#include <stdlib.h>

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

void merge(int arr[], int l, int m, int h)
{
    // 模拟分治区间
    //  printf("模拟区间:[%d, %d, %d]\n", l, m, h);
    //  printf("[");
    //  for (int i = l; i <= h; i++)
    //  {
    //      if (i == h)
    //      {
    //          printf("%d]\n", arr[i]);
    //      }
    //      else
    //      {
    //          printf("%d, ", arr[i]);
    //      }
    //  }
    int i = l, j = m + 1;
    int temp[h - l + 1];
    int index = 0;
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }

    while (i <= m)
    {
        temp[index++] = arr[i++];
    }
    while (j <= h)
    {
        temp[index++] = arr[j++];
    }

    int s = l;
    for (int k = 0; k < (h - l + 1); k++)
    {
        arr[s++] = temp[k];
    }
}

//快速排序
void QuickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int m = QPartition(arr, s, e);
    QuickSort(arr, s, m - 1);
    QuickSort(arr, m + 1, e);
}
//选择排序
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
//冒泡排序
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
//二路归并排序
void MergeSort(int arr[], int l, int h)
{
    if (l >= h)
        return;
    int m = (l + h) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, h);
    merge(arr, l, m, h); // 此时上两层分治到底层
}

//插入排序
void insertSort(int arr[]) {
    
}