#include<iostream>
#include<conio.h>
using namespace std;
class abc
{
private:
	int *a,n,m;
public:
	int ktra()
	{
		int b[m];int t=0,tt=0; 
		for(int i = 1 ; i <= m ; i++)
		{
			b[i]=n-m+i;
			t+=b[i];
			tt+=a[i]; 
		}
		for(int i = 1 ; i <= m ; i++)
		{
			if(a[i]>b[i] || tt>=t)
			{
				return 0; 
			}
		}
	}
	void daycon()
	{
		cout<<"nhap so ptu day cha: ";cin>>n;
		do
		{
			cout<<"nhap so ptu day con: ";cin>>m;
			if(m>n)
			{
				cout<<"so nhap ko hop le"<<'\n';
			}
		}while(m>n);
		a = new int [m]; 
		cout<<"nhap 1 day con:"<<'\n';
		do
		{
			cout<<m<<'\n';
			for(int i = 1 ; i <= m ; i++)
			{
				cout<<"nhap a["<<i<<"]= ";cin>>a[i];
			}
			if(ktra()==0)
			{
				cout<<"Day nhap ko hop le."<<'\n';
			}
		}while(ktra()==0);
	}
	void xuat()
	{
		cout<<"day con ke tiep la: ";
		for(int i = 1 ; i <= m ; i++)
		{
			cout<<a[i]<<"  ";
		}
		cout<<'\n'; 
	}
	void abcd()
	{
		int i=m;
		while(a[i]==n-m+i)
		{
			i--;
		}
		a[i]=a[i]+1;
		for(int j = i + 1 ; j<=m ; j++)
		{
			a[j]=a[i] + j - i;
		}
	}
	~abc()
	{
		delete[] a; 
		n=0;m=0; 
	} 
};
int main()
{
	abc a;int l; 
	a.daycon();
	cout<<"nhap so lan sinh: ";cin>>l;
	for(int i = 0 ; i < l ; i++)
	{
		a.abcd();
		a.xuat(); 
		if(a.ktra()==0)
		{
			break; 
		} 
	} getch();
	return 0;
 } 
