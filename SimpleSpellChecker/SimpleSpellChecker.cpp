#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<string> set_from_file(ifstream& file) {
	set<string> ::iterator i;
	set<string> set;
	string word;
	while (!file.eof()) {
		file >> word;
		set.insert(word);
	}
	return set;
}
void remove_punctuation(string& str) {
	str.erase(remove(str.begin(), str.end(), '.'), str.end());
	str.erase(remove(str.begin(), str.end(), ','), str.end());
	str.erase(remove(str.begin(), str.end(), '!'), str.end());
	str.erase(remove(str.begin(), str.end(), '?'), str.end());
	str.erase(remove(str.begin(), str.end(), '<'), str.end());
	str.erase(remove(str.begin(), str.end(), '>'), str.end());
	str.erase(remove(str.begin(), str.end(), '\"'), str.end());
	str.erase(remove(str.begin(), str.end(), '\''), str.end());
}

int main(int argc, char* argv[])
{
	ifstream dictionaryFile(argv[1]);
	ifstream textFile(argv[2]);

	set<string> dictionary = set_from_file(dictionaryFile);

	string word;
	while (!textFile.eof()) {
		textFile >> word;
		remove_punctuation(word);
		if (dictionary.find(word) == dictionary.end()) { // if not contains
			cout << word << endl;
		}
	}
};



