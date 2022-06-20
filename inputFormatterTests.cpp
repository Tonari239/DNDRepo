#include "inputFormatter.h"
#include "doctest.h"

TEST_SUITE("Input formatter")
{
	TEST_CASE("Split by interval")
	{
		string test = "Ivan Pesho Viki Minko Maria";
		vector<string> splitResult = InputFormatter::splitStringByDelimiter(test,' ');
		CHECK(splitResult[0] == "Ivan");
		CHECK(splitResult[0] == "Pesho");
		CHECK(splitResult[0] == "Viki");
		CHECK(splitResult[0] == "Minko");
		CHECK(splitResult[0] == "Maria");
	}

	TEST_CASE("Split by comma")
	{
		string test = "Ivan,Pesho,Viki,Minko,Maria";
		vector<string> splitResult = InputFormatter::splitStringByDelimiter(test, ' ');
		CHECK(splitResult[0] == "Ivan");
		CHECK(splitResult[0] == "Pesho");
		CHECK(splitResult[0] == "Viki");
		CHECK(splitResult[0] == "Minko");
		CHECK(splitResult[0] == "Maria");
	}

	TEST_CASE("Empty string")
	{
		string test = "";
		vector<string> splitResult = InputFormatter::splitStringByDelimiter(test, ' ');
		CHECK(splitResult[0] == "");
	}


}