#include <iostream>
#include <unordered_map>
#include <cstddef>
#include <cstdint>
#include <vector>
using namespace std;

class HeapTracker {
private:
	// initializing
	unordered_map<void*, size_t> allocations; // pointer -> size
	size_t totalAllocated = 0;
	size_t peakUsage = 0;
	size_t totalAllocations = 0;
	size_t totalDeallocations = 0;

public:
	// allocation
	void* allocate(size_t size) {
		void* ptr = new char[size]; // allocate memory on heap
		allocations[ptr] = size;    // store pointer + size
		totalAllocated += size;     // update current usage
		if (totalAllocated > peakUsage) { // track peak
			peakUsage = totalAllocated;
		}
		totalAllocations++;         // increment allocation count
		return ptr;                 // return memory to caller

		cout << "Allocated: " << ptr << "(decimal: " << reinterpret_cast<uintptr_t>(ptr) << ")" << endl;
		cout << endl;
	}

	// deallocation
	void deallocate(void* ptr) {
		auto it = allocations.find(ptr);
		if (it != allocations.end()) {
			totalAllocated -= it->second;  // subtract size
			totalDeallocations++;          // increment deallocation count
			delete[] static_cast<char*>(ptr);  // free memory
			allocations.erase(it);         // remove from map
		}
		else {
			cerr << "Warning: Attempting to free untracked pointer " << ptr << endl;
		}
	}


	// report
	void report() const {
		cout << "Total allocations: " << totalAllocations << endl;
		cout << "Total deallocations: " << totalDeallocations << endl;
		cout << "Peak heap usage: " << peakUsage / 1024 << " KB" << endl;

		if (!allocations.empty()) {
			cout << "Potential memory leak detected for " << allocations.size() << " block(s):" << endl;
			for (const auto& [ptr, size] : allocations) {
				cout << " Address: " << ptr << " (decimal: " << reinterpret_cast<uintptr_t>(ptr) << "), Size: " << size << " bytes" << endl;
			}
		}
		cout << endl;
	}

	~HeapTracker() {
		for (auto& [ptr, size] : allocations) {
			delete[] static_cast<char*>(ptr);
		}
	}
};