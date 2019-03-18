/**************************************************************************
* 
*	Student Number : RSKJAM001
*	@author James Rasekoala
* 
* ***************************************************************************/

#include "VolImage.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main (int argc, char* argv[]){
	string outputFileName = "";			//stores output file
	string flag="";	
	string baseName ="";				//variable to hold letter in front of command
	RSKJAM001::VolImage volImage;
	
	//switch statement to handle input according to size
	istringstream ( argv[1] ) >> baseName;
	cout<<"baseName : "<<baseName<<endl;
	volImage.readImages(baseName);	
	switch(argc){
		case 2:
			//switch case for when there is no argument given.
			//Statements print the bytes requred for images and number of images
			cout<<"Number of bytes required: "<< volImage.volImageSize()<<endl;
			cout<<"Number of images: "<< volImage.numOfImages()<<endl;
			break;		//break out of switch statement
		
		case 5:

			//switch case for when there formate includes to number
			//assign first letter of run paramenter
			istringstream ( argv[2] ) >> flag;
			
			//This will run the extract method if "-x" is detected
			if (flag=="-x"){
				int sliceI;
				istringstream ( argv[3] ) >> sliceI;
				outputFileName = (string) argv[4];
				volImage.extract( sliceI , outputFileName);
				
			//This will run the method for a cross Sectional loop in 3D array if "-g" is detected
			}else if (flag=="-g"){
				
				//extracts an image along row i of the volume, across all slices
				int sliceI;
				istringstream ( argv[3] ) >> sliceI;
				outputFileName = (string) argv[4];
				volImage.crossSectional(sliceI , outputFileName);
				
				
			}else{
				
				//Else statement will be printed if correct length but incorrect format
				cout<<"You have entered an invalid input with a correct input length"<<endl;
			}
			
			break;		//break out of switch statement
			
		//This will run the diffmap method if "-d" is detected for a
		case 6:
			istringstream ( argv[2] ) >> flag;
		
			if (flag=="-d"){
				int sliceI , sliceJ;
				istringstream ( argv[3] ) >> sliceI;
				istringstream ( argv[4] ) >> sliceJ;
				outputFileName = (string) argv[5];
				volImage.diffmap( sliceI , sliceJ , outputFileName);
			
			}
			break;		//break out of switch statement

			
		default:
		// if the user enters an input of invalid length
			cout<<"You have entered an invalid input"<<endl;
		}
	
	}
