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
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]){
	string outputFileName = "";
	string flag="";
	RSKJAM001::VolImage volImage;
	
	
	
	switch(argc){
		case 1:
			volImage.readImages("MRI");
			volImage.crossSectional(9);
			cout<<"-------------- 1 --------------"<<endl;
		//	cout<<"Number of images: "<<volImage.numOfImages<<endl;
			cout<<"Number of bytes required: "<< volImage.volImageSize()<<endl;
			break;
		
		
				
		case 4:
			istringstream ( argv[1] ) >> flag;
			
			if (flag=="-x"){
				
				cout<<"-------------- 4 --------------"<<endl;
				cout<<"[-x i output_file_name]"<<endl;
				int sliceI;
				istringstream ( argv[2] ) >> sliceI;
				outputFileName = (string) argv[3];
				volImage.extract( sliceI , outputFileName);
			}else if (flag=="-g"){
				
				//extracts an image along row i of the volume, across all slices, 
				//and write this out.
				int sliceI;
				istringstream ( argv[2] ) >> sliceI;
				outputFileName = (string) argv[3];
				//volImage.extractRow(sliceI, outputFileName);
				volImage.crossSectional(9);
				
			}else{
				cout<<"You have entered an invalid input for the correct input length"<<endl;
			}
			
			break;
			
		case 5:
			 
		     
			cout<<"-------------- 5 --------------"<<endl;
			cout<<"[-d i j output_file_name]"<<endl;
			int sliceI , sliceJ;
			istringstream ( argv[2] ) >> sliceI;
			istringstream ( argv[3] ) >> sliceJ;
			outputFileName = (string) argv[4];
			volImage.diffmap( sliceI , sliceJ , outputFileName);
			
			break;
		
		case 6:
			//statement;
			cout<<"-------------- 6 --------------"<<endl;
			break;
			
		default:
			cout<<"You have entered an invalid input"<<endl;

		
		}
	
	
	/*
	cout<<"Number of images: (int)"<<endl;
	cout<<"Number of bytes required: (int)"<<endl;
	volImage.readImages("MRI");
	//volimg.extractRow(imgi, outfile);
	volImage.extract(2,"testing");
	cout<<" int volImageSize(void);  "<<volImage.volImageSize()<<endl; 
	//volImage.diffmap(10, 10, "xxxxxxxxxxxx");
		cout<< argc<<"      special print      "<<endl;

		cout<<argv[0]<<"       =="<<endl;
		cout<<argv[1]<<"       =="<<endl;
		//cout<<argv[3]<<"       =="<<endl;
		*/
	}
