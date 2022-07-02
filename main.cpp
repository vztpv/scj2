
// now, test only haswell..
// need C++17, 64bit..

#define _CRT_SECURE_NO_WARNINGS


//#include <vld.h>
#include "mimalloc-new-delete.h"

#include <iostream>
#include <string>
#include <ctime>


#include "claujson.h" // using simdjson 2.0.0

#include <cstring>

using namespace std::literals::string_view_literals;


int main(int argc, char* argv[])
{
	std::cout << sizeof(claujson::Array) << "\n";
	std::cout << sizeof(claujson::Object) << "\n";
	std::cout << sizeof(claujson::Element) << "\n";
	std::cout << sizeof(claujson::Root) << "\n";
	
	for (int i = 0; i < 1; ++i) {
		claujson::Json* ut = nullptr; 
		try {
			int a = clock();
			
			auto x = claujson::Parse(argv[1], 64, ut);
			if (!x.first) {
				std::cout << "fail\n";
				if (ut) {
					delete ut;
				}
				return 1;
			}

			int b = clock();
			std::cout << "total " << b - a << "ms\n";

			//claujson::LoadData::save(std::cout, ut);
			//claujson::LoadData::save("output10.json", *ut);
			int c = clock();
			std::cout << c - b << "ms\n";

			bool ok = x.first;
			

			delete ut;

			return !ok;
		}
		catch (...) {
			if (ut) {
				delete ut;
			}
			std::cout << "internal error\n";
			return 1;
		}
	}
	
	//getchar();

	return 0;
}

