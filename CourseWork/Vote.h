#ifndef VOTE_H
#define VOTE_H
#include <vector>
typedef unsigned int candidate;
class vote {
public:
	std::vector<candidate> preference;
	bool spent() const;
	candidate first_preference() const;
	void discard(candidate c);
	vote(const std::vector<candidate>& prefs);
};
#endif // !VOTE_H

