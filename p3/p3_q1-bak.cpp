#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

int ranval(vector<int> vec) {
	random_device random_dev;
	mt19937 generator(random_dev());
	shuffle(vec.begin(), vec.end(), generator);
	//cout << vec[0] << " ::: " << vec[1] << endl; 
 	return vec[1];
}

vector<int> heads (vector<vector<int> > vec) {
	vector<int> temp;
	int i=0;
	while (i<vec.size()) {
//		cout << "at" << i << " value is " << vec.at(i).at(0) << endl;
		temp.push_back(vec.at(i).at(0));
		i++;
	}
	return temp;
}

int findindx (vector<vector<int>>& vec, int val) {
	vector<int> hd = heads(vec);
//	cout << " I am here" << endl;
//	printme(hd);
//	cout << " I am out" << endl;
	auto it=find(hd.begin(), hd.end(), val);
	auto pos= it - hd.begin();
//	cout << pos << " pos " << endl;
	return pos;
}

vector<int> tail (vector<int> vec) {
	vector <int> temp;
	for (auto it = vec.cbegin()+1; it != vec.cend(); ++it) {
		temp.push_back(*it);
		//cout << ' ' << *it;
	}
	return temp;
}

void printme (vector<int> vec) {
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		cout << *it << ' ' ;
	}
	cout << endl;
}

void deleteme (vector<vector<int>>& vec,int row) {
	vec.erase(vec.begin()+row);
}

void replace (vector<vector<int>>& vec,int scnd, int org, int sub) {
	for (auto it = vec[scnd].cbegin()+1; it != vec[scnd].cend(); ++it) {
	//	cout << *it << endl;
		int idx=findindx(vec,*it);
		replace(vec[idx].begin()+1, vec[idx].end(), org, sub);
	}
}

void selfloop (vector<vector<int>>& vec,int frval) {
//	for (auto it = vec[frst].cbegin()+1; it != vec[frst].cend(); ++it) {
		int idx=findindx(vec,frval);
		vec[idx].erase(remove(vec[idx].begin()+1, vec[idx].end(), frval), vec[idx].end());
//		replace(vec[*it].begin(), vec[*it].end(), frst, sub);
//	}
}


int main()
{
	string line;
	int z=0;
	vector<vector<int>> vertex(4);
	ifstream myfile("example.txt");
//	ifstream myfile("KargerMinCut.txt");
	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			stringstream temp (line);
			int i;
			while (temp >> i) {
				vertex[z].push_back(i);
			}
			z++;
		}
		myfile.close();
	}
	else 
		cout << "unable to open the file" << endl;
	
	//int size=sizeof(vertex)/sizeof(vertex[0][0]);
	//cout << "size:: " << size << endl;
	vector<int> hd = heads(vertex);
	printme(hd);
	cout << "----------" << endl;
	int c=0;
	while(c<vertex.size()) {printme(vertex[c]);c++;}
	cout << "----------" << endl;
	//cout << "hd size: " << hd.size() << endl;
	int frval=1;
//	int frval=ranval(hd);
	int frst=findindx(vertex,frval);
//	cout << "frst " << frval << " at " << frst << endl;
//	printme(vertex[frst]);
//	cout << "----------" << endl;
//	int scval=ranval(tail(vertex[frst]));
	int scval=2;
	int scnd=findindx(vertex,scval);
//	cout << "scnd " << scval << " at " << scnd << endl;
	printme(vertex[frst]);
	printme(vertex[scnd]);
	cout << "----------" << endl;
	cout << frval << " - " << scval << endl;
	cout << "----------" << endl;
	vector<int> tlscnd=tail(vertex[scnd]);

//	printme(tlscnd);
//	cout << "----------" << endl;
//	cout << vertex[frst].at(0) << endl;
//	printme(vertex[frst]);
//	cout << vertex[frst].size() << endl;
//	cout << tlscnd.size() << endl;
//	vertex[frst].reserve(vertex[frst].size() + tlscnd.size());
//	vertex[frst].insert(vertex[frst].end(), tlscnd.begin(), tlscnd.end());

//	frval=1;
//	scval=2;
//	frst=findindx(vertex,frval);
//	scnd=findindx(vertex,scval);

	vertex[frst].insert(vertex[frst].end(), vertex[scnd].begin(), vertex[scnd].end());
//	printme(vertex[frst]);
//	cout << vertex[frst].size() << endl;
//	cout << "----------" << endl;
//	cout<<vertex.size()<< endl;
//	cout<<vertex.size()<< endl;
	int b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	replace(vertex,scnd,scval,frval);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	selfloop(vertex,frval);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	deleteme(vertex,scnd);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;

	frval=1;
	frst=findindx(vertex,frval);
	scval=4;
	scnd=findindx(vertex,scval);
	printme(vertex[frst]);
	printme(vertex[scnd]);
	cout << "----------" << endl;
	cout << frval << " - " << scval << endl;
	cout << "----------" << endl;

	vertex[frst].insert(vertex[frst].end(), vertex[scnd].begin(), vertex[scnd].end());
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	replace(vertex,scnd,scval,frval);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	selfloop(vertex,frval);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;
	deleteme(vertex,scnd);
	b=0;
	while(b<vertex.size()) {printme(vertex[b]);b++;}
	cout << "----------" << endl;

//	cout << prt1[0] << endl;
//	for (int i=1cout << *vertex[scnd] << endl;
//	cout << ranval2(prt) << endl;
//	while (i<prt.size()) {cout << prt.at(30);i++;}
	//cout << ranval2(prt) << endl;
//	cout << prt.at(2);
//	ver(vertex);
//	cout << QuickSort(a,0,size-1) << endl;
	//findingPI(a,0,size-1);// << endl;
	//cout << "final vector " << endl;
//	for (int i=0;i<size;i++) cout << a[i] << " ";
	return 0;
}
