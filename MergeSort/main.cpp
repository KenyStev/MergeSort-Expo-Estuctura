#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//int first(vector<int*> list);
//int last(vector<int*> list);
//vector<int*> rest(vector<int*> & list);
//vector<int*> mergeSort(vector<int*> & left,vector<int*> & right);
//vector<int*> mergeSort(vector<int*> & m);

//int first(int* list);
//int last(int* list);
//int* rest(int* list);
//int* mergeSort(int* left,int* right);
//int* mergeSort(int* m,);

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


/* UITLITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    vector<int*> unorder;

//    int nums[7] = {2,4,7,6,5,1,8};
//    for(int i=0;i<7;i++)
//        unorder.push_back(&nums[i]);

//    for(int i=0;i<unorder.size();i++)
//        cout<<*unorder[i]<<" ";

//    vector<int*> order = mergeSort(unorder);
//    cout<<endl;
//    cout<<"now: "<<order.size()<<endl;

//    for(int i=0;i<order.size();i++)
//    {
////        cout<<"SSADSDSD"<<endl;
//        cout<<*order[i]<<" ";
//    }

    int arr[] = {2,4,7,6,5,1,8};//{12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    return a.exec();
}

//int* mergeSort();


//vector<int*> mergeSort(vector<int*> & m)
//{
//    vector<int*> left, right, result;
//    if(m.size()<=1)
//        return m;
//    int middle = m.size()/2;

//    for(int i=0; i<middle;i++)
//        left.push_back(m[i]);
//    for(int i=middle; i<m.size();i++)
//        right.push_back(m[i]);

//    left = mergeSort(left);
//    right = mergeSort(right);
//    if(last(left) <= first(right))
//    {
////        left.insert(left.end(),right.begin(),right.end());
//        for(int i=0;i<right.size();i++)
//            left.push_back(right[i]);
//        return left;
//    }
//    result = mergeSort(left,right);
//    return result;
//}

//vector<int*> mergeSort(vector<int*> & left,vector<int*> & right)
//{
//    vector<int*> result;

//    while(left.size()>0 && right.size()>0)
//    {
//        if(first(left)!=INT_MIN && first(right)!=INT_MIN)
//        {
//            if(first(left) <= first(right))
//            {
//                int x = first(left);
//                result.push_back(&x);
//                left = rest(left);
//            }else{
//                int x = first(right);
//                result.push_back(&x);
//                right = rest(right);
//            }
//        }
//    }
//    if(left.size()>0)
//    {
//        int x = first(left);
//        result.push_back(&x);
//    }
//    if(right.size()>0)
//    {
//        int x = first(right);
//        result.push_back(&x);
//    }
//    return result;
//}

//int first(vector<int*> list)
//{
//    return *list[0];
//}

//int last(vector<int*> list)
//{
//    return *list[list.size()-1];
//}

//vector<int*> rest(vector<int*> & list)
//{
//    vector<int*> temp;
////    if(list.size()>1)
//        for(int i=1;i<list.size();i++)
//            temp.push_back(list[i]);
//    return temp;
//}
