#include<bits/stdc++.h>
using namespace std;

int partition(int *a, int s, int e)
{
  int i = s-1;
  int j = s;

  // Declare pivot element as last element
  int pivot = a[e];

  // Element smaller than pivot are store in region-1
  for( ; j<=e-1 ; j++)
  {
    if(a[j]<=pivot)
    {
      swap(a[++i],a[j]);
    }
  }

  // Putting pivot at its correct position
  swap(a[i+1],a[e]);

  // Returning the index of pivot element
  return i+1;
}


void quicksort(int *a, int s, int e)
{
  // Base Case
  if(s>=e)
    return;

  // Getting pivot index
  int p = partition(a,s,e);

  // Recursive Case
  // Left Part
  quicksort(a,s,p-1);
  // Right Part
  quicksort(a,p+1,e);
}


int main()
{
  int arr[] = {3,2,1,4,56,3};
  int n = sizeof(arr)/sizeof(arr[0]);

  quicksort(arr,0,n-1);

  for(auto i:arr)
    cout<<i<<" ";

}
© 2020 GitHub, Inc.
