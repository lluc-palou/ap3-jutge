# ap3-jutge
This repository contains codes and helpful tools for AP3 (Algorithmic and Programming III) course.

## Compilation settings
As we are going to use c++ as the main programming language in this course, i have installed g++ compiler in my ubuntu (linux subsystem for windows) distribution. The following line is a remainder about the flags we have to use in order to compile the code file using the cited compiler, show all generated warnings during compilation, choose the level of optimization we require and choose the name of the output file that we will execute to run the final program.

<code>g++ -Wall -O3 code_file_name -o executable_file_name<code>

Then, wheter we want to feed our executable program with an input file, we can run the following command in the temrinal, providing a test input file.

<code>./executable_file_name < test_input_file<code>
