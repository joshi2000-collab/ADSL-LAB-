#include <iostream>
#define N 5

using namespace std; 

class OBST
{
	int p[N],q[N],keys[N],
		c[N][N],w[N][N],r[N][N],n;

public:
	OBST()
	{
		cout<<"Enter number of elements >>";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter p["<<i+1<<"] >>";
			cin>>p[i];
			cout<<"Enter key["<<i+1<<"] >>";
			cin>>p[i];
		}
		for(int i=0;i<=n;i++)
		{
			cout<<"Enter q["<<i<<"] >>";
			cin>>q[i];
		}
		
	}
	void construct()
	{
		int x;
		for(int i=0;i<n;i++)
		{
			w[i][i]=q[i];
			c[i][i]=0;
			r[i][i]=0;
		}
		for(int diff=1;diff<=n;diff++)
		{
			int j=0;
			for(int i=0;i<n;i++)
			{
				j=i+diff;
				if(j<=n)
				{
					w[i][j]=w[i][j-1]+p[j]+q[j];
					int min =9999;
					for(int k=i+1;k<=j;k++)
					{
						c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
						if(c[i][j]<min)
							min=c[i][j],x=k;
					}
					c[i][j]=min;
					r[i][j]=x;
				}
			}
		}
		cout<<"COST : "<<c[0][n]
			<<"\nRoot : "<<keys[r[0][n]]
			<<endl;

	}
};

int main()
{
	cout<<"OBST";
	OBST o;
	o.construct();
}
