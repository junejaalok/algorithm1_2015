#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int merge(int a[],int na,int b[],int nb,int c[]) {
	int i=0;
	int j=0;
	int k=0;
	int count=0;

	while(i<na && j<nb) {
		if (a[i]<b[j]) {
			c[k]=a[i];
			i++;
		}
		else {
			c[k]=b[j];
			j++;
			count = count + na - i;
		}
		k++;
	}
	
	while (i<na) {
		c[k]=a[i];
		i++;
		k++;	
	}
	while (j<nb) {
		c[k]=b[j];
		j++;
		k++;
	}
	return count;
	
}
long inversion(int a[],int n) {
	if (n>1) {
		int mid=n/2;
		long c1=inversion(a,mid);
		long c2=inversion(a+mid,n-mid);
		int temp[n];		
		long c3=merge(a,mid,a+mid,n-mid,temp);
		for (int x=0;x<n;x++) {
			a[x]=temp[x];
		}
		return c3+c2+c1;
	}
	else	
		return 0;
}


int main()
{
	//int a[]={1,2,3};
	//int a[]={1,3,5,2,4,6};
	//int a[]={1,6,3,2,4,5};
	//int a[]={ 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };
	//int a[]={5,4,3,2,1};
	//int a[]={23,5,25,18,11,4,23,4,17,7};
	//int a[]={9,12,3,1,6,8,2,5,14,13,11,7,10,4,0};
	string line;
	int a[100000];
	int z=0;
	ifstream myfile("IntegerArray.txt");
	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			stringstream(line) >> a[z];
			//a[z]=val;
			//cout << val << endl;
			z++;
			 
		}
		myfile.close();
	}
	else 
		cout << "unable to open the file" << endl;
	
	int size=sizeof(a)/sizeof(a[0]);
	cout << "Hello:: " << inversion(a,size) << endl;
	return 0;
}

