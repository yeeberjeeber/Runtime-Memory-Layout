#include <iostream>
using namespace std;

class Buffer {
private:
	char* data;
	size_t size;

public:
	Buffer(size_t size) {
		this->size = size;
		data = new char[size];
		cout << "Allocated " << size << " bytes" << endl;
		cout << endl;
	}

	// Creating a deep copy
	Buffer(const Buffer& other) {
		size = other.size;               // copies metadata from other
		data = new char[size];			 // allocates new memory
		memcpy(data, other.data, size);  // copies contents into the new destination data
	}

	// Copy assignment operator, overloading the = operator
	Buffer& operator=(const Buffer& other) {
		if (this == &other) {
			return *this;
		}

		delete[] data;

		size = other.size;
		data = new char[size];
		memcpy(data, other.data, size);

		return *this;
	}

	~Buffer() {
		delete[] data;
		cout << "Memory freed" << endl;
		cout << endl;
	}
};