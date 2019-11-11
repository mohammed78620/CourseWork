#ifndef ELECTION_H
#define ELECTION_H
#include "Vote.h"
#include <iostream>
#include <vector>
class election {
private:
public:
	std::vector<vote> elec;
	void add_vote(const vote& v);
	int vote_count() const;
	void eliminate(candidate c);
	std::vector<std::pair<candidate, int>> ranked_candidates()const;
};
election read_votes(std::istream& in);
void main1();
#endif // !ELECTION_H
