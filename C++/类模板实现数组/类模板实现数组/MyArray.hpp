#pragma

template<class T>
class MyArray {
private:
	T *p;
	int mCapacity;
	int mSize;

public:
	MyArray(int mCapacity) {
		this->mCapacity = mCapacity;
		this->mSize = 0;
		p = new T[this->mCapacity];
	}
	MyArray(const MyArray &arr) {
		this->mCapacity = arr.mCapacity;
		this->mSize = arr.mSize;
		p = new T[arr.mCapacity];

		for (int i = 0; i < this->mSize; i++) {
			p[i] = arr.p[i];
		}
	}
	~MyArray() {
		if (this->p != NULL) {
			delete[] p;
			p = NULL;
		}
	}

	MyArray &operator= (const MyArray &arr) {
		if (this->p != NULL) {
			delete[] p;
			p = NULL;
		}

		p = new T[arr.mCapacity];
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		for (int i = 0; i < this->mSize; i++) {
			p[i] = arr.p[i];
		}
		return *this;
	}

	T &operator[](int index) {
		return this->p[index];
	}

	void pushBack(const T &val) {
		if (this->mSize == this->mCapacity) {
			return;
		}
		this->p[this->mSize] = val;
		this->mSize++;
	}
	void popBack() {
		if (this->mSize == 0) {
			return 0;
		}
		this->mSize--;
	}

	int getSize() {
		return this->mSize;
	}
};

