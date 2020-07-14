#include <iostream>
#include <fstream> 
using namespace std; 

int gcd(int, int); 
int factor(int);

int main(int argc, char **argv) 
{ 
	int a, b, times;
	ifstream ifile(argv[1],ios::in);
	ifile>>times;
	for(int i = 0; i < times; i++)
	{
		ifile>>a>>b;
		int c = gcd(a,b);
		if(c != 1)
		{	
			cout<<c<<" = ";
			factor(c);
		}
		else
			cout<<"1 = 1"<<endl;
	}
      

} 

int gcd(int m, int n) 
{ 
    return n == 0? m : gcd(n, m % n); 
}

int factor(int num)
{

	for(int x = 2; x <= num; x++)
	{
		while(num % x == 0)
		{
			if(num % (x * x) == 0)
			{
				int sum = 0;
				do{
					sum++;
					num /= x;
				}while(num % x == 0);
				cout<<x<<"^"<<sum;
			}
			else
			{
				cout<<x;
				num /= x;
			}
			if(num>1)
			{
				cout<<"*";
			}
		}
	}
	cout<<endl;
}