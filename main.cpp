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
using std::ifstream;
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
// for convenience
using json = nlohmann::json;
#include <cstdio>

int main()
{

json j;
//std::cout << std::setw(4) << j << std::endl;
// read a JSON file
ifstream i("coen 244 assg.json");

//more like deserialization
i >> j;

// write prettified JSON to another file
std::ofstream o("prett.json");
o << std::setw(4) << j << std::endl;

//print out a json
for (json::iterator it = j.begin(); it != j.end(); ++it)
{
// the setw manipulator was overloaded to set the indentation for pretty printing
  std::cout << std::setw(4) << *it << "\n";
}

for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << it.key() << " : " << it.value() << "\n";
}
return 0;

}
