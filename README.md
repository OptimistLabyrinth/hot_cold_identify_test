# Terminal Command Examples
## BUILD
#### &ensp;(in the root directory of project)  
&emsp;$ mkdir build && cd build && cmake ..     
&emsp;$ make    
&emsp;$ ./hot_cold_test    

## Clear
#### &ensp;(in the build directory)
&emsp;$ make clean    

&emsp;$ cd .. && rm -rf build/  (you can clear by removing the directory itself)    

## Requiremets
&emsp;CMake >= 3.0 (using "$ make")    
&emsp;GCC >= 4.8 (using "$ g++")    
&emsp;Clang >= 3.3 (using "$ g++")    

## Configurations
&emsp;{std::string path}        : path to the input and output data    
&emsp;{std::string file_name}   : name of the input data file (such as .txt)    
&emsp;{std::string output_name} : name of the output data file (such as .txt)    

&emsp;{int RANGE} : range of block number    
&emsp;{int W}     : maximum size of the window, that is nubmer of slot sequence    
&emsp;&emsp;&emsp;(these two variables correspond with input data file)    

&emsp;In the function "start_test_algorith( )," I wrote comments explain my idea. You can read it and understand how it works.

## Using test_case_xx.txt
&emsp;(for "test_case_01.txt" and "test_case_02.txt") RANGE = 5, W = 5    
&emsp;(for "test_case_03.txt" and "test_case_03.txt") RANGE - 8, W = 10    
