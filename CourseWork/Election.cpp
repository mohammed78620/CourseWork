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
	
	
	
	//std::vector<std::pair<candidate, int>> vec_pairs;
	//vec_pairs = elec.ranked_candidates();
	//std::cout << "candidate: " << vec_pairs[0].first << " " << vec_pairs[0].second << "\n";
	//elec.eliminate(3);
	//vec_pairs = elec.ranked_candidates();
	//std::cout << "candidate: " << vec_pairs[0].first << " " << vec_pairs[0].second << "\n";
	//elec.eliminate(2);
	//vec_pairs = elec.ranked_candidates();
	//std::cout << "candidate: " << vec_pairs[0].first << " " << vec_pairs[0].second << "\n";
	//if (vec_pairs[0].second > elec.elec.size() / 2) {
	//	std::cout << "candidate is selected through majority vote: " << vec_pairs[0].first;
	//}


	/*vote v(*it);*/
		
	/*std::cout << v.first_preference();*/
		
	
	


	std::vector<std::pair<candidate, int>> vec_pairs = elec.ranked_candidates();
	std::vector<std::pair<candidate, int>>::iterator it1 = vec_pairs.begin();
	
	int round = 1;
	while (vec_pairs[0].second<=elec.elec.size()/2) {
		vec_pairs = elec.ranked_candidates();
		std::cout << "Round " << round << ": " << elec.elec.size() << " votes" << "\n"
			<< "First preferences:"<<"\n";
		for (int i = 0; i < vec_pairs.size(); i++) {
			
			std::cout<<"  Candidate " << vec_pairs[i].first << ": " 
				<< vec_pairs[i].second<<"\n";
		}
		if (vec_pairs[0].second > elec.elec.size() / 2) {
		std::cout << "Candidate  " << vec_pairs[0].first<<" is selected.";
		return;
		
		}
		std::cout << "Candidate " << vec_pairs.back().first << " is eliminated."<<"\n\n\n";

		elec.eliminate(vec_pairs.back().first);
		
		

		round++;
	}
	
	/*std::cout << "candidate has won by majority vote: " << vec_pairs[0].first;*/
	

	
}

