#include "../cs225/catch/catch.hpp"
#include "../cs225/dsets.cpp"
#include <vector>
#include <iostream>

using namespace std;

TEST_CASE("disjoint1", "dsets")
{
	DisjointSets<string> disjSets;
	disjSets.addElement("15");
	disjSets.addElement("30");
	disjSets.printStatusReport();
	REQUIRE(disjSets.inSameSet("15", "30") == false);
}

TEST_CASE("disjoint2", "dsets")
{
	DisjointSets<string> disjSets;
	disjSets.addElement("165");
	disjSets.addElement("123414");
	disjSets.printStatusReport();
	REQUIRE(disjSets.inSameSet("165", "123414") == false);
}

TEST_CASE("setunionsimple1", "dsets")
{
	DisjointSets<string> disjSets;
	disjSets.addElement("15");
	disjSets.addElement("30");
    disjSets.setUnion("15", "30");
	disjSets.printStatusReport();
	REQUIRE(disjSets.inSameSet("15", "30") == true);
}

TEST_CASE("setunionsimple2", "dsets")
{
	DisjointSets<string> disjSets;
	disjSets.addElement("165");
	disjSets.addElement("123414");
    disjSets.setUnion("165", "123414");
	disjSets.printStatusReport();
	REQUIRE(disjSets.inSameSet("165", "123414") == true);
}

TEST_CASE("addElementsComplex", "dsets")
{
	DisjointSets<string> disjSets;
	disjSets.addElement("15");
	disjSets.addElement("30");
	disjSets.addElement("151");
	disjSets.addElement("301");
	disjSets.addElement("152");
	disjSets.addElement("302");
	disjSets.addElement("153");
	disjSets.addElement("303");
    disjSets.setUnion("151", "15");
    disjSets.setUnion("303", "30");
    disjSets.setUnion("152", "153");
    disjSets.setUnion("151", "153");
	disjSets.printStatusReport();
	REQUIRE(disjSets.inSameSet("15", "151") == true);
	REQUIRE(disjSets.inSameSet("15", "152") == true);
	REQUIRE(disjSets.inSameSet("15", "153") == true);
	REQUIRE(disjSets.inSameSet("152", "151") == true);
	REQUIRE(disjSets.inSameSet("301", "30") == false);
	REQUIRE(disjSets.inSameSet("303", "151") == false);
	REQUIRE(disjSets.inSameSet("302", "30") == false);
	REQUIRE(disjSets.inSameSet("302", "151") == false);
}