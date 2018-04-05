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


//template<class UnaryFunction>
//void recursive_iterate(const json& j, UnaryFunction f)
//{
//    for(auto it = j.begin(); it != j.end(); ++it)
//    {
//        if (it->is_structured())
//        {
//            recursive_iterate(*it, f);
//        }
//        else
//        {
//            f(it);
//        }
//    }
//}


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
		"\n2) print in form of a table(output show both sorted and unsorted)"
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
			std::cout << '\n'<<"\t"<< "  ID    "<< "|\t"<< "Type"<< " \t|"<< "    Name"<<"\t\t|"<< "   Batter" <<"\t\t|"<< "   Toppings\n\t";
			for(int i=0;i<80;i++)
			{
				cout<<"-";
			}cout<<"\n";

//			for (auto it : json::iterator_wrapper(j))
//			{
//			    std::cout << "key: " << it.key() << ", value:" << a["/0/name"]<< '\n';
//			}
//			recursive_iterate(j, [](json::const_iterator it){
//			        std::cout << *it << std::endl;
//			    });


			unsigned  int arr=0;
			for (arr=0;arr<j["items"]["items"].size();arr++)
			             {
			            for (unsigned int batter=0;batter<j["items"]["items"][arr]["batters"]["batter"].size();batter++)
			             {
			                for (unsigned int i=0;i<j["items"]["items"][arr]["topping"].size();i++)
			                {
			                	if(arr==2||j["items"]["items"][0]["batters"]["batter"][batter]["type"]=="Devil's Food")
			                	{
			                		if(arr==2)
			                		{
			                			cout<< "\t"<<j["items"]["items"][arr]["id"]<<"\t|  "<< j["items"]["items"][arr]["type"]<<"\t|  "<< j["items"]["items"][arr]["name"]<<"\t|  "<< j["items"]["items"][arr]["batters"]["batter"][batter]["type"]<<"\t\t|"<< j["items"]["items"][arr]["topping"][i]["type"]<<endl;
			                		}
			                		if(j["items"]["items"][0]["batters"]["batter"][batter]["type"]=="Devil's Food")
			                		{
			                			cout<< "\t"<<j["items"]["items"][arr]["id"]<<"\t|  "<< j["items"]["items"][arr]["type"]<<"\t|  "<< j["items"]["items"][arr]["name"]<<"\t\t|  "<< j["items"]["items"][arr]["batters"]["batter"][batter]["type"]<<"\t|"<< j["items"]["items"][arr]["topping"][i]["type"]<<endl;
			                		}


			                	}
			                	else
			                	{
			                		cout<< "\t"<<j["items"]["items"][arr]["id"]<<"\t|  "<< j["items"]["items"][arr]["type"]<<"\t|  "<< j["items"]["items"][arr]["name"]<<"\t\t|  "<< j["items"]["items"][arr]["batters"]["batter"][batter]["type"]<<"\t\t|"<< j["items"]["items"][arr]["topping"][i]["type"]<<endl;
			                	}
			                }
			              }
			            }





		}
		else if(a==3)
		{

			json t;

			// read a JSON file (same thing but was rearranged for sorting)

			ifstream ace("coen244.json");
			ace>> t;
			cout<<"sort by:"
					"\n1)Name"
					"\n2)ID";
				int s;
				cin>>s;



			if (s==1)
			{
			std::cout << "unsorted:\n"<< std::setw(4) << t << '\n\n';
			std::sort(t.begin(), t.end(),
			        [](const json &a, const json &b)
					{
			          return a["name"] < b["name"];
					});
			  std::cout << "\nSorted:\n" << std::setw(4)<< t << '\n';
			}
			if (s==2)
						{
						std::cout << "unsorted:\n"<< std::setw(4) << t << '\n\n';
						std::sort(t.begin(), t.end(),
						        [](const json &a, const json &b)
								{
						          return a["id"] < b["id"];
								});
						  std::cout << "\nSorted:\n" << std::setw(4)<< t << '\n';
						}
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


