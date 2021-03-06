#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a,int s,int e,int *tree,int index)
{	//Base Case
	if(s==e)
	{
		tree[index]=a[s];
		return ;
	}

	int mid=(s+e)/2;
	buildTree(a,s,mid,tree,2*index);
	buildTree(a,mid+1,e,tree,2*index+1);

	tree[index]=min(tree[2*index],tree[2*index+1]);

	return ;
}


int query(int *tree,int ss,int se,int qs,int qe,int index)
{
	//complete overlap
	if(ss>=qs && se<=qe)
	{
		return tree[index];
	}
	//nooverlap
	if(qe<ss || qs >se)
	{
		return INT_MAX;
	}
	//partialoverlap

	int mid=(ss+se)/2;
	int left=query(tree,ss,mid,qs,qe,2*index);
	int right=query(tree,mid+1,se,qs,qe,2*index+1);

	return min(left,right);

}

void update(int *tree,int ss,int se,int i,int inc,int index)
{
	//CAse where the I is out of bound
	if(i>se || i<ss)
	{
		return ;
	}
	//leaf node
	if(ss==se)
	{
		tree[index]+=inc;
		return;
	}

	int mid=(ss+se)/2;
	update(tree,ss,mid,i,inc,2*index);
	update(tree,mid+1,se,i,inc,2*index+1);

	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;

}

void updateRange(int *tree,int ss,int se,int l ,int r,int inc,int index )
{
	//out of bound
	if(l>se || r<ss)
	{
		return;
	}
	//leaf node
	if(ss==se)
	{
		tree[index]+=inc;
		return ;
	}

	int mid=(ss+se)/2;
	updateRange(tree,ss,mid,l,r,inc,2*index);
	updateRange(tree,mid+1,se,l,r,inc,2*index+1);


	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

int main()
{
	int a[]={
1 ,4, 3, 5, 2};
	int n=sizeof(a)/sizeof(a[0]);

	int *tree=new int[4*n+1];
	buildTree(a,0,n-1,tree,1);

	//update(tree,0,n-1,3,-10,1);

	for(int i=1;i<14;i++)
	{

		cout<<tree[i]<<" ";
	}
cout<<endl<<endl;

	int q;
	cin>>q;

	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(tree,0,n-1,l,r,1)<<endl;



	}

/*
	for(int i=1;i<14;i++)
	{

		cout<<tree[i]<<" ";
	}


*/

	return 0;
}
