#include "Election.h"
#include "Vote.h"
#include <iostream>
#include <vector>

int main() {
	std::vector<candidate> vec = { 3,2,4,1 };
	vote v(vec);

	v.discard(2);

}
