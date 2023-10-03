# ap3-jutge
<p align="justify">This repository contains codes and helpful tools for AP3 (Algorithmic and Programming III) course.</p>

## Compilation settings

<p align="justify">As we are going to use C++ as the main programming language in this course, i have installed g++ compiler in my ubuntu (Windows Subsystem for Linux) distribution. The following line is a remainder about the flags we have to use in order to compile the code file using the cited compiler, show all generated warnings during compilation, choose the level of optimization we require and choose the name of the output file that we will execute to run the final program.</p>

`g++ -Wall -O3 code_file_name -o executable_file_name`

## Useful terminal notation

<p align="justify">Then, wheter we want to feed our executable program with an input file, we can run the following command in the temrinal, providing a test input file.</p>

`./executable_file_name < test_input_file`

<p align="justify">In some cases we might be interested in counting the number of output instances for a given program, we can manage using the following command, that employs a terminal pipeline.</p>

`./executable_file_name < test_input_file | wc`

<p align="justify">We can use too the following command that shows to the user the local execution time of the program, to have an idea, jutge will process your program since 1s execution at you local environment.</p>

`time ./executable_file_name < test_input_file`

