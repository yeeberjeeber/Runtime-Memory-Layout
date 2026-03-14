#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

void heapAllocation(int n) {
	vector<int*> heapAddresses; // declaring vectors

	for (int i = 0; i < n; i++) {
		int* ptr = new int(i);
		heapAddresses.push_back(ptr);

		uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
		cout << "Heap allocation " << i << ": " << ptr << " (decimal: " << addr << ")" << endl;
	}

	// Calculating heap growth
	for (size_t i = 1; i < heapAddresses.size(); ++i) {
		uintptr_t prev = reinterpret_cast<uintptr_t>(heapAddresses[i - 1]);
		uintptr_t curr = reinterpret_cast<uintptr_t>(heapAddresses[i]);

		ptrdiff_t diff = curr - prev;

		cout << "Heap grew by " << diff << " bytes from allocation " << i - 1 << " to " << i << endl;
	}

	// Clean up
	for (auto ptr : heapAddresses) {
		delete ptr;
	}
}