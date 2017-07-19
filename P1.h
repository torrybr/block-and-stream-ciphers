#ifndef READIMAGE_H
#define READIMAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream> 
#include <iterator>
#include <string.h>
#include <math.h>
using namespace std;

class cipher{
    public:         
       void computeBlockXOR();
       void computeBlockSwap();
       void computeStream();
       int readInput(ifstream& istr);
       int readKeyFile(ifstream& istr2);
       void padBlock();
       void write2file(string filename);
       void write2filed(string filename);
       void rmPadding();
       void transfer2XOR();
       void decryptXOR();
    private:      
		vector<char> inputFile;
		vector<string> outputFile;
		vector<char> keyfile;    
		vector<char> XOR;  
		vector<char> decrypt;
};

#endif
