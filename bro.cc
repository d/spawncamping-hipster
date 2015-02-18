#include "MyAlloc.hpp"
#include <vector>

int main() {
	std::vector<int, MyAlloc<int> > yo(1, MyAlloc<int>(42));
	yo.resize(10);
	return 0;
}
