#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<set>

using namespace std;
int main() {
	fstream ifs("dictionary.txt");
	string str;
	vector<string>v;
	while (getline(ifs, str)) {
		if (str.length() < 3)
			continue;
		else
			v.push_back(str);
	}
	map<string, int>mp;
	for (int i = 0; i < v.size(); ++i) {
		string s = v[i].substr(v[i].length() - 3);
		mp[s] += 1;
	}
	vector<string>mp_key;
	vector<int>mp_value;
	map<string, int>::iterator number;
	int size = 0;
	for (number = mp.begin(); number != mp.end(); number++)
		size += 1;
	map<string, int>::iterator iend;
	for (iend = mp.begin(); iend != mp.end(); iend++) {
		mp_value.push_back(iend->second);
	}
	set<int>st;
	for (int j = 0; j < mp_value.size(); ++j) {
		st.insert(mp_value[j]);
	}
	set<int>::iterator ibegin;
	int count = 0;
	for (ibegin = st.begin(); ibegin != st.end(); ++ibegin) {
		count++;
	}
	vector<int>my_value;
	int total = 0;
	for (ibegin = st.begin(); ibegin != st.end(); ++ibegin) {
		total++;
		if (total <=count - 10) {
			continue;
		}
		else
			my_value.push_back(*ibegin);
	}
	vector<string>my_key;
	int start = 0;
	for (iend = mp.begin(); iend != mp.end(); ++iend) {
		for (int start = 0; start < my_value.size(); ++start) {
			if (iend->second == my_value[start]) {
				my_key.push_back(iend->first);
			}
		}
	}
	for (int m = 0; m < my_value.size(); ++m) {
		cout << my_key[m] << " " << my_value[m] << endl;
	}
	cin.get();
	return 0;
}