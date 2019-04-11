I. Compilation
	- run command "Make" in terminal to produce an executable called driver. 
	- Use command "Make run" or "/.driver" in terminal to run without parameters
	- To run with parameters read below for options. 

II. Included Files:
	* Volimage.cpp 
	* Volimage.h 
	* Driver.cpp
	* this README
	* Makefile
	* brain_mri_raws  - folder with raw input images
	* viewer & diffmap - tools to view and check output


III. Command Line Arguments 
	* Volimage <imageBase> [-d i j output_file_name]
	* Volimage <imageBase> [-x i output_file_name]
	* Volimage <imageBase> [-g i]

IV. Program Explanition 
	The program has a Volimage.h this file has the declarations of methods which shows thier signature.
	The Volimage.cpp has method definitions.
	The Driver.cpp has the method implementation.

	
	The make file gives a the following files. Volimage.o , Driver.o , Driver (executable)
