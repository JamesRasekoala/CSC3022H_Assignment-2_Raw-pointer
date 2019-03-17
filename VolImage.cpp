/*****************************************************************
*	
* 	File defines VolImage methods found in the VolImage.h
*   file. It provides has Vector called slicesVector used to store slices.
* 	
* 	Student Number : RSKJAM001
*	@author James Rasekoala
* 	
*
* *****************************************************************/

#include "VolImage.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;


bool RSKJAM001:: VolImage:: readImages(std::string baseName){
		vector<string> line;
		string fileExtension=".raw";
		string content;
		ifstream file("brain_mri_raws/"+baseName+".data");		//variable to work for all images
		
		if(!file){
			// if file can not be opened
			cout<<"Error opening file"<<endl;
			
		}else{
			
			while(std::getline(file, content, ' ')) { //reads and data file for parameters
				line.push_back(content);  
				
			}
				file.close(); 		//data file closed
				
			// assigning image parameter 	
			istringstream ( line[0] ) >> width;
			istringstream ( line[1] ) >> height;
			istringstream ( line[2] ) >> numberImages;
						
			for(int picNum =0; picNum<= numberImages; picNum++){ 			//loop through all images
				string pos;
				pos=to_string(picNum);						// the number of the imagie in string format
				ifstream rawfile("brain_mri_raws/"+baseName+""+pos+".raw",std::ios::binary);   //secifies file name and changes it accoding to loop for all images
				streampos pix;
				if(!rawfile){
					cout<<"Error opening Image"<<endl;
					} else{

						pix = rawfile.tellg();				
						unsigned char** imageArray = new unsigned char* [height];
						unsigned char* slice;
						for(int ycord=0; ycord<height;ycord++){
							imageArray[ycord] =  new unsigned char [width];
							slice = new unsigned char[width];
							rawfile.read((char*)slice,width);
							imageArray[ycord] = slice;
															}
															
						slicesVector.push_back(imageArray); 		// adds 2D image slice to vector
						rawfile.close();		// closes file for looped image
					}
					
				
				//end of for loop
				}
			
		//end of else loop for opening
		}
		
		return true;

}


		RSKJAM001:: VolImage::VolImage(){
			// costructor creats a VolImage with default values as below
			width = 0;
			height = 0;
			std:: vector<unsigned char **> slicesVector(0);
			}


			RSKJAM001:: VolImage::~VolImage(){ 
				// destructor method to free memory
				for(std::size_t i =0; i< slicesVector.size();i++){
					for(int j =0; j< height;j++){
						delete[] slicesVector[i][j]; // dealocates each row for using the heigt going down
						 }
					delete [] slicesVector[i]; // dealocates the now empty slice
				}
				
			}


	void RSKJAM001:: VolImage:: diffmap(int sliceI, int sliceJ, std::string output_prefix){
		// calculates the difference in volume for two different slices
			std::ofstream diffmapDatafile(output_prefix+".raw",std::ios::binary); 	// writes binary file
			
			// loop through hight
			for(int r=0;r<height;r++){
				//loop through width
				for (int c=0;c<width;c++){
					//hold holds the difference in pixels
				    char hold = abs(((float)slicesVector[sliceI][width][height] - (float)slicesVector[sliceJ][width][height])/2);
					diffmapDatafile.write(&hold,1);
										 }
									}
			diffmapDatafile.close();  //close file
		}
		
		
	void RSKJAM001:: VolImage:: extract(int sliceId, std::string output_prefix){
			
			std::ofstream extractRawFile(output_prefix+".raw",std::ios::binary);
			std::ofstream file(output_prefix+".dat", ios::out);
			file<<width<<" "<<height<<" "<<1;
			ofstream rawfile;
			rawfile.open(output_prefix+".data");
			rawfile.open("brain_mri_raws/output"+output_prefix+".dat");
		 
		 if(!extractRawFile){
			 
			 // if file does not open
			 std::cout<<"Could't write file for extract "<<endl;
		}else{
			
			//for loop to go through each row for height number of times
			for(int y; y<height;y++){
					//take the whole row of size width
				char* bitLine = (char*) slicesVector[sliceId][y];
				// write a raw file with a raw file and write the size of width
				extractRawFile.write(bitLine,width);
			}
			
		}
		
	extractRawFile.close(); // closes writing file	
	rawfile.close(); // closes reading file	
		}
		
		
	int RSKJAM001:: VolImage:: volImageSize(void){
		int widthPtrSize =  sizeof(unsigned char) * slicesVector.size();		 //size of weight pointer
		int hightPtr =  height* sizeof(unsigned char) * slicesVector.size();	 //size of 2D pointers used to hold raw
		int	SliceSize =  width * height* sizeof(unsigned char) * slicesVector.size(); // calculate size of all slices
		int totalSize = widthPtrSize + hightPtr + SliceSize;
		return totalSize; // Size of uchars plus pinters
		}
		
		
	void RSKJAM001:: VolImage:: crossSectional(int heightInput){
			string output_prefix = "cross";
			cout<<" extractRow  method "<<endl;
			ofstream extractRawFile(output_prefix+".raw",std::ios::binary);
		
			//unsigned char** slice = slicesVector[sliceId];
			std::ofstream file("cross"+output_prefix+".dat", ios::out);
			file<<width<<" "<<height<<" "<<1;
			ofstream rawfile;
			rawfile.open(output_prefix+".data");
			
			for(int i=0; i<(int)slicesVector.size();i++){
				char* bitLine = new char [width-1];
				//cout<<"BitLine size";
				//cout<<bitLine.size()<<endl;
				
				for(int w=0 ; w<width;w++){
				char bit = (char) slicesVector[i][heightInput][w];
				cout<<"count w :"<<w<<endl;
				bitLine[i]= bit;
			}
			cout<<"extract size : "<<bitLine<<" Width :"<<width<<endl;
			extractRawFile.write(bitLine,width);
				}
			
			/*
			
			rawfile.open("brain_mri_raws/output"+output_prefix+".dat");
		 
			if(!extractRawFile){
			 
			 std::cout<<"Could't write file for extract "<<endl;
			 }else{
			for(int y; y<height;y++){
				char* bit = (char*) slicesVector[sliceId][y];
				extractRawFile.write(bit,width);
				//cout<<"*";
			//rawfile<<"Please writr this text to a file.\n this text is written using C++\n";
									}
			}	
			*/
		}
		
	//int RSKJAM001 :: VolImage :: numOfImages(void){
		//return numberImages;
		//}


