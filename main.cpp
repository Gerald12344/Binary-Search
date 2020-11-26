#include <iostream>
#include <math.h>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int find = 4;
int arr[1001] = {};

int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      

    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
} 
int main() {
  bubbleSort(arr, sizeof(arr)/sizeof(arr[0]));  
  for (int i = 0; i <= 1000; i++) {
    srand(time(NULL));
    arr[i] = i + rand() % 20 + 1;;
  }
  std::cout << "What would you like to find? \n";
  std::string name;
  std::getline(std::cin, name);
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, std::stoi(name));
  if (result == -1) {
    std::cout << "Element is not present in array \n";
  } else {
    std::cout << "Element is present at index " << result << "\n";
  }
  return 0;
}