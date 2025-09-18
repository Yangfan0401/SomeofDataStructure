// #include <algorithm.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "linkList.h"

// 10年
// 数组左移
//  Examples:
//  arr[] = {1,2,3,4,5,6,7}  p = 3 左移位数
//  arr[] = {1,2,3,4,5,6,7}  p = 9 左移位数

void leftMove(int arr[], int *target)
{
    // int len = sizeof(*arr) / sizeof(int);
    int len = 8;
    int i = *target;
    for (int j = 0; j < len; j++)
    {
        int index = ((i - 1) % len + len) % len;
        arr[index] = arr[i];
        i = ((i + 1) % len + len) % len;
    }
    *target = ((*target - 1) % len + len) % len;
}
void printArr(int arr[], int target)
{
    // int len = sizeof(arr) / sizeof(int);
    int len = 8;
    int i = 0;
    while (i < len)
    {
        if (i != ((target - 1) % len + len) % len)
        {
            if (i == len - 1)
            {
                printf("%d\n", arr[i]);
            }
            else
            {
                printf("%d, ", arr[i]);
            }
        }
        i++;
    }
    printf("\n");
}

int leftMoveAlg(int p)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0};
    int start = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 6)
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d\n", arr[i]);
            break;
        }
    }
    printf("\n");
    for (int i = 0; i < p; i++)
    {
        leftMove(arr, &start);
        printf("第%d次左移: ", i + 1);
        printArr(arr, start);
    }
    return 0;
}

// 11年

// 两个长度大小相同的升序序列S1、S2,求出它们的中位数
//  int *merge(int S1[], int S2[])
// {
//     int i = 0, j = 0, count = 0;
//     int *arr = (int *)malloc(sizeof(int) * 12);
//     while (count < 12)
//     {
//         if (S1[i] < S2[j])
//         {
//             arr[count] = S1[i++];
//         }
//         else if (S1[i] > S2[j])
//         {
//             arr[count] = S2[j++];
//         }
//         else
//         {
//             arr[count] = S1[i++];
//             j++;
//         }
//         count++;
//     }
//     return arr;
// }

// int test()
// {
//     int arr1[] = {1, 3, 4, 5, 7, 9};
//     int arr2[] = {2, 6, 10, 12, 14, 15};
//     int *arr = (int *)malloc(sizeof(int) * 12);
//     // arr = merge(arr1, arr2);
//     // 法2
//     int i = 0, j = 0;
//     int target = -1;
//     for (int count = 0; count < 7; count++)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             target = arr1[i];
//             i++;
//         }
//         else if (arr1[i] > arr2[j])
//         {
//             target = arr2[j];
//             j++;
//         }
//         else
//         {
//             target = arr2[j];
//             i++;
//             j++;
//         }
//     }

//     for (int i = 0; i < 12; i++)
//     {
//         if (i != 11)
//         {
//             printf("%d,", *(arr + i));
//         }
//         else
//         {
//             printf("%d\n", *(arr + i));
//         }
//     }

//     printf("\n");
//     printf("%d\n", target);
//     int mid = arr[12 / 2];
//     return mid;
// }

// 13年
int test_13_findKey(int s[], int length)
{
    QuickSort(s, 0, length - 1);
    printf("[");
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
        {
            printf("%d, ", s[i]);
        }
        else
        {
            printf("%d", s[i]);
        }
    }
    printf("]\n");
    int max_count = length / 2;
    for (int i = 1, count = 0; i < length; i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
        {
            printf("%d\n", ++count);
            if (count > max_count)
                return 1;
            count = 0;
        }
    }
    return 0;
}

// 16年 集合S,划分为S1,S2两个子集,计长度n1、n2,
// 求划分法使得|n1-n2|最小、|S1的和-S2的和|最大
int partition_16(int s[], int l, int h)
{
    int temp = s[l];

    while (s[h] > temp && l < h)
    {
        h--;
    }
    s[l] = s[h]; //
    while (s[l] < temp && l < h)
    {
        l++;
    }
    s[h] = s[l];

    s[l] = temp;
    return l;
}

void test_16(int s[], int length)
{
    int m = length;
    int l = 0, h = length - 1;
    while (m != 3)
    {
        m = partition_16(s, l, h);
        if (m < 3)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (i != 5)
        {
            printf("%d, ", s[i]);
        }
        else
        {
            printf("%d]\n", s[i]);
        }
    }
}


//19单链表 环序
test_19(LinkedList l) {
     
}