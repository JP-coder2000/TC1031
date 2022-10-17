// =================================================================
//
// File: main.cpp
// Author: Sebastían Jimenez Bauer y Juan Pablo Cabrera Quiroga
// Date:17/10/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct info{
    string month, status, time, ip;
    int day;
};
vector <info> data;

int main(){
    ifstream newFile("bitacora.txt");
    string s;
    getline(newFile,s);
    cout << s;
     while (newFile)
     {
        getline(newFile,s);
        if (!newFile) break;
        cout << "read: " << s << endl;
        istringstream sts(s);

        info p;

        string temp;

        getline(sts,temp,' ');
        p.month = temp;
        cout << "read month: " << p.month << endl;       
        getline(sts,temp,' ');
        int dayNum = stoi(temp);
        p.day = dayNum;
        cout << "read # Day: " << p.day << endl;        
        getline(sts,temp,' ');
        p.time = temp;
        cout << "read time: " << p.time << endl;       
        getline(sts,temp,' ');
        p.ip = temp;
        cout << "read ip: " << p.ip << endl;    
        getline(sts,temp);
        p.status = temp;
        cout << "read status: " << p.status << endl;         

    }
    newFile.close();

    return 0 ;
}