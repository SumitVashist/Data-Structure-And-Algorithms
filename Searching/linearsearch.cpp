#include<iostream>
using namespace std;

int linearsearch(int a[],int n,int key)
{
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==key)
			return i;
	
	}
	return -1;


} 


int main()
{	
	
	int n;
	cout<<"Enter no of elements "<<endl;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<endl<<"Enter the element you want to search : ";
	int key;
	cin>>key;
	int result=linearsearch(a,n,key);
	if(result==-1)
		cout<<"Element does not exists";
	else
		cout<<"Element found at  index  "<<result;
		
		
	
	
	
	return 0;
}
