/*****************************************************************
*	
* 	File defines student Record methods found in the studentRecord.h
*   file. It provides a Vector called database used to store a 
* 	temporary memory. This files uses two name
* 	RSKJAM001
*	James Rasekoala
*
* *****************************************************************/

#include "VolImage.h"
using namespace std;
#include <iostream>
int main (int argc, char* argv[]){
	
	RSKJAM001::VolImage volImage;
	
	
	cout<<"Number of images: (int)"<<endl;
	cout<<"Number of bytes required: (int)"<<endl;
	volImage.readImages("MRI");
	//volimg.extractRow(imgi, outfile);
	//volImage.extract();
	
	}
