#include <iostream>
#include <cstdint>
using namespace std;

int initializedGlobal = 42;
int uninitializedGlobal;

void sampleFunction() {}

void recurse(int depth) {
	int var;
	uintptr_t varAddr = reinterpret_cast<uintptr_t>(&var);
	cout << "Depth " << depth << " address: " << &var << endl;
	cout << "Depth " << depth << " value: " << varAddr << endl;
	cout << endl;
	if (depth < 5) {
		recurse(depth + 1);
	}
}

int main() {
	recurse(1);
	cout << endl;

	int stackVar = 5;
	int* heapVar = new int(100);

	static int initializedStatic = 10;
	static int uninitializedStatic;

	cout << "Initialized Data Segment " << endl;
	cout << " initializedGlobal: " << &initializedGlobal << endl;
	cout << " initializedStatic: " << &initializedStatic << endl;
	cout << endl;
	cout << "BSS Segment (Uninitialized data) " << endl;
	cout << " uninitializedGlobal: " << &uninitializedGlobal << endl;
	cout << " uninitializedStatic: " << &uninitializedStatic << endl;
	cout << endl;
	cout << "Stack Segment " << endl;
	cout << " stackVar: " << &stackVar << endl;
	cout << endl;
	cout << "Heap Segment " << endl;
	cout << " heapVar: " << heapVar << endl;
	cout << endl;
	cout << "Text Segment (function) " << endl;
	cout << " sampleFunction: " << reinterpret_cast<void*>(&sampleFunction) << endl;
	cout << endl;

	delete heapVar;
	return 0;
}