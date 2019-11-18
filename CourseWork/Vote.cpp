#include "Vote.h"
#include <iostream>
#include <vector>
#include <algorithm>

vote::vote(const std::vector<candidate>& prefs) : preference(prefs){

}
bool vote::spent() const {
	return preference.empty();
}
candidate vote::first_preference() const {
	return preference[0];
}
void vote::discard(candidate c) {
	if (!spent()) {
		preference.erase(std::remove(preference.begin(), preference.end(), c), preference.end());
	}
}