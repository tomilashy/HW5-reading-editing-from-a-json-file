/*
 * jsonfile.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: ore-oluwa.olasubulumi
 */
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


json j;



j={
		  "items",
		  {
		    "items",
			{
		          {
		        		  	  	{"id", "0001"},
								{"type", "donut"},
								{"name", "Cake"},
								{"ppu", 0.55},
								{"batters"},
								{
								  "batter",
								  {
												{ "id": "1001", "type": "Regular" },
												{ "id": "1002", "type": "Chocolate" },
												{ "id": "1003", "type": "Blueberry" },
												{ "id": "1004", "type": "Devil's Food" }
								  }
								}},
								{"topping",
									{
		  								{ "id": "5001", "type": "None" },
		  								{ "id": "5002", "type": "Glazed" },
		  								{ "id": "5005", "type": "Sugar" },
		  								{ "id": "5007", "type": "Powdered Sugar" },
		  								{ "id": "5006", "type": "Chocolate with Sprinkles" },
		  								{ "id": "5003", "type": "Chocolate" },
		  								{ "id": "5004", "type": "Maple" }
									}
								}


		          },

		          {
								"id": "0002",
								"type": "donut",
								"name": "Raised",
								"ppu": 0.55,
								"batters":
								{
								  "batter":{ "id": "2001", "type": "Regular" }
								},
								"topping":
		  							[
		  								{ "id": "5001", "type": "None" },
		  								{ "id": "5002", "type": "Glazed" },
		  								{ "id": "5005", "type": "Sugar" },
		  								{ "id": "5003", "type": "Chocolate" },
		  								{ "id": "5004", "type": "Maple" }
		  							]
		          },
		           {
								"id": "0003",
								"type": "donut",
								"name": "Old Fashioned",
								"ppu": 0.55,
								"batters":
								{
								  "batter":
											[
												{ "id": "3001", "type": "Regular" },
												{ "id": "3002", "type": "Chocolate" }
											]
								},
								"topping":
		  							[
		  								{ "id": "5001", "type": "None" },
		  								{ "id": "5002", "type": "Glazed" },
		  								{ "id": "5003", "type": "Chocolate" },
		  								{ "id": "5004", "type": "Maple" }
		  							]



		          },
		           {
								"id": "0004",
								"type": "bar",
								"name": "Bar",
								"ppu": 0.55,
								"batters":
								{
								  "batter":{ "id": "4001", "type": "Regular" }

								},
		  					"topping":
		  							[
		  								{ "id": "5003", "type": "Chocolate" },
		  								{ "id": "5004", "type": "Maple" }
		  							]
		          },
		           {
								"id": "0005",
								"type": "twist",
								"name": "Twist",
								"ppu": 0.55,
								"batters":
								{
								  "batter":{ "id": "5001", "type": "Regular" }
								},
								"topping",
		           	   	   	   	   	 }
		  								{ "id": "5002", "type": "Glazed" },
		  								{ "id": "5005", "type": "Sugar" }
		           	   	   	   	   	 }
		          },
		           {
								"id": "0006",
								"type": "filled",
								"name": "Filled",
								"ppu": 0.55,
								"batters":
								{
								  "batter":{ "id": "6001", "type": "Regular" }
								},
								"topping",
		           	   	   	   	   }

		  								{ "id": "5002", "type": "Glazed" },
		  								{ "id": "5007", "type": "Powdered Sugar" },
		  								{ "id": "5003", "type": "Chocolate" },
		  								{ "id": "5004", "type": "Maple" }
		           	   	   	   	   }



		          }
			}

		  }

		};
