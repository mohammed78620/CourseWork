#include "Election.h"
#include "Vote.h"
#include <iostream>
#include <vector>
#include<istream>
#include <sstream>
#include <fstream>
int main() {
	election elect;

	std::fstream in("Text1.txt");
	elect = read_votes(in);

	std::vector<std::pair<candidate, int>> vec_pairs = elect.ranked_candidates();
	std::vector<std::pair<candidate, int>>::iterator it1 = vec_pairs.begin();

	int round = 1;
	while (vec_pairs[0].second <= elect.elec.size() / 2) {
		vec_pairs = elect.ranked_candidates();
		std::cout << "Round " << round << ": " << elect.vote_count() << " votes" << "\n"
			<< "First preferences:" << "\n";		
		for (int i = 0; i < vec_pairs.size(); i++) {
			std::cout << "  Candidate " << vec_pairs[i].first << ": "
				<< vec_pairs[i].second << "\n";
		}
		if (vec_pairs[0].second > elect.elec.size() / 2) {
			std::cout << "Candidate  " << vec_pairs[0].first << " is selected.";
			return 0;
		}
		std::cout << "Candidate " << vec_pairs.back().first << " is eliminated." << "\n\n\n";
		elect.eliminate(vec_pairs.back().first);
		round++;
	}
}
