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
	int i = 0;
	for (auto x : elec) {
		i++;
	}
	return i;
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
	
	std::vector<vote>::const_iterator it = elec.begin();
	std::vector<std::pair<candidate, int>> p;
	std::map<candidate,int> m;
	std::map<candidate, int>::iterator it2;
	vote v = *it;
	for (; it != elec.end(); ++it) {
		v = *it;
		++m[v.preference.at(0)];
	}
	
	for (it2 = m.begin(); it2 != m.end();++it2) {
		p.push_back(*it2);
		std::sort(p.begin(), p.end(), [](std::pair<candidate, int> p1, std::pair<candidate, int> p2) {
			return p1.second > p2.second;
			});
	}
	for (int i = 0; i < p.size(); i++) {
		std::cout << " Candidate: " << p[i].first<<" " << " FirstPreferenceCount: " << p[i].second;
	}
	return p;
}
election read_votes(std::istream& in) {
	election elec;
	vote vo();
	std::string line;
	while (std::getline(in,line)) {
		std::stringstream s(line);
		std::cout << s.str();		
	}
	
	return elec;
}
void main1() {
	election elec;
	std::vector<candidate> vec;
	std::fstream in("Text.txt");
	std::string line;
	std::stringstream s(line);
	while (std::getline(in, line)) {
		while (s >> line) {
			candidate line;
			vec.push_back(line);
		}
		vote vo(vec);
		elec.add_vote(vo);
		vec.clear();
	}
	vote v = *elec.it;
	v.preference.at(0);
	
	//for (; it != elec.elec.end();++it) {
	//	vote v = *it;
	//	v.first_preference();
	//}
	
}

