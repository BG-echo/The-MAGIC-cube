# The-MAGIC-cube
This is a rotating cube written using C++ and SDL2

The main.cpp file contains the main code inside the int main() function.
The Matrix.cpp file contains the other functions for the purpose of matrix calculations.

The executable is the todo.exe and you can run it if you have it in the same folder as the SDL2.dll file
as this program is dynamically linked with the SDL2.dll file.

You can choose to edit this file, but then you have to link it with SDL2, for that follow the following steps:
1. Put the main.cpp and the Matrix.cpp file in a folder (You can name the folder what ever you want).
2. Then download SDL from there website and put the SDL2.dll and the libSDL2main.a files in a folder named lib which must be inside another folder named bin.
3. And also put the SDL2 folder from the SDL zip in a folder named include which must be inside the bin folder.
4. Now, put the folder you made to put the main.cpp and the Matrix.cpp files in the same folder where there is the bin folder.
5. run the command 'g++ -o <executable filename> <folder containing the main.cpp file>/main.cpp -Lbin/lib -lSDL2 -lmingw32 -lSDL2main' and press enter.
6. YOU MUST HAVE DOWNLOADED MINGW or MSYS2 FROM BEFORE.

# NOTE : THIS CURRENTLY WORKS ONLY ON WINDOWS
