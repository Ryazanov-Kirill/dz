
#include <random>
#include "windows.h"
#include <iostream>
#include <ctime>


#include <stdlib.h>
#include <stdio.h>



using namespace std;

void  filling_array(int* array, int size)
{
    for(int i=0; i<size; i++){
        array[i]=rand() % 1000;
    }
}
void bubble_sort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                int buf = array[j];
                array[j]=array[j+1];
                array[j+1]=buf;

            }
        }
    }
}
void InsertSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        int key = i + 1;
        int temp = array[key];
        for (int j = i + 1; j > 0; j--) {
            if (temp < array[j - 1]) {
                array[j] = array[j - 1];
                key = j - 1;
            }
        }
        array[key] = temp;
    }
}
void SelectionSort(int * array, int size) {
    int count, key;
    for (int i = 0; i < size - 1; i++) {
        count = array[i];
        key = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[key]) key = j;
        if (key != i) {
            array[i] = array[key];
            array[key] = count;
        }
    }
}
void qsortRecursive(int *array, int size) {
    int i = 0;
    int j = size - 1;

    int mid = array[size / 2];


    do {

        while(array[i] < mid) {
            i++;
        }
        while(array[j] > mid) {
            j--;
        }


        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);



    if(j > 0) {

        qsortRecursive(array, j + 1);
    }
    if (i < size) {

        qsortRecursive(&array[i], size - i);
    }
}
void Merge(int arr[], int minIndex, int middleIndex, int maxIndex) {
    int left = minIndex;
    int right = middleIndex + 1;
    int count = maxIndex - minIndex + 1;
    int *tempArray= new  int[maxIndex+1];
    int index = 0;

    while ((left <= middleIndex) && (right <= maxIndex))
    {
        if (arr[left] < arr[right])
        {
            tempArray[index] = arr[left];
            left++;
        }
        else
        {
            tempArray[index] = arr[right];
            right++;
        }

        index++;
    }

    for (int i = left; i <= middleIndex; i++)
    {
        tempArray[index] = arr[i];
        index++;
    }

    for (int i = right; i <= maxIndex; i++)
    {
        tempArray[index] = arr[i];
        index++;
    }

    for (int i = 0; i < count; i++)
    {
        arr[minIndex + i] = tempArray[i];
    }
    delete []tempArray ;
}

void MergeSort(int arr[], int minIndex, int maxIndex) {
    if (minIndex < maxIndex) {
        int middleImdex = (minIndex + maxIndex) / 2;
        MergeSort(arr, minIndex, middleImdex);
        MergeSort(arr, middleImdex + 1, maxIndex);
        Merge(arr, minIndex, middleImdex, maxIndex);
    }
}
void comb(int array[], int size)
{
    double factor = 1.2473309;
    int step = size - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < size; i++)
        {
            if (array[i] > array[i + step])
            {
                int tmp = array[i];
                array[i] = array[i+step];
                array[i+step] = tmp;
            }
        }
        step /= factor;
    }
}


void ShakerSort(int *array, int Start, int size)
{
    int Left, Right, i;
    Left=Start;
    Right=size-1;
    while (Left<=Right)
    {
        for (i=Right; i>=Left; i--)
            if (array[i-1]>array[i]){
                int temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;;}
        Left++;
        for (i=Left; i<=Right; i++)
            if (array[i-1]>array[i]){
                int temp=array[i];
                array[i]=array[i-1];
                array[i-1]=temp;
            };
        Right--;
    }
}



int main() {
    FILE* f1;
    f1= fopen("quick_sort.dat","w");

    srand(time(0));
    for (int i=0;i<5000000     ;i+=100000)
    {
        int* arr = new int[i];

        filling_array(arr, i);
        long int time = GetTickCount64();
        bubble_sort(arr, i);
        time = (GetTickCount64() - time);
        fprintf(f1, "%d\t%d\n", i, time);
        filling_array(arr, i);
        time = GetTickCount();
        InsertSort(arr, i);
        time = (GetTickCount64() - time);
        fprintf(f1, "%d\t%d\n",i, time);
        filling_array(arr, i);
        time = GetTickCount();
        SelectionSort(arr, i);
        time = (GetTickCount64() - time);
        fprintf(f1, "%d\t%d\n",i, time);
        filling_array(arr,i);time = GetTickCount();
        qsortRecursive(arr,i);
        time= (GetTickCount64() - time);
        fprintf(f1,"%d\t%d\n",i,time);
        filling_array(arr,i);
        time = GetTickCount();
        MergeSort(arr, 0, i-1);
        time= (GetTickCount64() - time);
        fprintf(f1,"%d\t%d\n",i,time);
        filling_array(arr,i);
        time = GetTickCount();
        comb(arr,i);
        time= (GetTickCount64() - time);
        fprintf(f1,"%d\t%d\n",i,time);
        filling_array(arr,i);
        time = GetTickCount();
        ShakerSort(arr,1,i);
        time= (GetTickCount64() - time);

        fprintf(f1,"%d\t%d\n",i, time);

        delete [] arr;
        cout<<i<<endl;

    }
    fclose(f1);
    return 0;
}