#include "Election.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include<string>
#include <sstream>
#include <fstream>
void election::add_vote(const vote &v) {
	vote vo = v;
	elec.push_back(vo);
}
int election::vote_count()const {
	return elec.size();
}
void election::eliminate(candidate c) {
	std::vector<vote>::iterator it = elec.begin();



	for (; it != elec.end(); ++it){
		vote v = *it;
		v.discard(c);
		if (v.spent()) {
			it = elec.erase(it);
		}
		else{
			*it = v;
		}
	}
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


