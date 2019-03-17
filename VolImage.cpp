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
#include <vector>
#include <fstream>
#include <string>
////////////
#include <math.h>
#include <sstream>
using namespace std;

//RSKJAM001::VolImage volimage;


bool RSKJAM001:: VolImage:: readImages(std::string baseName){
		vector<string> line;
		string fileExtension=".raw";
		string content;
		ifstream file("brain_mri_raws/"+baseName+".data");
		if(!file){
			cout<<"Error opening file"<<endl;
			}else{
		
			
			while(std::getline(file, content, ' ')) {
			line.push_back(content);  
				}
			file.close();
			
			istringstream ( line[0] ) >> width;
		    istringstream ( line[1] ) >> height;
			istringstream ( line[2] ) >> numberImages;
						
			//cout<<"width : "<<width<<" height : "<<height<<" numberImages :"<<numberImages<<endl;
			//cout<<"Test"<<
			for(int picNum =0; picNum<= numberImages; picNum++){ 			//loop through all images
				string pos;
				pos=to_string(picNum);												// the number of the imagie in string format
				//ifstream rawfile;
				//cout<<"######################";
				//rawfile.open("brain_mri_raws/"+baseName+""+pos+".raw",iso::binary);
				ifstream rawfile("brain_mri_raws/"+baseName+""+pos+".raw",std::ios::binary);
	//			cout<<"brain_mri_raws/"+baseName+""+pos+".raw"<<endl;
				//rawfile.open();
				streampos pix;
				if(!rawfile){
					cout<<" if statement"<<endl;
					cout<<"Error opening Image"<<endl;
					} else{
						
						
						pix = rawfile.tellg();
						// managed to open image
						unsigned char** imageArray = new unsigned char* [height];
						unsigned char* slice;
						for(int ycord=0; ycord<height;ycord++){
							imageArray[ycord] =  new unsigned char [width];
							
							//width
							
	//						cout<<" inside "<< ycord<<" index"<<endl;
							//char* point = new char[rawfile.tellg()];
							slice = new unsigned char[width];
	//						cout<<" point "<< ycord<<" index"<<endl;
							rawfile.read((char*)slice,width);
							
							
							//rawfile.read(point,sizeof(int) );
	//						cout<<" rawfile "<< ycord<<" index"<<endl;
							imageArray[ycord] = slice;
	//						cout<<" imageArray "<< imageArray[ycord] <<endl;
	//						cout<<endl;
	//						cout<<endl;
					}
	//				cout<<" End of for loop"<<endl;
					slicesVector.push_back(imageArray);
					rawfile.close();
					}
					
				
				}
			
			
		}
		
		return true;
		
		
}


		RSKJAM001:: VolImage::VolImage(){
			width = 0;
			height = 0;
			std:: vector<unsigned char **> slicesVector(0);
			}


			RSKJAM001:: VolImage::~VolImage(){ 
				for(std::size_t i =0; i< slicesVector.size();i++){
					for(int j =0; j< height;j++){
						delete[] slicesVector[i][j];
						 }
					delete [] slicesVector[i];
				}
				cout<< "Memory cleared "<<endl ;
			}


	void RSKJAM001:: VolImage:: diffmap(int sliceI, int sliceJ, std::string output_prefix){
			std::ofstream diffmapDatafile("-----------"+output_prefix+".dat",std::ios::binary);
			
			for(int r=0;r<height;r++){
				for (int c=0;c<width;c++){
				  /*(unsigned char)*/ char hold = abs(((float)slicesVector[sliceI][width][height] - (float)slicesVector[sliceJ][width][height])/2);
					diffmapDatafile.write(&hold,1);
										 }
									}
		
		}
		
		
	void RSKJAM001:: VolImage:: extract(int sliceId, std::string output_prefix){
		std::ofstream extractRawFile("-----------"+output_prefix+".raw",std::ios::binary);
		
		//unsigned char** slice = slicesVector[sliceId];
		std::ofstream file("*******   "+output_prefix+".dat", ios::out);
		file<<width<<" "<<height<<" "<<1;
		ofstream rawfile;
		rawfile.open(output_prefix+".data");

		 rawfile.open("brain_mri_raws/output"+output_prefix+".dat");
		 
		 if(!extractRawFile){
			 
			 std::cout<<"Could't write file for extract "<<endl;
			 }else{
			for(int y; y<height;y++){
				char* bitLine = (char*) slicesVector[sliceId][y];
				extractRawFile.write(bitLine,width);
				//cout<<"*";
			//rawfile<<"Please writr this text to a file.\n this text is written using C++\n";
									}
			}	
		}
		
		
	int RSKJAM001:: VolImage:: volImageSize(void){
		//return width*height*slicesVector.size();
		return (1 + height + width * height)* sizeof(unsigned char) * slicesVector.size(); // Size of uchars
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


