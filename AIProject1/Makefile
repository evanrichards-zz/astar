all : a-star random_board

a-star : a-star.cpp Node.cpp MoveMapMaker.cpp
	g++ a-star.cpp Node.cpp MoveMapMaker.cpp -o a-star

random_board : random_board.cpp boardGenerator.cpp MoveMapMaker.cpp
	g++ -std=c++0x random_board.cpp boardGenerator.cpp MoveMapMaker.cpp -o random_board
