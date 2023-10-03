# ap3-jutge
<p align="justify">This repository contains codes and helpful tools for AP3 (Algorithmic and Programming III) course.</p>

## Compilation settings

<p align="justify">As we are going to use C++ as the main programming language in this course, i have installed g++ compiler in my ubuntu (windows subsystem for linux) distribution. The following line is a remainder about the flags we have to use in order to compile the code file using the cited compiler, show all generated warnings during compilation, choose the level of optimization we require and choose the name of the output file that we will execute to run the final program.</p>

`g++ -Wall -O3 code_file_name -o executable_file_name`

<p align="justify">Then, wheter we want to feed our executable program with an input file, we can run the following command in the temrinal, providing a test input file.</p>

`./executable_file_name < test_input_file`
