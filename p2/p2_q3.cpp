#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int findingPI(int *A, int start,int end) {
	int num=3;
	int middle=(end-start)/2 + start;
	int idx[]={start,middle,end};
	cout << "middle  " << (end-start)/2 + start << endl;
	cout << "index" << endl;
	for (int i=0;i<3;i++) cout << idx[i] << " ";
	cout << endl;
	cout << "values" << endl;
	for (int i=0;i<3;i++) cout << A[idx[i]] << " ";

	if ((A[idx[0]] > A[idx[1]] && A[idx[0]] < A[idx[2]]) || (A[idx[0]] < A[idx[1]] && A[idx[0]] > A[idx[2]])) return idx[0];
	else if ((A[idx[1]] > A[idx[0]] && A[idx[1]] < A[idx[2]]) || (A[idx[1]] < A[idx[0]] && A[idx[1]] > A[idx[2]])) return idx[1];
	else return idx[2];
}

int Partition(int *A, int start, int end) {
	int len = end - start +1;
	cout << "length is:: " << len << endl;
	if (len >=3) {
		int ind=findingPI(A,start,end);
		cout << "value:: " << A[ind] << endl;
		swap(A[start],A[ind]);
	}
	int pivot=A[start];
	int partitionIndex=start+1;
	cout << "pivot:: " << pivot << endl;
	cout << "Before partition"<< endl;
	for (int i=0;i<100;i++) cout << A[i] << " ";
	cout << endl;
	for (int j=start+1;j<=end;j++) {
		cout << j << " :: " << A[j] << endl;
		if (A[j] <= pivot) {
			cout << "after:: " << A[j] << endl;
			swap(A[j],A[partitionIndex]);
			cout << "PartitionIndex_before::" << partitionIndex << endl;
			partitionIndex++;
			cout << "PartitionIndex_after::" << partitionIndex << endl;
		}
			cout << "Runtime" << endl;
			for (int i=0;i<100;i++) cout << A[i] << " ";
			cout << endl;
	}
	swap(A[start],A[partitionIndex-1]);
	cout << "partition:: " << partitionIndex-1 << endl;
	cout << "===========" << endl;
	return partitionIndex-1;
}


long QuickSort(int *A, int start, int end) {
	long cnt;
	cout << "start::" <<  start << " end:: " << end << endl;

	if (start < end) {
		cnt=end-start;
	cout << "--------------------------------return cnt:: " << cnt << endl;
		int pIndex=Partition(A,start,end);
		cout << "pIndex:: " << pIndex << endl;
		cout << "After partition" << endl;
		for (int i=0;i<100;i++) cout << A[i] << " ";
		cout << endl;
		cout << "------------------ Going left" << endl;
		cnt += QuickSort(A,start,pIndex-1);
		cout << "------------------ Back left" << endl;
		cout << "------------------ Going right" << endl;
		cnt += QuickSort(A,pIndex+1,end);
		cout << "------------------ Back right" << endl;
	}
	else 
		cnt=0;
	return cnt;
}


int main()
{
	//int a[] = {4,5,6,7};
	//int a[] = {8,2,4,5,7,1};
	//int a[]={3,8,2,5,1,4,7,6};
	//int a[]={6,5,4,3,2,1};
	//int a[]={5,3,1,2,4,6};
	//int a[]={1,6,3,2,4,5};
	//int a[]={ 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };
	//int a[]={5,4,3,2,1};
	//int a[]={23,5,25,18,11,4,23,4,17,7};
	//int a[]={9,12,3,1,6,8,2,5,14,13,11,7,10,4,0};
	string line;
	int a[10000];
	//int a[1000];
	int z=0;
	ifstream myfile("QuickSort.txt");
	//ifstream myfile("t1000.txt");
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
	//findingPI(a,0,size-1);// << endl;
	//cout << "final vector " << endl;
//	for (int i=0;i<size;i++) cout << a[i] << " ";
	return 0;
}
