#ifndef MYALLOC_HPP_
#define MYALLOC_HPP_

#include <cstddef>
#include <cstdint>
#include <typeinfo>
#include <iostream>

template<typename T>
class MyAlloc {
public:
	typedef T value_type;
	const int64_t id;

	MyAlloc(int64_t id): id(id) {}

	template<typename T2> MyAlloc(const MyAlloc<T2>& other): MyAlloc(other.id) {}

	T* allocate(std::size_t n) {
		std::cout << typeid(T()).name() << "\t" << n << "\n";
		return static_cast<T*>(malloc(n * sizeof(T)));
	}

	void deallocate(T* p, std::size_t n) {
		return;
	}
};

#endif /* MYALLOC_HPP_ */
