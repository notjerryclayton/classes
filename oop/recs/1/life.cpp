/*
 * Jerry Clayton 
 * Recitation 01: Implements Conway's Game of Life
 */
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

const int GENERATIONS = 10;

vector<string> readBoardFromFile(){
	vector<string> board;

	ifstream fileStream("life.txt");
	if(!fileStream){
		cerr << "File not found\n";
		exit(1);
	}

	string line;
	while(getline(fileStream, line)){
		if(line != ""){
			board.push_back(line);
		}
	}
	return board;
}

void printBoard(const vector<string>& board){
	for(size_t row = 0; row < board.size(); row++){
		for(size_t col = 0; col < board[row].size(); col++){
			if(board[row][col] == '*') cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
}

vector<string> addBorder(const vector<string>& board){
	vector<string> borderBoard;
	int newRows = board.size() + 2;
	int newCols = board[1].size() + 2;

	string border;

	for(int i = 0; i < newCols; i++){
		border.push_back('-');
	}
	borderBoard.push_back(border);
	string newLine;
	for(int row =  0; row < board.size(); row++){
		newLine = '-' + board[row] + '-';
		borderBoard.push_back(newLine);
		newLine = "";
	}
	borderBoard.push_back(border);

	return borderBoard;
}

int computeNeighbors(const vector<string>& board, int row, int col){
	int neighbors = 0;
	for(int i = row-1; i <=row+1; i++){
		for(int j = col-1; j <=col+1; j++){
			if(i==row && j==col) continue;
			else if(board[i][j] == '*') neighbors++;
		}
	}
	return neighbors;
}
vector<string> computeNextGeneration(vector<string>& current){
		current = addBorder(current);
		vector<string> newBoard;
		int neighbors = 0;
		string newLine;
		for(int row = 1; row < current.size()-1; row++){ //ignore border
			newLine = "";
			for(int col = 1; col < current[row].size() - 1; col++){ //ignore border
				neighbors = computeNeighbors(current, row, col);
				if(current[row][col] == '*'){
					if(neighbors == 2 || neighbors == 3) newLine.push_back('*');
					else newLine.push_back('-');
				} 
				else if(neighbors == 3) newLine.push_back('*');
				else newLine.push_back('-');
			}
			newBoard.push_back(newLine);
		}
	return newBoard;
}

int main(){
	vector<string> board = readBoardFromFile();
	printBoard(board);
	cout << "Gen 0" << endl;
	for(int i = 0; i < GENERATIONS; i++){
		board = computeNextGeneration(board);
		printBoard(board);
		cout << "Gen " << i+1 << endl;
	}
}


