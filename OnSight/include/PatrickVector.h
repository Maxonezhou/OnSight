//
// Created by Patrick Li on 2019-11-16.
//

#ifndef PROJECT_4__Vector_H_
#define PROJECT_4__Vector_H_

template<class T>
class Vector {
 public:
  int capacity;
  T *arr;

  Vector() {
	capacity = 0;
	arr = new T[capacity];
  }

  ~Vector() {
    delete[] arr;
    capacity = 0;
  }

  Vector(Vector &v) {
	capacity = v.capacity;
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++) {
	  arr[i] = v.arr[i];
	}
  }

  void push_back(T val) {
	int sz = capacity;
	Vector old(*this);

	delete[] arr;
	arr = new T[sz + 1];

	for (int i = 0; i < sz; i++) {
	  arr[i] = old.arr[i];
	}

	capacity = sz + 1;
	arr[sz] = val;
  }

//   void print() {
// 	cout << "[";
// 	for (int i = 0; i < capacity - 1; i++) {
// 	  cout << arr[i] << ", ";
// 	}
// 	cout << arr[capacity - 1] << "]" << endl;
//   }

  int size() {
	return capacity;
  }

  T &operator[](int idx) {
	if (idx >= capacity) {
	  //throw out_of_range("OUT OF BOUNDS");
	}
	else {
	  return arr[idx];
	}
  }

  const T &operator[](int idx) const {
	if (idx >= capacity) {
	  //cout << "OUT OF BOUNDS" << endl;
	  return nullptr;
	}
	else {
	  return arr[idx];
	}
  }
};

#endif //PROJECT_4__Vector_H_
