#include <iostream>
using namespace std;

void printCoOrd(int r_temp,int r_i,int r_count)
{
	int colnum,k;
	colnum = r_temp+r_count;
	for(k=r_temp;k<colnum;k++)
	{
		cout<<"("<<r_i<<","<<k<<")"<<"\t";
	}
	cout<<"\n";
}

int check(int a)
{
	if(a>=3)
	return a;
	else 
	return 0;
}

int main() {
	// your code goes here
	int i,j,row,col,a[100][100],count = 0,temp;
	cin>>row>>col;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cin>>a[i][j];
		}
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<a[i][j];
		}
	cout<<"\n";
	}
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		if(a[i][j] ==1)
			{
				count = count + 1;
				if(count ==1)
				{
					temp = j; //checks the statrt of co-ordinate
				}
			}
			else
			{
			if(count>=3)
		{
			printCoOrd(temp,i,count);
			count =0;
			temp =0 ;
		}
			else
			{
				count =0;
				temp =0;
			}
			}
			//count = check(count);
	
		
		}
		if(count>=3)
		{
			printCoOrd(temp,i,count);
		}
		count =0;
		temp =0;
	}
	return 0;
}
