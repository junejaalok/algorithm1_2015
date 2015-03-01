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
 	return vec[1];
}

vector<int> heads (vector<vector<int> > vec) {
	vector<int> temp;
	int i=0;
	while (i<vec.size()) {
		temp.push_back(vec.at(i).at(0));
		i++;
	}
	return temp;
}

int findindx (vector<vector<int>>& vec, int val) {
	vector<int> hd = heads(vec);
	auto it=find(hd.begin(), hd.end(), val);
	auto pos= it - hd.begin();
	return pos;
}

vector<int> tail (vector<int> vec) {
	vector <int> temp;
	for (auto it = vec.cbegin()+1; it != vec.cend(); ++it) {
		temp.push_back(*it);
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
		int idx=findindx(vec,*it);
		replace(vec[idx].begin()+1, vec[idx].end(), org, sub);
	}
}

void selfloop (vector<vector<int>>& vec,int frval) {
		int idx=findindx(vec,frval);
		vec[idx].erase(remove(vec[idx].begin()+1, vec[idx].end(), frval), vec[idx].end());
}

int mincut(vector<vector<int>> vertex) {
	while (vertex.size() > 2 ) {
		vector<int> hd = heads(vertex);
//		printme(hd);
//		cout << "----------" << endl;
		int c=0;
//		while(c<vertex.size()) {printme(vertex[c]);c++;}
//		cout << "----------" << endl;
		//cout << "hd size: " << hd.size() << endl;
	//	int frval=1;
		int frval=ranval(hd);
		int frst=findindx(vertex,frval);
		cout << "frst " << frval << " at " << frst << endl;
	//	printme(vertex[frst]);
	//	cout << "----------" << endl;
		int scval=ranval(tail(vertex[frst]));
	//	int scval=2;
		int scnd=findindx(vertex,scval);
	//	cout << "scnd " << scval << " at " << scnd << endl;
//		printme(vertex[frst]);
//		printme(vertex[scnd]);
		cout << "----------" << endl;
		cout << frval << " - " << scval << endl;
		cout << "----------" << endl;

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
//		while(b<vertex.size()) {printme(vertex[b]);b++;}
//		cout << "----------" << endl;
		replace(vertex,scnd,scval,frval);
		b=0;
//		while(b<vertex.size()) {printme(vertex[b]);b++;}
//		cout << "----------" << endl;
		selfloop(vertex,frval);
		b=0;
//		while(b<vertex.size()) {printme(vertex[b]);b++;}
//		cout << "----------" << endl;
		deleteme(vertex,scnd);
		b=0;
//		while(b<vertex.size()) {printme(vertex[b]);b++;}
//		cout << "----------" << endl;
		cout << "###################" << endl;
	}
	return vertex[0].size()-1;
}

int main()
{
	string line;
	int z=0;
	int val=8;
	vector<vector<int>> vertex(val);
	ifstream myfile("t2.txt");
//	ifstream myfile("example.txt");
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
	
	cout << mincut(vertex) << endl;
	int x=0;
	int run=100;
	int mcut[run];
	while (x<run) {
		mcut[x]=mincut(vertex);
		x++;
		cout << "++++++++++++++++++++++++++++++++++" << endl;
	}

	for (int i=0;i<run;i++) {cout << mcut[i] << " ";}
	cout << endl;

	return 0;
}
