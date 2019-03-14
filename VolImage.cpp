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
				cout<<"brain_mri_raws/"+baseName+""+pos+".raw"<<endl;
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
							
							cout<<" inside "<< ycord<<" index"<<endl;
							//char* point = new char[rawfile.tellg()];
							slice = new unsigned char[width];
							cout<<" point "<< ycord<<" index"<<endl;
							rawfile.read((char*)slice,width);
							
							
							//rawfile.read(point,sizeof(int) );
							cout<<" rawfile "<< ycord<<" index"<<endl;
							imageArray[ycord] = slice;
							cout<<" imageArray "<< imageArray[ycord] <<endl;
							cout<<endl;
							cout<<endl;
					}
					cout<<" End of for loop"<<endl;
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
		
			for(int r=0;r<height;r++){
				for (int c=0;c<width;c++){
				(unsigned char)(abs((float)slicesVector[sliceI][width][height] - (float)slicesVector[sliceJ][width][height])/2);
				
										 }
									}
		
		}
		
		
	void RSKJAM001:: VolImage:: extract(int sliceId, std::string output_prefix){
		
		unsigned char** slice = slicesVector[sliceId];
		std::ofstream file("output"+output_prefix+".dat");
		file<<1<<" "<<1<<" "<<1;
		 ofstream rawfile;
		 rawfile.open("output.txt");

		 rawfile.open("brain_mri_raws/output"+output_prefix+".dat");
			for(int y; y<height;y++){
				for(int x;x<width;x++ ){
			//rawfile<<"Please writr this text to a file.\n this text is written using C++\n";
		
									}
								}
								
		}
		
		
	int RSKJAM001:: VolImage:: volImageSize(void){
		return width*height*slicesVector.size();
		}


