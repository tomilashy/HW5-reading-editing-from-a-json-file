/*
 * main.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: ore-oluwa.olasubulumi
 */
//Ogo-Oluwa Jesutomi Olasubulumi <tomilashy@yahoo.com>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
// for convenience
using json = nlohmann::json;
#include <cstdio>

int main()
{


//	Json::Value root;   // starts as "null"; will contain the root value after parsing
//	std::ifstream config_doc("coen 244 assg.json", std::ifstream::binary);
//	config_doc >> root;

// deserialize from standard input
json j;
//std::cin >> j;

// serialize to standard output
//std::cout << j;

// the setw manipulator was overloaded to set the indentation for pretty printing
//std::cout << std::setw(4) << j << std::endl;
// read a JSON file
std::ifstream i("coen 244 assg.json");
i >> j;
// write prettified JSON to another file
std::ofstream o("prett.json");
o << std::setw(4) << j << std::endl;
for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout <<"\n"<< *it << "H\n";
}
return 0;

}
