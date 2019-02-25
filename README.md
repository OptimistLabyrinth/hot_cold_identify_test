# Terminal Command Examples
## BUILD
#### &ensp;(in the root directory of project)  
&emsp;$ mkdir build && cd build && cmake ..     
&emsp;$ make    
&emsp;$ ./hot_cold_test    

## Clear
#### &ensp;(in the build directory)
&emsp;$ cd .. && rm -rf build/    

## Requiremets
&emsp;CMake >= 3.0 (using "$ make")    
&emsp;GCC >= 4.8 (using "$ g++")    
&emsp;Clang >= 3.3 (using "$ g++")    

## Configurations
&emsp;{std::string path}        : path to the input and output data (such as .txt)    
&emsp;{std::string file_name}   : name of the input data file    
&emsp;{std::string output_name} : name of the output data file    

&emsp;{int RANGE} : range of block number    
&emsp;{int W}     : maximum size of the window, that is nubmer of slot sequence    
&emsp;&emsp;&emsp;(these two variables correspond with input data file)    
