/*
 * main.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: Ogo-Oluwa Jesutomi Olasubulumi
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
void print();

int main()
{

	cout<<"Using nlohmann json library"
			"\nPlease note that the batters are placed first because the library automatically sorts it that way and "
			"\nand I read nothing would be done about it so the ids come after the batters(useful when checking if its sorted)\n";
json j;
//std::cout << std::setw(4) << j << std::endl;
// read a JSON file
ifstream i("coen 244 assg.json");

//more like deserialization
i >> j;

int a;
do {

cout<<"\nWhat do you what to do with coen 244 assg.json?"
		"\n1)output json file"
		"\n2) print in form of a table"
		"\n3) sort json  file "
		"\n4) Copy json file to another file"
		"\n5) Exit";
	cin>>a;

		if(a==1)
		{
			cout<< std::setw(4) << j << std::endl;
		}
		else if(a==2)
		{
			std::cout << '\n'<<"\t"<< "  ID  "<< "|\t"<< "Type"<< " \t|"<< "Name"<<"\t\t|"<< "Batter" <<"\t\t|"<< "Toppings\n\t";
			for(int i=0;i<60;i++)
			{
				cout<<"-";
			}
			print();
		}
		else if(a==3)
		{

			json t;

			// read a JSON file (same thing but was rearranged for sorting)

			ifstream ace("coen244.json");
			ace>> t;


			std::cout << "unsorted:\n"<< std::setw(4) << t << '\n';
			//this is whats left

			std::sort(t.begin(), t.end(),
			        [](const json &a, const json &b)
					{
			          return a["id"] < b["id"];
					});
			  std::cout << "\nSorted:\n" << std::setw(4)<< t << '\n';
		}

		else if (a==4)
		{
			string newfile;
			cout<<"What's the name you want to give the new file?";
			cin>>newfile;
			newfile= newfile+".json";
			// write prettified JSON to another file
			std::ofstream o(newfile);
			o << std::setw(4) << j << std::endl;
			json out;
			ifstream b(newfile);
			b>>out;
			//print out a json
			for (json::iterator it = out.begin(); it != out.end(); ++it)
			{
				// the setw manipulator was overloaded to set the indentation for pretty printing
				std::cout << std::setw(4) << *it << "\n";
				cout<<newfile<<" created!!";
			}

		}


}while(a!=5);


return 0;

}
void print()
{
	json j;
	//std::cout << std::setw(4) << j << std::endl;
	// read a JSON file
	ifstream i("coen 244 assg.json");

	//more like deserialization
	i >> j;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/3/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/4/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/5/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/6/type"_json_pointer) ;

	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/3/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/4/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/5/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/6/type"_json_pointer) ;

	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/3/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/4/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/5/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/2/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/6/type"_json_pointer) ;

	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/3/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/4/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/5/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/0/id"_json_pointer)<< "|\t"<< j.at("/items/items/0/type"_json_pointer) << " |"<< j.at("/items/items/0/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/0/batters/batter/3/type"_json_pointer) <<"\t|"<< j.at("/items/items/0/topping/6/type"_json_pointer) ;

//ID 002 starts

	std::cout << '\n'<<"\t"<< j.at("/items/items/1/id"_json_pointer)<< "|\t"<< j.at("/items/items/1/type"_json_pointer) << " |"<< j.at("/items/items/1/name"_json_pointer)<<"\t|"<< j.at("/items/items/1/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/1/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/1/id"_json_pointer)<< "|\t"<< j.at("/items/items/1/type"_json_pointer) << " |"<< j.at("/items/items/1/name"_json_pointer)<<"\t|"<< j.at("/items/items/1/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/1/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/1/id"_json_pointer)<< "|\t"<< j.at("/items/items/1/type"_json_pointer) << " |"<< j.at("/items/items/1/name"_json_pointer)<<"\t|"<< j.at("/items/items/1/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/1/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/1/id"_json_pointer)<< "|\t"<< j.at("/items/items/1/type"_json_pointer) << " |"<< j.at("/items/items/1/name"_json_pointer)<<"\t|"<< j.at("/items/items/1/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/1/topping/3/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/1/id"_json_pointer)<< "|\t"<< j.at("/items/items/1/type"_json_pointer) << " |"<< j.at("/items/items/1/name"_json_pointer)<<"\t|"<< j.at("/items/items/1/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/1/topping/4/type"_json_pointer) ;

//ID 003 starts
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/0/type"_json_pointer);
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/0/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/3/type"_json_pointer);


	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/0/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/2/id"_json_pointer)<< "|\t"<< j.at("/items/items/2/type"_json_pointer) << " |"<< j.at("/items/items/2/name"_json_pointer)<<"|"<< j.at("/items/items/2/batters/batter/1/type"_json_pointer) <<"\t|"<< j.at("/items/items/2/topping/3/type"_json_pointer) ;

//ID 004 starts
	std::cout << '\n'<<"\t"<< j.at("/items/items/3/id"_json_pointer)<< "|\t"<< j.at("/items/items/3/type"_json_pointer) << "   |"<< j.at("/items/items/3/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/3/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/3/topping/0/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/3/id"_json_pointer)<< "|\t"<< j.at("/items/items/3/type"_json_pointer) << "   |"<< j.at("/items/items/3/name"_json_pointer)<<"\t\t|"<< j.at("/items/items/3/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/3/topping/1/type"_json_pointer) ;

//ID 005 starts
	std::cout << '\n'<<"\t"<< j.at("/items/items/4/id"_json_pointer)<< "|\t"<< j.at("/items/items/4/type"_json_pointer) << " |"<< j.at("/items/items/4/name"_json_pointer)<<"\t|"<< j.at("/items/items/4/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/4/topping/0/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/4/id"_json_pointer)<< "|\t"<< j.at("/items/items/4/type"_json_pointer) << " |"<< j.at("/items/items/4/name"_json_pointer)<<"\t|"<< j.at("/items/items/4/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/4/topping/1/type"_json_pointer) ;

//ID 006 starts
	std::cout << '\n'<<"\t"<< j.at("/items/items/5/id"_json_pointer)<< "|\t"<< j.at("/items/items/5/type"_json_pointer) << "|"<< j.at("/items/items/5/name"_json_pointer)<<"\t|"<< j.at("/items/items/5/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/5/topping/0/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/5/id"_json_pointer)<< "|\t"<< j.at("/items/items/5/type"_json_pointer) << "|"<< j.at("/items/items/5/name"_json_pointer)<<"\t|"<< j.at("/items/items/5/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/5/topping/1/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/5/id"_json_pointer)<< "|\t"<< j.at("/items/items/5/type"_json_pointer) << "|"<< j.at("/items/items/5/name"_json_pointer)<<"\t|"<< j.at("/items/items/5/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/5/topping/2/type"_json_pointer) ;
	std::cout << '\n'<<"\t"<< j.at("/items/items/5/id"_json_pointer)<< "|\t"<< j.at("/items/items/5/type"_json_pointer) << "|"<< j.at("/items/items/5/name"_json_pointer)<<"\t|"<< j.at("/items/items/5/batters/batter/type"_json_pointer) <<"\t|"<< j.at("/items/items/5/topping/3/type"_json_pointer) ;


}
