#include<iostream>
using namespace std;


void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;



}
//Selection Sort
void selection_sort(int a[],int n )
{

	for(int i=0;i<n-1;i++)
	{
		//find out the smallest element index in the unsorted part
		int min_idx=i;
		for(int j=i;j<=n-1;j++)
		{
			if (a[j]<a[min_idx])
			{
				min_idx=j;
			}

		}
	//After this we can swap elements
		swap(a[i],a[min_idx]);

	}



}




int main()
{
	int a[1000];
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	selection_sort(a,n);

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}


	return 0;
}
