#include <iostream>
#include <unordered_set>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

const long long MAX_NUM = 1000000000;
const long long MIN_NUM = 0;

int main() {
	unordered_set <int> sset;
	default_random_engine gen;
	uniform_int_distribution <long long> distr(MIN_NUM, MAX_NUM);
	for(int i = 0; i < 100000; i++) {
		sset.insert(distr(gen));
	}
	int counter = 10;
/*	for(long long i = MAX_NUM; i > MIN_NUM; --i) {
		long long c = sset.count(i);
		for(int j = 0; j < c; j++) {
			counter--;
			cout << i << " ";
			if(counter == 0)
				break;
		}
		if(counter == 0)
			break;
	}*/
	vector<long long> vect;
	for(auto i : sset) {
		if(vect.size() < 10) {
			vect.push_back(i);
			sort(vect.begin(), vect.end());
		}
		else {
			for(int j = vect.size() - 1; j >= 0; j--) {
				if(vect[j] < i) {
					for(int k = 0; k < j; k++) {					
						vect[k] = vect[k+1];		
					}
					vect[j] = i;
				}
				break;
			}
		}
	}
	for(auto i = vect.rbegin(); i != vect.rend(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}
