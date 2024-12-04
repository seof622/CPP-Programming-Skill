#include <iostream>
#include <memory>

using namespace std;

class Person {
private:
	string name_;
	weak_ptr<Person> partner;
public:
	Person(string name) : name_(name) {
		cout << name_ << " Constructed!\n";
	}
	~Person() {
		cout << name_ << " Destructed!\n";
	}
	bool setPartner(shared_ptr<Person>& p) {
		if (!p) return false;

		this->partner = p;

		cout << name_ << " is now partnerd with " << p->name_ << "\n";

		return true;
	}

};

int main() {
	shared_ptr<Person> ptr1 = make_shared<Person>("Minsu");
	shared_ptr<Person> ptr2 = make_shared<Person>("YoungHee");

	ptr1->setPartner(ptr2);
	ptr2->setPartner(ptr1);

	ptr1.reset();
	ptr2.reset();

	return 0;
}