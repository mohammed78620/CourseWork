#include "Election.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<string>
#include <sstream>
#include <fstream>
void election::add_vote(const vote &v) {
	elec.push_back(v);
}

int election::vote_count()const {
	return elec.size();
}

void election::eliminate(candidate c) {
	std::vector<vote>::iterator it = elec.begin();
	while (it!=elec.end()){
		it->discard(c);
		++it;
	}
	it = std::remove_if(elec.begin(), elec.end(), [](vote v) {
		return v.spent(); });
	elec.erase(it, elec.end());
}

std::vector<std::pair<candidate, int>> election::ranked_candidates() const {
	std::vector<vote>::const_iterator it = elec.begin();
	std::vector<std::pair<candidate, int>> p;
	std::map<candidate,int> m;
	std::map<candidate, int>::iterator it2;
	vote v = *it;
	for (; it != elec.end(); ++it) {
		v = *it;
		++m[v.first_preference()];
	}
	for (it2 = m.begin(); it2 != m.end();++it2) {
		p.push_back(*it2);
		
	}
	std::sort(p.begin(), p.end(), [](std::pair<candidate, int> p1, std::pair<candidate, int> p2) {
			return p1.second > p2.second;
			});
	return p;
}

election read_votes(std::istream& in) {
	election elec;
	candidate x;
	std::vector<candidate> vec;	
	std::string line;
	while (std::getline(in, line)) {
		std::stringstream s(line);
		while (s >> x) {
			vec.push_back(x);
		}
		vote vo(vec);
		elec.add_vote(vo);
		vec.clear();
	}
	return elec;
}


