#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

/*void alok (vector<vector<int>>& v, int val ) {
	cout << "val " << val << endl;
	for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); it++) {
    if (find(it->begin(), it->end(), val)) {
        // I will remove the row in here
    }
}
}*/
 /*   int key = val;
    typedef std::vector< std::vector<int> >::iterator riter;
    for ( riter row = array.begin(), end = array.end(); row != end ; ++row ){
    	typedef std::vector<int>::iterator citer;
  		citer col = find(row->begin(), row->end(), key);
  		cout << "hello mr." << *col << endl;
    	if ( col != row->end() ) {
    		std::cout << "row " << row - array.begin()
    		<< ", col " << col - row->begin() << '\n';
    		//break;
    	}
    }
}*/

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

bool at0 (vector<vector<int>>& vec, int val) {
	cout << "check " << val << endl;
	cout << vec.size() << endl;
	for(int i=0;i<vec.size();i++) {
		if(vec[i][0]==val) return true;
		else return false;
		break;
	}
//	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
//		if (it[0]==val) return true;
//		else return false;
	//	col=(find((*it).begin(), (*it).end(), val) != (*it).end());
	//	cout << "my  " << col << endl;
	//	if (col) {
	//		return true;
	//	}
	//	else
	//		return false;
	}
//}
/*	cout << vec.size() << endl;
	for (int i=0; i<vec.size(); i++) {
		//cout << vec[i].at(0) << endl;
		if (vec[i][0] == val) {
			cout << "val " << val << " ans " << "true" << endl;
			return true;
		}
		else {
			cout << "val " << val << " ans " << "false" << endl;
			return false;
		}
	}*/
//	bool it=(find(vec.begin(), vec.begin(), val) != vec.begin());
//	cout << "val " << val << " ans " << it << endl;
//	return it;
//}

/*int findindx (vector<vector<int>>& vec, int val) {
	vector<int> hd = heads(vec);
	auto it=find(hd.begin(), hd.end(), val);
	auto pos= it - hd.begin();
	cout << "pos " << pos << endl;
	return pos;
}*/

/*int findindx (vector<vector<int>>& vec, int& val) {
	cout << "sez " << vec.size() << endl;
	for (auto hd = vec.begin(); hd != vec.end(); ++hd) {
		auto it=find((*hd).begin(), (*hd).begin(), val);
		//cout << hd[0] << endl;
		//cout << (*hd)[1] << endl;
		auto pos= it - (*hd).begin();
		cout << "pos " << pos << endl;
		return pos;
	}
}*/


vector<int> tail (vector<int> vec) {
	vector <int> temp;
	for (auto it = vec.cbegin()+1; it != vec.cend(); ++it) {
		temp.push_back(*it);
	}
	return temp;
}

//vector<vector<int>>& reverse(vector<vector<int>>& vec) {
/*void reverse(vector<vector<int>>& vec) {
	vector<vector<int>> rev;
	int row=vec.size();
	for (auto row = vec.begin(); row != vec.end(); ++row) {
 	   for (auto col = row->begin()+1; col != row->end(); ++col) {
 	   		rev[*col].push_back(rev[*col][0]);
            cout << "val " << *col;
	    }
    	cout << endl;
	}
}*/

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
	int y=0;
	int err = 0;
	int val=5105042;
	int intl=-1;
	int a;
	int b;
	vector<int> explored;
	vector<int>leader;
	vector<int> finish;

	vector<vector<int>> vertex(val);
	vector<vector<int>> rev_vertex(val);

	ifstream myfile("t1.txt");
	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			stringstream (line) >> a >> b;
			if (intl != a) {
				z++;
				intl=a;
			}
//			cout << "intl " << intl << endl;
			//cout << "a " << a << endl;
			//cout << "b " << b << endl;
			//cout << "z " << z << endl;
			//cout << "y " << y << endl;
			cout << "=========" << endl;
//			if (!ispresent(vertex[z],a,0)) vertex[z].push_back(a);
//			if (!ispresent(vertex[z],b,1)) vertex[z].push_back(b);
//			cout << "myans " << at0(rev_vertex,b) << endl;
			rev_vertex[b].push_back(a);
			printvec(rev_vertex[b]);
//			if (!at0(rev_vertex,b)) {
//				rev_vertex[y].push_back(b);
//				y++;
//			}
//			else {

//			}
	//		rev_vertex[y].push_back(b);
	//		rev_vertex.resize(y-1);
	//		while (!rev_vertex.empty()) {
//				at0(rev_vertex,b);
//				cout << "b " << b << endl;
//				cout << at0(vertex,b);
//				int rev_idx=findindx(rev_vertex,b);
//				cout << " :: " << rev_idx<< endl;
//				if (rev_idx==0) {
//					rev_vertex[y].push_back(b);
//					y++;
//				}
//				int nidx=findindx(rev_vertex,b);
//				cout << "nidx " << nidx << endl;
//				if (!ispresent(rev_vertex[nidx],a,1)) rev_vertex[nidx].push_back(a);
//				rev_vertex.resize(y+1);
				//printver(rev_vertex);
	//			cout << " :: " << rev_idx<< endl;
	//		}
			//else
			//	rev_vertex[z].push_back(b);

//			if(rev_idx<0) rev_vertex[z].push_back(b);
			//if (!ispresent(rev_vertex[rev_idx],a,1)) rev_vertex[rev_idx].push_back(a);
//			if (!at0(rev_vertex,b)) rev_vertex[z].push_back(b);
			//if (!ispresent(rev_vertex[z],a,1)) rev_vertex[z].push_back(a);
		}
		myfile.close();
	}
	else 
		cout << "unable to open the file" << endl;
//	vertex.resize(z+1);
//	rev_vertex.resize(z+1);
//	cout << "now " << vertex.size() << endl;
//	printvec(vertex[0]);
//	printver(vertex);
//	cout << "++++++++++++++++" << endl;
//	printver(rev_vertex);
//	cout << vertex.size() << endl;
//	DFS_loop(vertex,t,s,explored);
//	DFS(vertex,explored,leader,finish,9);
	//reverse(vertex);
	return 0;
}
