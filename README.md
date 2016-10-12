# Practice11
Practice8 have different file because I create the static library with gcc
Practice9 have different file because I create the dinamy library with gcc

to linked the pracrice 9 to a project you nedd this two command if you are running on the terminal
gcc -o "executable" "file.c" -L. -lpractice9 //the text inside the "" is the name of your project them you need to let the program know where are the library, this is because -L. <- the point and at the last are the library only with L and the name without the docks 
export LD_LIBRARY_PATH=. // to set up the enviroment fro teh library
