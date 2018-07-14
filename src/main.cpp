#include <iostream>
#include <cstdlib>
#include <map>
#include "map_base/map_check.hpp"
#include "mymap.hpp"

using ::std::map;
using ::std::string;

int main() {

    WMJTask::mapCheck< string, int > right;
	WMJTrain::map< string, int > test;

	::std::cout << "Map Class from " << test.author() << ::std::endl;
	::std::cout << "==================Start===================\n";

	for( int i = 0; i < 5; ++i) {
		::std::string tmp = "";
		auto inserttmp = 
			::std::pair< string, int>( tmp + char( 'A' + i), i);
		bool jud1 = right.insert(inserttmp);
		bool jud2 = test.insert(inserttmp);

		if ( jud1 != jud2) {
			if ( jud1) {
				::std::cout << "\e[1;31m[ERROR] Pair Insert " << i << " failed!\e[0m\n";
			} else {
				::std::cout << "\e[1;31m[ERROR] Repeat Insert " << i << "\e[0m\n";
			}
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] Pair Insert " << i << " pass!\e[0m\n";
		}
	}

	for( int i = 0; i < 10; ++i) {
		::std::string tmp = "";
		auto inserttmp = 
			::std::pair< string, int>( tmp + char( 'A' + i), i);
		bool jud1 = right.insert(inserttmp);
		bool jud2 = test.insert(inserttmp);

		if ( jud1 != jud2) {
			if ( jud1) {
				::std::cout << "\e[1;31m[ERROR] Pair Insert " << i << " failed!\e[0m\n";
			} else {
				::std::cout << "\e[1;31m[ERROR] Repeat Insert " << i << "\e[0m\n";
			}
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] Pair Insert " << i << " pass!\e[0m\n";
		}
	}

	for( int i = 5; i < 20; ++i) {
		::std::string tmp = "";
		bool jud1 = right.insert( tmp + char( 'A' + i), i);
		bool jud2 = test.insert( tmp + char( 'A' + i), i);

		if ( jud1 != jud2) {
			if ( jud1) {
				::std::cout << "\e[1;31m[ERROR] Function Insert " << i << " failed!\e[0m\n";
			} else {
				::std::cout << "\e[1;31m[ERROR] Repeat Insert " << i << "\e[0m\n";
			}
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] Function Insert " << i << " pass!\e[0m\n";
		}
	}

	for ( int i = 0; i < 20; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		if ( right.at(tmp) != test.at(tmp)) {
			::std::cout << "\e[1;31m[ERROR] At Find " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] At Find " << tmp << " pass\e[0m\n";
		}
	}

	for ( int i = 0; i < 30; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		if ( right.has(tmp) != test.has(tmp)) {
			::std::cout << "\e[1;31m[ERROR] Has Find " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] Has Find " << tmp << " pass\e[0m\n";
		}
	}

	for ( int i = 0; i < 10; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		if ( right[tmp] != test[tmp]) {
			::std::cout << "\e[1;31m[ERROR] [] Find " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] [] Find " << tmp << " pass\e[0m\n";
		}
	}

	for ( int i = 10; i < 20; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		right[tmp] = i * 2;
		test[tmp] = i * 2;
		if ( right[tmp] != test[tmp]) {
			::std::cout << "\e[1;31m[ERROR] [] Change " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] [] Change " << tmp << " pass\e[0m\n";
		}
	}

	for ( int i = 20; i < 30; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		right[tmp] = i;
		test[tmp] = i;
		if ( right[tmp] != test[tmp]) {
			::std::cout << "\e[1;31m[ERROR] [] Insert " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] [] Insert " << tmp << " pass\e[0m\n";
		}
	}

	for ( int i = 20; i < 40; ++i) {
		::std::string tmp = "";

		tmp += char( 'A' + i);
		bool jud1 = right.erase(tmp);
		bool jud2 = test.erase(tmp);

		if ( ( jud1 != jud2) 
				|| right.has(tmp) != test.has(tmp)) {
			::std::cout << "\e[1;31m[ERROR] Erase " << tmp << " failed\e[0m\n";
			::std::exit(-1);
		} else {
			::std::cout << "\e[1;32m[PASS] Erase " << tmp << " pass\e[0m\n";
		}
	}

	if ( right.size() != test.size()) {
		::std::cout << "\e[1;31m[ERROR] Size not right\e[0m\n";
		::std::exit(-1);
	} else {
		::std::cout << "\e[1;32m[PASS] Size pass\e[0m\n";
	}

	auto vec1 = right.showAll();
	auto vec2 = test.showAll();

	if ( vec1.size() != vec2.size()) {
		::std::cout << "\e[1;31m[ERROR] ShowAll not right\e[0m\n";
		::std::exit(-1);
	} else {
		::std::cout << "\e[1;32m[PASS] ShowAll pass\e[0m\n";
	}

	for ( size_t i = 0; i < vec1.size(); ++i) {
		if ( vec1.at(i) != vec2.at(i)) {
			::std::cout << "\e[1;31m[ERROR] ShowAll not right\e[0m\n";
			::std::exit(-1);
		}
	}

	::std::cout << "\e[1;32m[SUCCESS] All Clear, Congratulations!\e[0m\n";

	return 0;

}
