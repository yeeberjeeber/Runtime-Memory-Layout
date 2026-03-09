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
	int* heapVar2 = new int(110);
	int* heapVar3 = new int(120);
	int* heapVar4 = new int(130);
	int* heapVar5 = new int(140);

	uintptr_t heapAddr = reinterpret_cast<uintptr_t>(heapVar);
	uintptr_t heapAddr2 = reinterpret_cast<uintptr_t>(heapVar2);
	uintptr_t heapAddr3 = reinterpret_cast<uintptr_t>(heapVar3);
	uintptr_t heapAddr4 = reinterpret_cast<uintptr_t>(heapVar4);
	uintptr_t heapAddr5 = reinterpret_cast<uintptr_t>(heapVar5);
 
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
	cout << " heapVar address: " << heapVar << endl;
	cout << " heapAddr decimal value: " << heapAddr << endl;
	cout << endl;
	cout << " heapVar2 address: " << heapVar2 << endl;
	cout << " heapAddr2 decimal value: " << heapAddr2 << endl;
	cout << endl;
	cout << " heapVar3 address: " << heapVar3 << endl;
	cout << " heapAddr3 decimal value: " << heapAddr3 << endl;
	cout << endl;
	cout << " heapVar4 address: " << heapVar4 << endl;
	cout << " heapAddr4 decimal value: " << heapAddr4 << endl;
	cout << endl;
	cout << " heapVar5 address: " << heapVar5 << endl;
	cout << " heapAddr5 decimal value: " << heapAddr5 << endl;
	cout << endl;
	cout << "Text Segment (function) " << endl;
	cout << " sampleFunction: " << reinterpret_cast<void*>(&sampleFunction) << endl;
	cout << endl;

	delete heapVar;
	return 0;
}