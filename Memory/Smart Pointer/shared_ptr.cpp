#include <iostream>
#include <memory>

using namespace std;

class Sample {
private:
    int content_;
public:
    Sample(int content) : content_(content) {
        cout << "Constructing Sample(" << content_ << ")\n";
    }

    ~Sample() {
        cout << "Destructing Sample(" << content_ << ")\n";
    }

    void print() {
        cout << "Sample Print(" << content_ << ")\n";
    }
};

void func1() {
    shared_ptr<Sample> pSample = make_shared<Sample>(1);
    
    shared_ptr<Sample> pSample2(pSample);

    shared_ptr<Sample> pSample3;
    pSample3 = pSample;
}

void func2() {
    shared_ptr<Sample> pSample = make_shared<Sample>(1);
    shared_ptr<Sample> pSample2(move(pSample));
}

void funcMakeMethod() {
    shared_ptr<Sample> pSample = make_shared<Sample>(1);
    shared_ptr<Sample> pSample2(new Sample(1));
}

void funcGet() {
    shared_ptr<int> pInt = make_shared<int>(1);
    if (pInt.use_count() > 0 ) {
        cout << "pInt.get() = " << pInt.get() << "\n";
        cout << "*pInt = " << *pInt << "\n";
    }
}

void funcReset() {
    shared_ptr<Sample> pSample = make_shared<Sample>(1);
    if (pSample.use_count() > 0) {
        cout << "[NonReset]*pSample = ";
        pSample->print();

        pSample.reset(new Sample(2));
        cout << "[.reset(new 2)] *pSample = ";
        pSample->print();

        pSample.reset();
        cout << "[.reset()] pSample.get() = " << pSample.get() << "\n";
    }
}

int main() {
    // func1();
    // func2();
    // funcMakeMethod();
    // funcGet();
    funcReset();
    return 0;
}