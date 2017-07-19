#include "P1.h"
//read input file and insert into string vector
int cipher::readInput(ifstream& istr) {
	char input;
	while(istr.get(input)) {
		cout<<input<<" "; //print string tokens
		inputFile.push_back(input);
	}
	cout<<endl;
	return 0;
}
//read keyfile and insert into vector
int cipher::readKeyFile(ifstream& istr2){
	char input;
	while(istr2.get(input)) {
		cout<<input<<" "; //print string tokens
		keyfile.push_back(input);
	}
	cout<<endl;
	return 0;
}
void cipher::padBlock() {
		//cout<<"Input total block size "<<inputFile.size()<<endl;
		int size = inputFile.size() % 8;
		size = 8-size;
		if(size !=0) {
			for(int i =0; i<size; i++) {
				inputFile.push_back(128);
			}
		}		
		cout<<inputFile.size() <<endl;
}
void cipher::computeBlockXOR() {
	int x = 0;
	for(int i= 0; i < inputFile.size(); i++) {	
		if(x > 7) x =0;
		//cout<<"X = "<<x<<endl;
		char n = inputFile[i] ^ keyfile[x];
		//cout<<n<<endl;
		XOR.push_back(n);
		x++;
	}
}

void cipher::computeBlockSwap() {
	int val = 0;
	int end = XOR.size() -1 ;
	int start = 0;
	int keycount = 0;
	char temp= ' ';
	while(start<=end){
		if(keycount>keyfile.size()-1){keycount=0;}
		val = keyfile[keycount]%2;
		if(val == 0) {
			start++;
			keycount++;
		} else {
			temp = XOR[start];
			XOR[start] = XOR[end];
			XOR[end] = temp;
			start++;
			end--;
			keycount++;
		}
	}
}
void cipher::computeStream() {

}
void cipher::write2file(string filename){
	    ofstream outputFile(filename);
	    copy(XOR.begin(), XOR.end(), ostream_iterator<char>(outputFile , "")); 
}
void cipher::rmPadding() {
	for(int x = decrypt.size() -1; decrypt[x] > 127 || decrypt[x] < 0; x--) {
		decrypt.pop_back();
	}
	for(int i =0; i<decrypt.size();i++){
		cout<<decrypt[i]<< " ";
	}
}
void cipher::transfer2XOR() {
	for(int i=0;i<inputFile.size();i++){
		XOR.push_back(inputFile[i]);
	}
}
void cipher::decryptXOR() {
	int x = 0;
	for(int i= 0; i < XOR.size(); i++) {	
		if(x > 7) x =0;
		//cout<<"X = "<<x<<endl;
		char n = XOR[i] ^ keyfile[x];
		//cout<<n<<endl;
		decrypt.push_back(n);
		x++;
	}
}
void cipher::write2filed(string filename){
	    ofstream outputFile(filename);
	    copy(decrypt.begin(), decrypt.end(), ostream_iterator<char>(outputFile , "")); 
}
