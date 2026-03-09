#include <iostream>
using namespace std;

int initializedGlobal = 42;
int uninitializedGlobal;

void sampleFunction() {}

int main() {
	int stackVar = 5;
	int* heapVar = new int(100);

	static int initializedStatic = 10;
	static int uninitializedStatic;

	cout << "Initialized Data Segment: " << endl;
	cout << " initializedGlobal: " << &initializedGlobal << endl;
	cout << " initializedStatic: " << &initializedStatic << endl;

	cout << "BSS Segment (Uninitialized data): " << endl;
	cout << " uninitializedGlobal: " << &uninitializedGlobal << endl;
	cout << " uninitializedStatic: " << &uninitializedStatic << endl;

	cout << "Stack Segment: " << endl;
	cout << " stackVar: " << &stackVar << endl;

	cout << "Heap Segment: " << endl;
	cout << " heapVar: " << heapVar << endl;

	cout << "Text Segment: " << endl;
	cout << " sampleFunction: " << reinterpret_cast<void*>(&sampleFunction) << endl;

	delete heapVar;
	return 0;
}