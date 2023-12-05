#include <iostream>   
#include <fstream>  
#include <string>  
#include <sstream>  
#include <algorithm>  

using namespace std;

string read_file_A()
{
	ifstream input_file("input_A.txt");
	string outa = "";
	if (input_file.is_open())
	{
		ostringstream outp;
		outp << input_file.rdbuf();
		outa = outp.str();
	}
	input_file.close();
	return outa;
}

string research_str(string s1, string s2) {

	int n, m;
	string s;
	m = s1.size();
	n = s2.size();
	int** a = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		a[i] = new int[n + 1];
	}
	for (int j = 0; j <= n; j++) {
		a[0][j] = 0;
	}
	for (int i = 0; i <= m; i++) {
		a[i][0] = 0;
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= m; i++) {
			if (s1[i - 1] == s2[j - 1])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = 0;
		}
	}
	s = "";
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] > s.size())
				s = s1.substr((i - a[i][j] + 1) - 1, a[i][j]);
		}
	}
	return s;
}

string read_file_B()
{
	ifstream input_file("input_B.txt");
	string outb = "";
	if (input_file.is_open())
	{
		ostringstream outp;
		outp << input_file.rdbuf();
		outb = outp.str();
	}
	input_file.close();
	return outb;
}

bool input_loop()
{
	cout << "if you want to continue, press (y/Y) or if you want to end the program, click any other symbol" << endl;
	string answer;
	cin >> answer;
	return (answer == "Y" || answer == "y");
}

int main()
{
	do 
	{
		string file_A = read_file_A();
		string file_B = read_file_B();
		cout << research_str(file_A, file_B) << endl;
	} while (input_loop());
	return 0;
}
