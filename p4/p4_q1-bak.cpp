#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

vector<int> heads (vector<vector<int>> vec) {
	vector<int> temp;
	int i=0;
//	cout << vec.size() << endl;
	while (i<vec.size()) {
		temp.push_back(vec.at(i).at(0));
		i++;
	}
	return temp;
}

void printvec (vector<int>& vec) {
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		cout << *it << ' ' ;
	}
	cout << endl;
}

void printver (vector<vector<int>>& vertex) {
	for (auto& x : vertex) {
        for (auto& y : x) {
            cout << y << ' ';
        }
        cout << endl;
    }
}

bool ispresent (vector<int>& vec, int val,int idx) {
	bool it=(find(vec.begin()+idx, vec.end(), val) != vec.end());
	return it;
}

int findindx (vector<vector<int>>& vec, int val) {
	vector<int> hd = heads(vec);
	auto it=find(hd.begin(), hd.end(), val);
	auto pos= it - hd.begin();
	cout << "pos " << pos << endl;
	return pos;
}

vector<int> tail (vector<int> vec) {
	vector <int> temp;
	for (auto it = vec.cbegin()+1; it != vec.cend(); ++it) {
		temp.push_back(*it);
	}
	return temp;
}

//vector<vector<int>>& reverse(vector<vector<int>>& vec) {
void reverse(vector<vector<int>>& vec) {
	vector<vector<int>> rev;
	int row=vec.size();
	for (auto row = vec.begin(); row != vec.end(); ++row) {
 	   for (auto col = row->begin()+1; col != row->end(); ++col) {
 	   		rev[*col].push_back(rev[*col][0]);
            cout << "val " << *col;
    }
    cout << endl;
}
//	for(int i=0;i<row;i++) {
//		for()
//		int node2=vec[idx][i];	

}

void DFS_loop(vector<vector<int>>& vertex, int& t, int& s, vector<int>& explored) {

	for (int i=vertex.size()-1;i>=0;--i) {
		cout << vertex[i][0] << ' ';
		if (!ispresent(explored,i,0)) {
			s=i;
//			DFS(vertex,vertex[i][0])
		}

	}

}

//void DFS(vector<vector<int>>& vec,int node) {
void DFS(vector<vector<int>>& vec,vector<int>& explored,vector<int>& leader,vector<int>& finish,int node,int& t) {
	//leader[node].push_back(s);
	explored.push_back(node);
	int idx=findindx(vec,node);
	cout << "idx " << idx << endl;
	for(int i=1;i<vec[idx].size();i++) {
		int node2=vec[idx][i];
		if (!ispresent(explored,node2,1)) {
			DFS(vec,explored,leader,finish,node2,t);
		}
	}
	t++;
	//finish[node].push_back(t);
}

int main()
{
	int t=0;
	int s=0;
	string line;
	int z=-1;
	int err = 0;
	int val=5105042;
	int intl=-1;
	int a;
	int b;
	vector<int> explored;
	vector<int>leader;
	vector<int> finish;

	vector<vector<int>> vertex(val);
	ifstream myfile("t1.txt");
	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			stringstream (line) >> a >> b;
			if (intl != a) {
				z++;
				intl=a;
			}
//			cout << "intl " << intl << endl;
//			cout << "a " << a << endl;
//			cout << "b " << b << endl;
//			cout << "z " << z << endl;
//			cout << "=========" << endl;
			if (!ispresent(vertex[z],a,0)) vertex[z].push_back(a);
			if (!ispresent(vertex[z],b,1)) vertex[z].push_back(b);
		}
		myfile.close();
	}
	else 
		cout << "unable to open the file" << endl;
	vertex.resize(z+1);
//	cout << "now " << vertex.size() << endl;
//	printvec(vertex[0]);
	//printver(vertex);
//	cout << vertex.size() << endl;
//	DFS_loop(vertex,t,s,explored);
//	DFS(vertex,explored,leader,finish,9);
	reverse(vertex);
	return 0;
}
