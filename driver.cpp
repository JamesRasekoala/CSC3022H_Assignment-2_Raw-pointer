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
	string flag="";						//variable to hold letter in front of command
	
	RSKJAM001::VolImage volImage;
	
	//switch statement to handle input according to size
	switch(argc){
		case 1:
		
			//switch case for when there is no argument given.
			volImage.readImages("MRI");		//
			volImage.crossSectional(9);
			
			//Statements print the bytes requred for images and number of images
			cout<<"Number of bytes required: "<< volImage.volImageSize()<<endl;
			
			break;		//break out of switch statement
		
		case 4:
			//switch case for when there formate includes to number
			
			//assign first letter of run paramenter
			istringstream ( argv[1] ) >> flag;
			
			//This will run the extract method if "-x" is detected
			if (flag=="-x"){
				cout<<"-------------- 4 --------------"<<endl;
				cout<<"[-x i output_file_name]"<<endl;
				int sliceI;
				istringstream ( argv[2] ) >> sliceI;
				outputFileName = (string) argv[3];
				volImage.extract( sliceI , outputFileName);
				
			//This will run the method for a cross Sectional loop in 3D array if "-g" is detected
			}else if (flag=="-g"){
				
				//extracts an image along row i of the volume, across all slices
				int sliceI;
				istringstream ( argv[2] ) >> sliceI;
				outputFileName = (string) argv[3];
				volImage.crossSectional(9);
				
			}else{
				
				//Else statement will be printed if correct length but incorrect format
				cout<<"You have entered an invalid input with a correct input length"<<endl;
			}
			
			break;		//break out of switch statement
			
		//This will run the diffmap method if "-d" is detected for a
		case 5:
			istringstream ( argv[1] ) >> flag;
		
			if (flag=="-d"){
				cout<<"[-d i j output_file_name]"<<endl;
				int sliceI , sliceJ;
				istringstream ( argv[2] ) >> sliceI;
				istringstream ( argv[3] ) >> sliceJ;
				outputFileName = (string) argv[4];
				volImage.diffmap( sliceI , sliceJ , outputFileName);
			
			}
			break;		//break out of switch statement

			
		default:
		// if the user enters an input of invalid length
			cout<<"You have entered an invalid input"<<endl;
		}
	
	}
