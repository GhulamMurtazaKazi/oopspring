Assume we’re writing a very bare bones program to figure out how we can apply OOP to Chess. Let’s
consider the following classes that will be interacting with each other to play the game.
The ChessPiece class is used for all chess pieces (pawn, rook, knight, etc.). Each piece has attributes such

as name(King, Queen, etc.), color (black or white) and a unique symbol (K/k-for king, Q/q-for queen, N/n-
for knight, etc.) to represent it on the board. Other requirements are as follows:

• Default Constructor: Whenever this constructor is called, it will create a white pawn.
• Parameterized Constructor: Creates a ChessPiece of the type specified by the parameters.
• Appropriate getters and setters for your member variables.
The ChessBoard class represents the chessboard itself. It contains a 2D array of ChessPiece to represent
the 8x8 grid. Each element of the array holds a pointer to a ChessPiece object or is set to null if there is no
piece at that position. The class has methods like display() to print the current state of the board, and aother
method, movePiece(), which is responsible for moving a piece from one position to another.
More details about the functions is given below:
• Default Constructor for the ChessBoard class should initialize the 2D array of chess pieces to an initial
game state (also shown below).
• The display() method should generate an output like this:
a b c d e f g h
8 R N B Q K B N R 8
7 P P P P P P P P 7
6 . . . . . . . . 6
5 . . . . . . . . 5
4 . . . . . . . . 4
3 . . . . . . . . 3
2 p p p p p p p p 2
1 r n b q k b n r 1
a b c d e f g h
White pieces can be represented by small alphabet while black pieces can be capital alphabets.
Note: R: Rook, N: Knight, B: Bishop, Q: Queen, K: King, P: Pawn

• The bool movePiece(string source, string destination) method is used to move the chess piece from
a source to destination. It returns true or false based on whether the move is valid or not. For simplicity’s
sake, let only consider the movements for knight and pawns on the first turn.
Example: Function is called as: movePiece(“b8”, “a6”), so this means we are moving the knight from
b8 to a6, which is a valid first move, so your function should return true. Similarly, if the function is
called as: movePiece(“b8”, “d7”), it should return false, as d7 is already occupied by a pawn.
Notes:
The knight moves in an "L" shape on the chessboard. It can move two squares in one direction (either
horizontally or vertically) and then one square in a perpendicular direction. Alternatively, it can move two
squares in a perpendicular direction and then one square in the original direction.
Meanwhile, during the first move only, a pawn has two possible moves: it can move forward by one or two
steps, only if there is nothing in its path.

#include<iostream>
#include<string>
using namespace std;
class chess_peice{
	string name,color,symbol;
	public:
		chess_peice() {
			name="pawn";
			color="white";
			symbol="p";
		}
		chess_peice(string n,string c,string s) {
			name=n;
			color=c;
			symbol=s;
		}
		string getname() {
			return name;
		}
		string getcolor() {
			return color;
		}
		string getsymbol() {
			return symbol;
		}
		void setname(string n) {
		name=n;
		 }
		void setcolor(string c) { 
		color=c;
		}
		void setsymbol(string s) {
		symbol=s;
		 }
};
class chessboard{
	chess_peice board[8][8];
	public:
		chessboard() {
			board[0][0]=chess_peice("rook","black","R");
			board[0][1]=chess_peice("knight","black","N");
				board[0][2]=chess_peice("Bishop","black","B");
					board[0][3]=chess_peice("Queen","black","Q");
						board[0][4]=chess_peice("king","black","K");
							board[0][5]=chess_peice("Bishop","black","B");
								board[0][6]=chess_peice("knight","black","N");
									board[0][7]=chess_peice("rook","black","R");
									for (int i=1;i<2;++i) {
										for (int j=0;j<8;++j) {
											board[i][j].setcolor("black");
											board[i][j].setsymbol("P");
										}
									}
									for (int i=2;i<6;i++) {
									for (int j=0;j<8;++j) 
										board[i][j].setsymbol("-");
								}
					for(int i=7;i<8;++i) {
						for (int j=0;j<8;++j) {
							board[i][j]=board[i-7][j];
							board[i][j].setcolor("white");
							board[i][j].setsymbol(string(1, tolower(board[i-7][j].getsymbol().at(0))));
						}
					}
		}
		void display() 
		{
			int i=0,j;
			while (i<8) {
				j=0;
				while (j<8) {
					cout<<board[i][j].getsymbol()<<"\t";
					++j;
				}
				cout<<endl;
				++i;
			}
		}
		bool move_peice(string source,string destination) {
			int i,j,k,l;
		i=(source.at(1)-56)*(-1);
		j=source.at(0)-97;
		k=(destination.at(1)-56)*(-1);
		l=destination.at(0)-97;
		if (board[i][j].getsymbol()=="p"||board[i][j].getsymbol()=="P") {
			if ((i+1==k||i+2==k)&&(j==l)) {
				if (board[k][l].getsymbol()!="-"&&board[i][j].getcolor()!=board[k][l].getcolor()) {
					board[k][l]=board[i][j];
					board[i][j].setsymbol("-");
					return true;
				}
				else if (board[k][l].getsymbol()=="-") {
					board[k][l]=board[i][j];
					board[i][j].setsymbol("-");
					return true;
			}
			}
		}
		else if (board[i][j].getsymbol()=="N"||board[i][j].getsymbol()=="n") {
			if ((k<i+3&&k>i-3)&&(l<j+3&&l>j-3)) {
				if (board[k][l].getsymbol()!="-"&&board[i][j].getcolor()!=board[k][l].getcolor()) {
					board[k][l]=board[i][j];
					board[i][j].setsymbol("-");
					return true;
			}
			else if (board[k][l].getsymbol()=="-") {
					board[k][l]=board[i][j];
					board[i][j].setsymbol("-");
					return true;
			}
		}
		}
		return false ;
	}
};
int main () {
	chessboard game;
	game.display();
	if (game.move_peice("b8","d7")==true) game.display();
	else cout<<"invalid move\n";
	if (game.move_peice("b8","a6")==true) game.display();
	else cout<<"invalid move\n";
	return 0;
}
