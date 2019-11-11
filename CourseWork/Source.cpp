#include "Election.h"
#include "Vote.h"
#include <iostream>
#include <vector>
#include<istream>
#include <sstream>
#include <fstream>
int main() {
	std::vector<candidate> vote1 = { 3,2,4,1 };
	std::vector<candidate> vote2 = { 2,1,3,4 };
	std::vector<candidate> vote3 = { 3,2,4,1 };
	std::vector<candidate> vote4 = { 3,2,4,1 };
	vote v1(vote1);
	vote v2(vote2);
	vote v3(vote3);
	vote v4(vote4);
	election elec;
	elec.add_vote(v1);
	elec.add_vote(v2);
	elec.add_vote(v3);
	elec.add_vote(v4);
	//elec.ranked_candidates();
	/*read_votes(std::cin);*/
	main1();







	//std::fstream in("Text.txt");
	//std::string line;
	//std::vector<int> v;
	//std::vector<int>::iterator it;
	//int x=0;
	//while (std::getline(in, line)) {
	//	std::stringstream ss(line);
	//	while (ss>>x){
	//		/*std::cout << x;*/
	//		v.push_back(x);
	//	}
	//}
	//for (it = v.begin(); it != v.end(); ++it) {
	//	std::cout << *it;
	//}
	//for (int i = 0; i < v.size();i++) {
	//	std::cout<<v.at(i);
	//}
	
	


}
