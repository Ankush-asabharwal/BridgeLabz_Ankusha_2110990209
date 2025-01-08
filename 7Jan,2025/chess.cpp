#include <iostream>

#include <cmath>

using namespace std;

const int b_s = 8;

void findCoordinates(char board[b_s][b_s], string from, string to)
{

}

void printC(char board[b_s][b_s]) {
    cout << "            Black's side           " << endl;
    cout << "    a   b   c   d   e   f   g   h  " << endl;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for (int i=0; i<b_s; i++) {
        cout << i+1;
        for (int j=0; j<b_s;j++) {
            cout << " | " << board[i][j];
        }
        cout << " | ";
        cout << i+1;
        cout << endl;
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
    }
    cout << "    a   b   c   d   e   f   g   h  " << endl;
    cout << "            White's side           " << endl;
}

bool isValidMove(char board[b_s][b_s], string from, string to, bool isWhiteTurn) {
    if (from.length() != 2 || to.length() != 2) return false;
    int f1 = from[1] - '1';
    int f2 = toupper(from[0]) - 'A';
    int t1 = to[1] - '1';
    int t2 = toupper(to[0]) - 'A';
    if (f1 < 0 || f1 >= b_s || f2 < 0 || f2 >= b_s || t1 < 0 || t1 >= b_s || t2 < 0 || t2 >= b_s)
        return false;

    char piece = board[f1][f2];
    if (piece == '.') return false;  
    if (isWhiteTurn && !isupper(piece)) return false; 
    if (!isWhiteTurn && !islower(piece)) return false; 
    if(abs(f1-t1)>1 || abs(f2-t2)>1) return false;
    return true;
}

bool kill(char board[b_s][b_s], string from, string to)
{
    int f1 = from[1] - '1';
    int f2 = toupper(from[0]) - 'A';
    int t1 = to[1] - '1';
    int t2 = toupper(to[0]) - 'A';
    char peice = board[f1][f2];
    int leftU = board[f1-1][f2-1];
    int rightU = board[f1-1][f2+1];
    int leftL = board[f1+1][f2-1];
    int rightL = board[f1+1][f2+1];
    if(isupper(peice)){
        if(leftU!='.'){
            board[f1][f2] = '.';
            leftU = peice;
            return true;
        }else if(rightU!='.'){
            board[f1][f2] = '.';
            rightU = peice;
            return true;
        }
    }else{
        if(leftL!='.'){
            board[f1][f2] = '.';
            leftL = peice;
            return true;
        }
        else if(rightL!='.'){
            board[f1][f2] = '.';
            rightL = peice;
            return true;
        }
    }
    return false;
}

void knightMove(char board[b_s][b_s],string from, string to)
{

}

void move(char board[b_s][b_s], string from, string to) {
    int f1 = from[1] - '1';
    int f2 = toupper(from[0]) - 'A';
    int t1 = to[1] - '1';
    int t2 = toupper(to[0]) - 'A';

    board[t1][t2] = board[f1][f2];
    board[f1][f2] = '.';
}

int main() {
    char board[b_s][b_s] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    string from;
    string to;
    bool turn = true; 
    while (true) {
        printC(board);
        if(turn){
            cout << "White's Turn" << endl;
        }else{
            cout << "Black's Turn" << endl;
        }
        cin >> from;
        if (from == "exit") {
            cout << "Game Over" << endl;
            break;
        }
        cin >> to;

        if (!isValidMove(board, from, to, turn)) {
            cout << "Invalid Move" << endl;
            continue;
        }
        if(kill(board, from,to)){
            cout << "Peice Killed" << endl;
        }else{
            move(board, from, to);
        }
        turn = !turn; 
    }

    return 0;
}
