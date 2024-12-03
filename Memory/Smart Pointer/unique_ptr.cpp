#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class MySmartPointer {
private:
	const T* ptr;
public:
	MySmartPointer(T* _ptr) : ptr(_ptr) {

	}

	~MySmartPointer() {
		delete this->ptr;
	}

	const T& operator* () const {
		return *(this->ptr);
	}

	const T& operator-> () const {
		return this->ptr;
	}
};

class MyClass {
private:
	int* data;
public:
	MyClass(int len) {
		this->data = new int[len];
		printf("Construct Call: new int[%d]\n", len);
	}

	~MyClass() {
		delete[] this->data;
		printf("Destructor Call!\n");
	}

	int getValue(int index) {
		return this->data[index];
	}

	void setValue(int index, int value) {
		this->data[index] = value;
	}
};

void func1() {
	MySmartPointer<MyClass> sPtr(new MyClass(10));
	printf("Exit Scope!\n");
	printf("Exit Scope!\n");
	return;
}

void funcGet() {
	unique_ptr<MyClass> pMyClass(new MyClass(10));
	pMyClass->setValue(0, 10);
	printf("Smart Pointer Get Value : %d\n", pMyClass->getValue(0));

	MyClass* originalMyClass = pMyClass.get();
	printf("Original Pointer Get Value: %d\n", originalMyClass->getValue(0));
	printf("Exit Scope!\n");
	return;
}

void funcRelease() {
	unique_ptr<MyClass> pMyClass(new MyClass(10));
	pMyClass->setValue(0, 10);
	printf("Smart Pointer Get Value : %d\n", pMyClass->getValue(0));

	MyClass* originalMyClass = pMyClass.release();
	printf("Original Pointer Get Value: %d\n", originalMyClass->getValue(0));
	printf("Exit Scope!\n");
	return;
}

void funcReset() {
	unique_ptr<MyClass> pMyClass = make_unique<MyClass>(10);
	pMyClass.reset(new MyClass(20));
	printf("Exit Scope!\n");
	return;
}

int main() {
	funcReset();
	return 0;
}