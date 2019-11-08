#include "Election.h"
#include <iostream>
#include <vector>
void election::add_vote(const vote &v) {
	vote vo = v;
	elec.push_back(vo);
}
int election::vote_count()const {
	 
}
void election::eliminate(candidate c) {
	std::vector<vote>::iterator it = elec.begin();
	vote v = *elec.begin();
	for (; it != elec.end(); ++it) {
		v = *it;
		v.discard(c);
	}
}
std::vector<std::pair<candidate, int>> election::ranked_candidates() const {
	std::vector<vote>::iterator it2 = elec.begin();
	std::pair<candidate, int> p;
	vote v = *it2;
	for (; it2 != elec.end(); ++it2) {
		v = *it2;
		++p[v.first_preference];
	}
}

