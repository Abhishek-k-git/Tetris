all: 
	g++ -Wall main.cpp Board.cpp Pieces.cpp UI.cpp Sounds.cpp -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -o game

# g++: This is the GNU C++ compiler command
# main.cpp Board.cpp Pieces.cpp UI.cpp Sounds.cpp: These are your C++ source files
# -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio: These are linker flags that specify the SFML libraries to link against
# -o game: This flag tells the compiler to create an executable file named Game
# -Wall: This additional flag enables compiler warnings, which can help identify potential issues in your code
# -I/usr/local/include/SFML: -I is an additional flag to include SFML headers file, if not set