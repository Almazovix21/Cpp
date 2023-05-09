#include <iostream>

template <typename T>
class Array {
private:
	T* data;
	size_t size;
public:
	Array(size_t s = 0) : data(new T[s]), size(s) {}
	Array(const Array& other) : data(new T[other.size]), size(other.size) {
		std::copy(other.data, other.data + other.size, data);
	}
	~Array() {
		delete[] data;
	}

	T& operator[](size_t index) {
		return data[index];
	}

	const T& operator[](size_t index) const {
		return data[index];
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new T[size];
			std::copy(other.data, other.data + other.size, data);
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
		for (size_t i = 0; i < arr.size; i++) {
			os << arr.data[i] << " ";
		}
		return os;
	}

	Array operator+(const Array& other) const {
		Array result(size + other.size);
		std::copy(data, data + size, result.data);
		std::copy(other.data, other.data + other.size, result.data + size);
		return result;
	}
};
int main() {
	Array<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;

	Array<int> b(4);
	b[0] = 4;
	b[1] = 5;
	b[2] = 6;
	b[3] = 7;

	Array<int> c = a + b;
	std::cout << c << std::endl;

	return 0;
}
