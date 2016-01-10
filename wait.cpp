#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct unit{
	string name, sex;
	double r1, r2, f;
	bool operator >(unit &t)const {
		return f > t.f;
	}
};

int main(void) {
	// your code goes here
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		vector<unit> v1, v2;
		cin >> n >> m;
		double mr1 , mr2;
		mr1 = mr2 = 0;
		while (n--) {
			unit t;
			cin >> t.name >> t.sex >> t.r1 >> t.r2;
			mr1 = max(mr1, t.r1);
			mr2 = max(mr2, t.r2);
			v1.push_back(t);
			if (t.sex != "male") v2.push_back(t);
		}
		
		for (int i = 0; i < v1.size(); ++i) 
			v1[i].r1 *= (300 / mr1);
		for (int i = 0; i < v1.size(); ++i) 
			v1[i].r2 *= (300 / mr2);
		
		for (int i = 0; i < v1.size(); ++i) 
			v1[i].f = v1[i].r1 * 0.3 + v1[i].r2 * 0.7;
		
		sort(v1.begin(), v1.begin(), greater<unit>());
			
		cout << "The member list of Shandong team is as follows:" << endl;	
		for (int i = 0; i < v1.size(); ++i)
			cout << v1[i].name << " " << v1[i].sex << " " << v1[i].f << " " << endl;
		
	}
	return 0;
}





