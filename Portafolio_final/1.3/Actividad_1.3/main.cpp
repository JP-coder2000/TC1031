// =================================================================
//
// File: main.cpp
// Author: Juan Pablo Cabrera Quiroga
// Date: 09/10/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include "bubble.h"
#include <regex>

using namespace std;

int main(int argc, char* argv[]) {
	//We open the input/output files
	fstream inputFile(/*argv[2]*/"input2.txt",ios::in);
	fstream outputFile(/*argv[3]*/"mysolution2.txt",ios::out);
	//We set some important variables & regexs
	string currentLine;
	vector <string> matchLines;
	vector <int> Dates;
	getline(inputFile,currentLine);
	regex Nums("[0-9]+");
	regex Prefix("1[A-Z]+");
	regex Date ("([0-9]{2})-([0-9]{2})-([0-9]{2})");
	regex Hour ("([0-9]{2}):([0-9]{2})");
	smatch M,Match,Match2;
	//We find the number of lines to be read and the prefix
	regex_search(currentLine,M,Nums);
	int Size=stoi(M.str());
	cout<<"The size is "<<Size<<endl;
	regex_search(currentLine,M,Prefix);
	regex findPrefix("("+M.str()+")");
	cout<<"The prefix is "<<M.str()<<endl;
	//We get the lines that satisfy the prefix 
	for(int i = 0;i < Size;i++){
		getline(inputFile,currentLine);
		regex_search(currentLine,M,findPrefix);
		if (M.str()!=""){
			regex_search(currentLine,Match,Date);
			regex_search(currentLine,Match2,Hour);
			Dates.push_back(stoi(Match.str(1))*1440+(stoi(Match.str(2))*43800)+stoi(Match2.str(1))*60+stoi(Match2.str(2)));
			matchLines.push_back(currentLine);
		}
	}
	//We sort and write on the output
	bubbleSort(Dates,matchLines);
	for (int i = 0;i<matchLines.size();i++) {
		outputFile<<matchLines[i]<<endl;
	}
	//We close the files
	inputFile.close();
	outputFile.close();
	return 0;
}
