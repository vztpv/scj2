
// now, test only haswell..
// need C++17, 64bit..

#define _CRT_SECURE_NO_WARNINGS

#include "mimalloc-new-delete.h"

#include <iostream>
#include <string>
#include <ctime>


#include "claujson.h" // using simdjson 2.0.0

#include <cstring>

using namespace std::literals::string_view_literals;


int main(int argc, char* argv[])
{
	
	for (int i = 0; i < 64; ++i) {
		claujson::Ptr<claujson::Json> j;
		try {
			int a = clock();
			
			auto x = claujson::Parse(argv[1], 64, j);
			if (!x.first) {
				std::cout << "fail\n";
				return 1;
			}

			int b = clock();
			std::cout << "total " << b - a << "ms\n";

			//claujson::LoadData::save(std::cout, ut);
		//	claujson::LoadData::save("output12.json", *j);
			
			int c = clock();
			std::cout << c - b << "ms\n";

int counter = 0;
			bool ok = x.first;
			

				double sum = 0;
			if (ok) {
				int chk = 0;
				for (int i = 0; i < 1; ++i) {
					auto A = j[1];

					for (auto& features : as_array(A)) {

						auto y = features->at("geometry"sv); // as_array()[t].as_object()["geometry"];
						
						
						if (y && y->is_object()) {
							auto yyy = y->at("coordinates"sv);
							//if (yyy)
							{
								auto yyyy = (*yyy)[0];
								//	if (yyyy)
								{
									for (auto& temp : as_array(yyyy)) {
										for (auto& x : as_array(temp)) {

											if (x->is_element() && x->get_value()->is_float()) {
												sum += x->get_value()->float_val();

												counter++;
												chk++;
											}

										}
									}

								}
							}
							//	//std::cout << dur.count() << "ns\n";

						}


					}
				}
			}

			std::cout << clock() - c << "ms\n";
			std::cout << sum << " ";
			std::cout << counter << " ";
			
			return !ok;
		}
		catch (...) {
			std::cout << "internal error\n";
			return 1;
		}
	}
	
	//getchar();

	return 0;
}

