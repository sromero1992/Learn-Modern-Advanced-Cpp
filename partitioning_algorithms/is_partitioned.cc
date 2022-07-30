#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vec(const vector<int>& vec) {
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;
}

int main() {
	vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 8};
	auto is_odd = [](int n) {return n % 2 == 1;};

	cout << "vec: ";
	print_vec(vec);
	
	// Are all the odd elements at the front of the vector?
	if (is_partitioned(cbegin(vec), cend(vec), is_odd))
		cout << "vec is partitioned by oddness\n";
	else
		cout << "vec is not partitioned by oddness\n";
	
	// Partition: move odd elements to the front of the vector
	partition(begin(vec), end(vec), is_odd);
	
	cout << "vec after partition(): ";
	print_vec(vec);
	
	// Are all the odd elements at the front of the vector?
	if (is_partitioned(cbegin(vec), cend(vec), is_odd))
		cout << "vec is partitioned by is_odd\n";
	else
		cout << "vec is not partitioned by is_odd\n";
}