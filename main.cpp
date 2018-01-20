#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "HashTables.h"//change to .h
#include "GeneralHashFunctions.h"//change to .h

//TODO
// read in the two test files (names.txt, randoWords.txt) line by line
// lab1 code comes in handy here
std::ifstream nameFile("names.txt");
std::string nameString;

std::ifstream weakNameFile("names.txt");
std::string weakNameString;

std::ifstream randomFile("randoWords.txt");
std::string randomString;

std::ifstream weakRandomFile("randoWords.txt");
std::string weakRandomString;


std::ifstream jsNameFile("names.txt");
std::string jsNameString;

std::ifstream jsRandomfile("randomWords.txt");
std::string jsRandomString;


std::ifstream djbNameFile("name.txt");
std::string djbNameString;

std::ifstream djbRandomFile("randomWords.txt");
std::string djbRandomString;

//TODO
//use the STL hash as the hashing function to test your HashTable functionality





//TODO
//use the WeakHash() from GeneralHashFunctions as the hashing function to test your HashTable functionality



//TODO
// now using the same testing methods, pick 2 hashing functions from the included open source library "GeneralHashFunctions"



//TODO
// you will test your HashTable functions using one HashTable per file, per hashing function
// so you should have 2Files*4Hashers = 8 HashTable objects
// each HashTable object contains two different unordered maps for storage using different collision resistance methods
// you will use the addToTables() method once to add one entry into both tables
// you will edit the individual add-to-tables functions to add the appropriate functionality



using namespace std;
int main()
{
	HashTables stdHashTableNames;
	HashTables stdHashTableStrings;
	
	HashTables weakHashTableNames;
	HashTables weakHashTableStrings;

	HashTables jsHashTableNames;
	HashTables jsHashTableString;

	HashTables djbHashTableName;
	HashTables djbHashTableString;
	
	stdHashTableNames.openCollisions=0;
	stdHashTableNames.chainedCollisions = 0;
	
	stdHashTableStrings.openCollisions = 0;
	stdHashTableStrings.chainedCollisions = 0;

	weakHashTableNames.openCollisions = 0;
	weakHashTableStrings.openCollisions = 0;

	weakHashTableNames.chainedCollisions = 0;
	weakHashTableStrings.chainedCollisions = 0;

	jsHashTableNames.openCollisions = 0;
	jsHashTableString.openCollisions = 0;

	jsHashTableNames.chainedCollisions = 0;
	jsHashTableString.chainedCollisions = 0;

	djbHashTableName.chainedCollisions = 0;
	djbHashTableString.chainedCollisions = 0;

	djbHashTableName.openCollisions = 0;
	djbHashTableString.openCollisions = 0;

	cout << "STL HASH " << endl << endl;
	while (std::getline(nameFile, nameString))
	{
		std::size_t str_hash = std::hash<std::string>{}(nameString);
		stdHashTableNames.addToTables(str_hash, nameString);

	}
	stdHashTableNames.CollisionReport();


	while (std::getline(randomFile, randomString))
	{
		std::size_t str_hash = std::hash<std::string>{}(randomString);
		stdHashTableStrings.addToTables(str_hash, randomString);

	}
	stdHashTableStrings.CollisionReport();



	cout << endl<<endl<<endl << "WEAK HASH TABLES" << endl << endl << endl;

	while (std::getline(weakNameFile, weakNameString))
	{
		unint weakNameIndex = WeakHash(weakNameString);
		weakHashTableNames.addToTables(weakNameIndex, weakNameString);
	}


	weakHashTableNames.CollisionReport();
	while (std::getline(weakRandomFile, weakRandomString))
	{
		unint weakStringIndex = WeakHash(weakRandomString);
		weakHashTableStrings.addToTables(weakStringIndex, weakRandomString);

	}
	weakHashTableStrings.CollisionReport();


	cout << "JS HASH TABLES" << endl;

	while (std::getline(jsNameFile, jsNameString))
	{
		unint nameindex = FNVHash(jsNameString);
		jsHashTableNames.addToTables(nameindex, jsNameString);
	}
	jsHashTableNames.CollisionReport();

	while (std::getline(jsRandomfile, jsRandomString))
	{
		unint stringIndex = FNVHash(jsRandomString);
		jsHashTableString.addToTables(stringIndex, jsRandomString);
	}
	jsHashTableString.CollisionReport();


	cout << "DJB HASH TABLES" << endl;

	while (std::getline(djbNameFile, djbNameString))
	{
		unint nameindex = DJBHash(djbNameString);
		djbHashTableName.addToTables(nameindex, djbNameString);
	}
	djbHashTableName.CollisionReport();

	while (std::getline(djbRandomFile, djbRandomString))
	{
		unint stringIndex = DJBHash(djbRandomString);
		djbHashTableString.addToTables(stringIndex, djbRandomString);
	}
	djbHashTableString.CollisionReport();


	system("PAUSE");
	return 0;
}
