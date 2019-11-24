//
// Created by Patrick Li on 2019-11-16.
//

#ifndef PROJECT_4__MYVECTOR_H_
#define PROJECT_4__MYVECTOR_H_

#include <iostream>

using namespace std;

template<class T>
class myVector {
 public:
  int capacity;
  T *arr;

  myVector() {
	capacity = 0;
	arr = new T[capacity];
  }

  ~myVector() {
    delete[] arr;
    capacity = 0;
  }

  myVector(myVector &v) {
	capacity = v.capacity;
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++) {
	  arr[i] = v.arr[i];
	}
  }

  void push_back(T val) {
	int sz = capacity;
	myVector old(*this);

	delete[] arr;
	arr = new T[sz + 1];

	for (int i = 0; i < sz; i++) {
	  arr[i] = old.arr[i];
	}

	capacity = sz + 1;
	arr[sz] = val;
  }

  void print() {
	cout << "[";
	for (int i = 0; i < capacity - 1; i++) {
	  cout << arr[i] << ", ";
	}
	cout << arr[capacity - 1] << "]" << endl;
  }

  int size() {
	return capacity;
  }

  T &operator[](int idx) {
	if (idx >= capacity) {
	  throw out_of_range("OUT OF BOUNDS");
	}
	else {
	  return arr[idx];
	}
  }

  const T &operator[](int idx) const {
	if (idx >= capacity) {
	  cout << "OUT OF BOUNDS" << endl;
	  return nullptr;
	}
	else {
	  return arr[idx];
	}
  }
};

#endif //PROJECT_4__MYVECTOR_H_
