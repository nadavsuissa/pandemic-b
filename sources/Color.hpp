#pragma once
#include "City.hpp"
namespace pandemic
{

	// Class to Represent Colors for Game
	enum Color
	{
		Yellow,
		Red,
		Blue,
		Black
	};
	// Like in Cities same Concept - 
	// To String From Enum
	inline std::string colortostring(Color c)
	{

		if (c == Yellow)
		{
			return "Yellow";
		}
		if (c == Red)
		{
			return "Red";
		}
		if (c == Blue)
		{
			return "Blue";
		}
		else
		{
			return "Black";
		}
	}
}