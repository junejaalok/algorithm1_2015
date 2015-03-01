#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int Partition(int *A, int start, int end) {
	int pivot=A[start];
	int partitionIndex=start+1;
	cout << "pivot:: " << pivot << endl;

	for (int j=start+1;j<=end;j++) {
		cout << j << " :: " << A[j] << endl;
		if (A[j] <= pivot) {
			cout << "after:: " << A[j] << endl;
			swap(A[j],A[partitionIndex]);
			partitionIndex++;
			cout << "PartitionIndex::" << partitionIndex << endl;
		}
	}
	swap(A[partitionIndex-1],A[start]);
	cout << "partition:: " << partitionIndex-1 << endl;
	cout << "===========" << endl;
	return partitionIndex-1;
}


long QuickSort(int *A, int start, int end) {
	long cnt=end-start;
	cout << "start::" <<  start << " end:: " << end << endl;

	if (start < end) {
		cnt=end-start;
		int pIndex=Partition(A,start,end);
//		cout << "pIndex:: " << pIndex << endl;
		cnt += QuickSort(A,start,pIndex-1);
//			cnt = cnt + pIndex - 1 - start - 1;
//			cout << " left:: " << cnt << endl;
		cnt += QuickSort(A,pIndex+1,end);
//			cnt = cnt + end - pIndex - 1 - 1;
//			cout << " right:: " << cnt << endl;
	}
	else 
		cnt=0;
	//for (int i=0;i<cnt;i++) cout << A[i] << " ";
	cout << "return cnt:: " << cnt << endl;
	return cnt;
}


int main()
{
	//int a[]={4,3,1,2};
	//int a[]={5,3,1,2,4,6};
	//int a[]={1,6,3,2,4,5};
	//int a[]={ 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };
	//int a[]={5,4,3,2,1};
	//int a[]={23,5,25,18,11,4,23,4,17,7};
	//int a[]={9,12,3,1,6,8,2,5,14,13,11,7,10,4,0};
	string line;
	int a[10000];
	int z=0;
	ifstream myfile("QuickSort.txt");
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
	//cout << "size:: " << size << endl;
	cout << QuickSort(a,0,size-1) << endl;
	//for (int i=0;i<size;i++) cout << a[i] << " ";
	return 0;
}
