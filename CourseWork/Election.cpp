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
	int i = 0;
	for (; it != elec.end(); ++it) {
		vote v(*it);
		v.discard(c);
		if (v.preference.empty()) {
			it = elec.erase(it);

		}
		else{
			elec.at(i) = v;
			
		}
		
		i++;
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
	candidate x;
	std::vector<candidate> vec;
	std::vector<vote>::iterator it;
	
	std::fstream in("Text.txt");
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
	
	
	
	/*for (it = elec.elec.begin(); it != elec.elec.end();++it) {
		elec.eliminate(3);
		elec.eliminate(2);
		
		vote v(*it);
		
		std::cout << v.first_preference();
		
	}
	elec.ranked_candidates();*/
	std::vector<std::pair<candidate, int>> vec_pairs = elec.ranked_candidates();
	std::vector<std::pair<candidate, int>>::iterator it1 = vec_pairs.end()-1;
	int i = 0;
	while (vec_pairs[0].second<elec.elec.size()/2) {
		vec_pairs = elec.ranked_candidates();
		std::cout<<"candidate: " << vec_pairs[i].first << " " << vec_pairs[i].second<<"\n";
        vec_pairs.pop_back();
		elec.eliminate(vec_pairs.back().first);
	}
	if (vec_pairs[0].second > elec.elec.size() / 2) {
		std::cout << "candidate has won by majority vote: " << vec_pairs[0].first;
	}
	std::cout << "candidate has won by majority vote: " << vec_pairs[0].first;
	

	
}

