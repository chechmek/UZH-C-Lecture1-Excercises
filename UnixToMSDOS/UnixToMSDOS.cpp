#include <iostream>
#include <fstream>
using namespace std;

void convert_to_unix(ofstream& ofs, ifstream& ifs);
void convert_to_msdos(ofstream& ofs, ifstream& ifs);

int main(int argc, char* argv[])
{
	cout << "Hello World!\n";

	ifstream ifs(argv[1]);
	ofstream ofs(argv[2]);
	string instruction(argv[3]);

	if (instruction == "tounix")
		convert_to_unix(ofs, ifs);
	else if (instruction == "todos")
		convert_to_msdos(ofs, ifs);
	else {
		cout << "type \"tounix\" or \"todos\" as a third argument";
	}
	return 0;
}

void convert_to_unix(ofstream& ofs, ifstream& ifs) {
	char c;
	for (;;) {
		ifs >> c;
		if (!ifs.good())
			break;
		if (c == '\r')
			continue;
		else
			ofs << c;
	}
}

void convert_to_msdos(ofstream& ofs, ifstream& ifs) {
	char c;
	for (;;) {
		ifs >> c;
		if (!ifs.good())
			break;
		if (c == '\n')
			ofs << "\r\n";
		else
			ofs << c;
	}
}