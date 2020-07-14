#include<bits/stdc++.h>
using namespace std;

void merge(int *a, int s, int e)
{
  int i = s;
  int mid = (s+e)/2;
  int j = mid+1;
  int k=s;

  int temp[100];

  // 2. Sorting of elements
  while(i<=mid and j<=e)
  {
    if(a[i]<a[j])
      temp[k++] = a[i++];

    else
      temp[k++] = a[j++];
  }

  while(i<=mid)
    temp[k++] = a[i++];

  while(j<=e)
    temp[k++] = a[j++];

  // 3. Original Array
  // Coping temp array to original array
  for(int i=s ; i<=e ; i++)
    a[i] = temp[i];
}


void mergeSort(int *a, int s, int e)
{
  // Base Case
  if(s>=e)
    return;

  // Follow 3 steps
  // 1. Divide
  int mid = (s+e)/2;

  // Recursively the arrays - s-mid and mid+1-e
  mergeSort(a,s,mid);
  mergeSort(a,mid+1,e);

  // Merge two arrays
  merge(a,s,e);
}



int main()
{
  int arr[] = {3,4,1,2,5,9};
  int n = sizeof(arr)/sizeof(arr[0]);

  mergeSort(arr,0,n-1);

  for(auto i:arr)
    cout<<i<<' ';
}
