#include <iostream>
#include <conio.h>
using namespace std;


void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void bubbleSort(int *array, int size) {
   for(int i = 0; i<size; i++) {
      int swaps = 0;    
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {      
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            swaps = 1;    
         }
      }
      if(!swaps)
         break;       
   }
}
void insertionSort(int *array, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;  
   }
}
void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;  
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
        int temp = array[i];
        array[i] = array[imin];
        array[imin] = temp;
   }
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {      
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int partition (int *array, int low, int high)  
{  
    int pivot = array[high];   
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++)  
    {  
        if (array[j] < pivot)  
        {  
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;  
        }  
    }  
    int temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp; 
    return (i + 1);  
}  
void quickSort(int *array, int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(array, low, high);  
        quickSort(array, low, pi - 1);  
        quickSort(array, pi + 1, high);  
    }  
}  
void heapify(int *array, int n, int i) {
   int temp;
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && array[l] > array[largest])
      largest = l;
   if (r < n && array[r] > array[largest])
      largest = r;
   if (largest != i) {
      temp = array[i];
      array[i] = array[largest];
      array[largest] = temp;
      heapify(array, n, largest);
   }
}
void heapSort(int *array, int n) {
   int temp;
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(array, n, i);
   for (int i = n - 1; i >= 0; i--) {
      temp = array[0];
      array[0] = array[i];
      array[i] = temp;
      heapify(array, i, 0);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];   
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   bubbleSort(arr, n);
   cout << "Array after Bubble sort: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array after Insertion sort: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array after Selection sort: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Merge sort: ";
   display(arr, n);
   quickSort(arr, 0, n-1);
   cout << "Array after Quick sort: ";
   display(arr, n);
   heapSort(arr,n);
   cout << "Array after Heap sort: ";
   display(arr, n);
   getch();
}