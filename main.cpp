#include "P1.h"

int main(int argc, char* argv[])
{
    // check for the correct number of arguments
    if (argc != 6){
        cerr<<"Expect five argument."<<endl;
        return -1;
    }    
	string cipherType(argv[1]);
	string inputFilename(argv[2]);
	string outputFilename(argv[3]);
	string keyFilename(argv[4]);
	string mOperation(argv[5]);
	
	//read in inputfile
	ifstream istr(inputFilename);
	ifstream istr2(keyFilename);
	
	//error check for second argument input --> inputFilename[argv[2]]
	if (istr.fail() || istr2.fail() ){
        cerr<<"Cannot open file."<<endl;
        return -1;
    }
	//create an cipher object
	 cipher ciObj;
	 
	 if(cipherType == "b" || cipherType == "B") { //enter block cipher 
		 if(mOperation == "e" || mOperation =="E") { //enter encrypiton of plaintext
			int readIn = ciObj.readInput(istr);
			int keyIn = ciObj.readKeyFile(istr2);
			ciObj.padBlock();
			ciObj.computeBlockXOR();
			ciObj.computeBlockSwap();
			ciObj.write2file(outputFilename);
		 } else if(mOperation == "d" || mOperation == "D") { //enter decryption 
			 int readIn = ciObj.readInput(istr);
			 int keyIn = ciObj.readKeyFile(istr2);
			 ciObj.transfer2XOR();
			 ciObj.computeBlockSwap();
			 ciObj.decryptXOR();
			 ciObj.rmPadding();
			 ciObj.write2filed(outputFilename);
		 }	
	 } else if (cipherType == "s" || cipherType == "S") { // enter stream cipher
		 if(mOperation == "e" || mOperation =="E") {
			int readIn = ciObj.readInput(istr);
			int keyIn = ciObj.readKeyFile(istr2);
			ciObj.computeBlockXOR();
			ciObj.write2file(outputFilename);
		} else if( mOperation == "d" || mOperation =="D") {
			int readIn = ciObj.readInput(istr);
			int keyIn = ciObj.readKeyFile(istr2);
			ciObj.computeBlockXOR();
			ciObj.write2file(outputFilename);
		}
	 } else {
		 cerr<<"Must enter B or S"<<endl;
	 }
    return 0;
}
