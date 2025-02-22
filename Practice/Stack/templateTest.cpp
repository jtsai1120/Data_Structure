#include<iostream>

template <class T1, class T2>
class Mypair {
		public:
			T1 first;
			T2 second;
			
			Mypair(T1 fst, T2 sec): first(fst), second(sec) {}
};

int main() {
		Mypair<int, double> mp(1, 2.2);
		std::cout << mp.first << " " << mp.second << std::endl;
}