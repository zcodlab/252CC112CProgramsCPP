#ifndef SORT_H
#define SORT_H
//Declaracion de la funcion Selection Sort
void selectionSort(int X[], int n);

//Declaracion de la funcion Bubble Sort
void bubbleSort(int X[], int n);

//Declaracion de la funcion Insertion Sort
void insertionSort(int X[], int n);

//Declaracion de la funcion Insertion Binary Sort
void insertionBinarySort(int X[], int n);

//Declaracion de la funcion QuickSort
void quickSort(int X[],int low, int high);
int particionar(int X[],int low, int high);

//Declaracion de la funcion mergeSort
void mergeSort(int X[],int left, int right);
void merge(int X[],int left, int mid,int right);


#endif // SORT_H
