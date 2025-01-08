#include <iostream>

#include <cmath>

using namespace std;

// It remain constant throught the program because chess has grid of 8 X 8
const int board_size = 8;

void printC(char board[board_size][board_size]) {
//Print function to print the board or the grid according to the problem
    cout << "            Black's side           " << endl;
    cout << "    a   b   c   d   e   f   g   h  " << endl;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    // Printing the formatting by using loops 
    for (int i=0; i<board_size; i++) {
        cout << i+1;
        for (int j=0; j<board_size;j++) {
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

void findCoordinates(const string& from, const string& to, int& f1, int& f2, int& t1, int& t2)
{
    // This function is to find the coordinates of the input given by the user eg: e2 to e4

    // I will convert this into the coordinates according to the 2D matrix like source->(x1,y1) to
    // destination->(x2,y2)
    f1 = from[1] - '1';
    f2 = toupper(from[0]) - 'A'; // converting char to int by using ASCII value
    t1 = to[1] - '1';
    t2 = toupper(to[0]) - 'A';
}

// bool isValidMove(char board[board_size][board_size], string from, string to, bool isWhiteTurn) 
// {
//     // This function is for every peice that the move a user is given is valid or not
//     if (from.length() != 2 || to.length() != 2) return false;
//     int f1, f2, t1, t2; 
//     findCoordinates(from, to, f1, f2, t1, t2); // using coordinates for further use
//     if (f1 < 0 || f1 >= board_size || f2 < 0 || f2 >= board_size || t1 < 0 || t1 >= board_size || t2 < 0 || t2 >= board_size)
//         return false;
//     char piece = board[f1][f2]; // Storing the source position to the char peice
//     if (piece == '.') return false;
    
//     // It check if it is white turn then peice is not in the Upper alphabet
//     if (isWhiteTurn && !isupper(piece)) return false; 

//     // It check if it is black turn then peice is not in the lower alphabet
//     if (!isWhiteTurn && !islower(piece)) return false; 
//     return true;
// }

bool isValidMove(char board[board_size][board_size], string from, string to, bool isWhiteTurn) {
    if (from.length() != 2 || to.length() != 2) return false;
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2); // Using coordinates for further use

    // Check if coordinates are within bounds
    if (f1 < 0 || f1 >= board_size || f2 < 0 || f2 >= board_size || t1 < 0 || t1 >= board_size || t2 < 0 || t2 >= board_size)
        return false;

    char piece = board[f1][f2]; // Storing the source position to the piece
    if (piece == '.') return false; // No piece at the source

    // Check if the piece belongs to the current player
    if (isWhiteTurn && !isupper(piece)) return false; 
    if (!isWhiteTurn && !islower(piece)) return false; 

    // Rook movement (horizontal and vertical)
    if (piece == 'R' || piece == 'r') {
        if (f1 != t1 && f2 != t2) return false; // Rook can only move straight in rows or columns
        // Check if the path is clear (no blocking pieces in between)
        if (f1 == t1) { // Horizontal move
            for (int i = min(f2, t2) + 1; i < max(f2, t2); i++) {
                if (board[f1][i] != '.') return false;
            }
        } else { // Vertical move
            for (int i = min(f1, t1) + 1; i < max(f1, t1); i++) {
                if (board[i][f2] != '.') return false;
            }
        }
    }

    // Bishop movement (diagonal)
    if (piece == 'B' || piece == 'b') {
        if (abs(f1 - t1) != abs(f2 - t2)) return false; // Bishop moves diagonally
        // Check if the path is clear (no blocking pieces in between)
        int dx = (t1 > f1) ? 1 : -1;
        int dy = (t2 > f2) ? 1 : -1;
        for (int i = 1; i < abs(f1 - t1); i++) {
            if (board[f1 + i * dx][f2 + i * dy] != '.') return false;
        }
    }

    // Knight movement (L-shape)
    if (piece == 'N' || piece == 'n') {
        if (!((abs(f1 - t1) == 2 && abs(f2 - t2) == 1) || (abs(f1 - t1) == 1 && abs(f2 - t2) == 2))) return false;
    }

    // Queen movement (combination of rook and bishop)
    if (piece == 'Q' || piece == 'q') {
        if (f1 == t1 || f2 == t2) { // Rook-like move
            // Check if the path is clear (no blocking pieces in between)
            if (f1 == t1) { // Horizontal move
                for (int i = min(f2, t2) + 1; i < max(f2, t2); i++) {
                    if (board[f1][i] != '.') return false;
                }
            } else { // Vertical move
                for (int i = min(f1, t1) + 1; i < max(f1, t1); i++) {
                    if (board[i][f2] != '.') return false;
                }
            }
        } else if (abs(f1 - t1) == abs(f2 - t2)) { // Bishop-like diagonal move
            // Check if the path is clear (no blocking pieces in between)
            int dx = (t1 > f1) ? 1 : -1;
            int dy = (t2 > f2) ? 1 : -1;
            for (int i = 1; i < abs(f1 - t1); i++) {
                if (board[f1 + i * dx][f2 + i * dy] != '.') return false;
            }
        } else {
            return false; // Invalid queen move
        }
    }

    // King movement (1 square in any direction)
    if (piece == 'K' || piece == 'k') {
        if (abs(f1 - t1) > 1 || abs(f2 - t2) > 1) return false; // King can only move 1 square in any direction
    }

    // Pawn movement (one step forward or diagonal to capture)
    if (piece == 'P' || piece == 'p') {
        if (isupper(piece)) { // White pawn
            if (f1 - t1 == 1 && f2 == t2 && board[t1][t2] == '.') return true; // One step forward
            if (f1 - t1 == 1 && abs(f2 - t2) == 1 && islower(board[t1][t2])) return true; // Capture diagonally
        } else { // Black pawn
            if (t1 - f1 == 1 && f2 == t2 && board[t1][t2] == '.') return true; // One step forward
            if (t1 - f1 == 1 && abs(f2 - t2) == 1 && isupper(board[t1][t2])) return true; // Capture diagonally
        }
        return false;
    }

    return true; // If none of the above conditions failed, the move is valid
}


bool kill(char board[board_size][board_size], string from, string to) {
    // This function is to kill the another peice by pawn
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Storing the source and destination 
    char piece = board[f1][f2];
    char target = board[t1][t2];
    if (toupper(piece) == 'P') {
        // Killing the opponent's peice by detecting that it is in lower alphabet or in uppen alphabet
        if (abs(f2 - t2) == 1 && ((isupper(piece) && islower(target)) || (islower(piece) && isupper(target)))) {
            // Replacing the peice to destination from source
            board[t1][t2] = piece; 
            board[f1][f2] = '.';  
            return true;
        }
    }
    return false; 
}

void rookMove(char board[board_size][board_size],string from, string to)
{
    // This function is for rook to move vertically and horizontally only according to the chess rules
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2); // Again using the function for finding the coordinates for next move

    char piece = board[f1][f2];
    char target = board[t1][t2];
        if(board[t1][t2]!='.' && ((isupper(piece) && islower(target)) || (islower(piece) && isupper(target)))){
            // If the peice is detected than it will kill the opponent's peice
            cout << "Peice Detected and killed" << endl;
            board[t1][t2] = board[f1][f2];
            board[f1][f2] = '.';
        }else if(board[t1][t2]=='.'){
            // If the destination is empty it will go to destination from source
            board[t1][t2] = board[f1][f2];
            board[f1][f2] = '.';
        }
}

void knightMove(char board[board_size][board_size], string from, string to){
    // This function is for knight which can move in 'L-shape' only according to the chess rule.
    int f1, f2, t1, t2;
    findCoordinates(from,to,f1,f2,t1,t2);

    // It will check that move is valid or not like knight is moving in L shape or not
    if (!((abs(f1-t1)==2 && abs(f2-t2)==1) || (abs(f1-t1)==1 && abs(f2-t2)==2))) {
        cout << "Invalid move! l-shape" << endl;
        return;
    }
    // Storing source and destination in peice and target respectively. 
    char piece = board[f1][f2];
    char target = board[t1][t2];
    // It will check that knight doesn't kill their own side of peice, if ot is it will give the invalid move
    if (target!='.' && ((isupper(piece) && isupper(target)) || (islower(piece) && islower(target)))) {
        cout << "Invalid Move" << endl;
        return;
    }
    // if everything was ok then it will replace the peice to destination from the source
    board[t1][t2] = piece;
    board[f1][f2] = '.';
}

bool checkBishop(char board[board_size][board_size], string from, string to, int sumX, int sumY)
{
    // This function identifies that the move bishop is moving is valid or not
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Giving the base conditions that the coordinates that user entered is not out of bound
    if (f1 < 0 || f1 >= board_size || f2 < 0 || f2 >= board_size || t1 < 0 || t1 >= board_size || t2 < 0 || t2 >= board_size)
        return false;

    // Giving the conditions to the compiler that the bishop can move only diagonally
    if(board[t1][t2]== board[f1-sumX][f2+sumY] || board[t1][t2]== board[f1+sumX][f2+sumY] || 
       board[t1][t2]== board[f1-sumX][f2-sumY] || board[t1][t2]== board[f1+sumX][f2-sumY]){
        return true;
    }

    // check that the target contains the opponents peice or not
    char fromPiece = board[f1][f2]; // Storing the source value to fromPeice
    char toPiece = board[t1][t2]; // Storing the destination value to toPeice
    if (toPiece != '.' && ((isupper(fromPiece) && islower(toPiece)) || (islower(fromPiece) && isupper(toPiece)))) {
        return true;
    }

    return false;

}

void bishopMove(char board[board_size][board_size], string from, string to)
{
    // 
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);
    int sumX = abs(f1-f2); //To find that how many steps bishop wants to move in X-coordinate
    int sumY = abs(t1-t2); //To find that how many steps bishop wants to move in Y-coordinate

    // Now checking that bishop move is valid or not to move to target
    if (checkBishop(board, from, to, sumX, sumY)) {
        char targetPiece = board[t1][t2];

        //If the opponents peice find in target place then it remove that peice from target position
        if (targetPiece != '.') {
            cout << "Piece Captured: " << targetPiece << endl;
        }
        board[t1][t2] = board[f1][f2];  // Move the bishop
        board[f1][f2] = '.';           // Clear the original square
    } else {
        // If there is no option for bishop to move then it will give the invalid move
        cout << "B Done" << endl;
        cout << "Invalid Move" << endl;
    }
}

bool checkQueen(char board[board_size][board_size], string from, string to, int sumX, int sumY){
    // Again calling this function to access the coordinates
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Giving base conditions that coordinates doesn't go out of bound
    if (f1 < 0 || f1 >= board_size || f2 < 0 || f2 >= board_size || t1 < 0 || t1 >= board_size || t2 < 0 || t2 >= board_size)
        return false;

    // Giving conditions to the queen that it can move only in these directions only
    if(board[t1][t2]== board[f1-sumX][f2+sumY] || board[t1][t2]== board[f1+sumX][f2+sumY] || 
       board[t1][t2]== board[f1-sumX][f2-sumY] || board[t1][t2]== board[f1+sumX][f2-sumY] ||
       board[t1][t2]== board[f1][f2+sumY] || board[t1][t2]== board[f1][f2-sumY] ||
       board[t1][t2]== board[f1-sumY][f2] || board[t1][t2]== board[f1+sumY][f2]){
        return true;
    }

    // Check if the target is opponent's peice or not
    char fromPiece = board[f1][f2];
    char toPiece = board[t1][t2];
    if (toPiece != '.' && ((isupper(fromPiece) && islower(toPiece)) || (islower(fromPiece) && isupper(toPiece)))) {
        return true;
    }
    return false;
}   

void queenMove(char board[board_size][board_size], string from, string to){
    // The simple logic to move queen was that i can combine the functionality of two peice
    // which was bishop and rook because
    // rook move horizontally and vertically only
    // and bishop move diagonally only
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);
    int sumX = abs(f1-f2);
    int sumY = abs(t1-t2);
    // Check if the queen's move is valid
    if (checkQueen(board, from, to, sumX, sumY)) {
        char targetPiece = board[t1][t2];

        // If the target square contains an opponent's piece, capture it
        if (targetPiece != '.') {
            cout << "Piece Captured: " << targetPiece << endl;
        }
        board[t1][t2] = board[f1][f2];  // Move the queen
        board[f1][f2] = '.';           // Clear the original square
    } else {
        // Invalid move message
        cout << "Q Done" << endl;
        cout << "Invalid Move" << endl;
    }
}

bool checkKing(char board[board_size][board_size], string from, string to)
{
    // Again calling this function to access the coordinates
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Giving base conditions that coordinates doesn't go out of bound
    if (f1 < 0 || f1 >= board_size || f2 < 0 || f2 >= board_size || t1 < 0 || t1 >= board_size || t2 < 0 || t2 >= board_size)
        return false;

    // Giving conditions to the king that it can move only in these directions only
    if(board[t1][t2]== board[f1-1][f2] ||
       board[t1][t2]== board[f1-1][f2+1] ||
       board[t1][t2]== board[f1][f2+1] ||
       board[t1][t2]== board[f1+1][f2+1] ||
       board[t1][t2]== board[f1+1][f2] ||
       board[t1][t2]== board[f1+1][f2-1] ||
       board[t1][t2]== board[f1][f2-1] ||
       board[t1][t2]== board[f1-1][f2-1]){
        return true;
    }

    // Checking if the target square contains an opponent's piece
    char fromPiece = board[f1][f2];
    char toPiece = board[t1][t2];
    if (toPiece != '.' && ((isupper(fromPiece) && islower(toPiece)) || (islower(fromPiece) && isupper(toPiece)))) {
        return true;
    }
       return false;
}

void kingMove(char board[board_size][board_size], string from, string to)
{
    // Again calling this function to access the coordinates
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Check if the king's move is valid
    if (checkKing(board, from, to)) {
        char targetPiece = board[t1][t2];

        // If the target square contains an opponent's piece, capture it
        if (targetPiece != '.') {
            cout << "Piece Captured: " << targetPiece << endl;
        }
        board[t1][t2] = board[f1][f2];  // Move the king
        board[f1][f2] = '.';           // Clear the original square
    } else {
        // Invalid move message
        cout << "K Done" << endl;
        cout << "King has no other option" << endl;
    }
}

bool isKingInCheck(char board[board_size][board_size], int kingX, int kingY)
{
    // Check for pawns (only diagonal attacks)
    if (kingX - 1 >= 0 && kingY - 1 >= 0 && board[kingX - 1][kingY - 1] == 'p') return true;
    if (kingX - 1 >= 0 && kingY + 1 < board_size && board[kingX - 1][kingY + 1] == 'p') return true;

    // Check for knights (L-shaped moves)
    int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    for (int i = 0; i < 8; ++i) {
        int x = kingX + knightMoves[i][0];
        int y = kingY + knightMoves[i][1];
        if (x >= 0 && x < board_size && y >= 0 && y < board_size && board[x][y] == 'n') {
            return true;  // Opponent's knight
        }
    }

    // Check for rooks and queens (horizontal/vertical)
    for (int i = 1; i < board_size; ++i) {
        if (kingX - i >= 0 && board[kingX - i][kingY] != '.' && board[kingX - i][kingY] == 'r') return true; // Rook attack
        if (kingX + i < board_size && board[kingX + i][kingY] != '.' && board[kingX + i][kingY] == 'r') return true; // Rook attack
        if (kingY - i >= 0 && board[kingX][kingY - i] != '.' && board[kingX][kingY - i] == 'r') return true; // Rook attack
        if (kingY + i < board_size && board[kingX][kingY + i] != '.' && board[kingX][kingY + i] == 'r') return true; // Rook attack
    }

    // Check for bishops and queens (diagonal)
    for (int i = 1; i < board_size; ++i) {
        if (kingX - i >= 0 && kingY - i >= 0 && board[kingX - i][kingY - i] != '.' && board[kingX - i][kingY - i] == 'b') return true; // Bishop attack
        if (kingX + i < board_size && kingY + i < board_size && board[kingX + i][kingY + i] != '.' && board[kingX + i][kingY + i] == 'b') return true; // Bishop attack
        if (kingX - i >= 0 && kingY + i < board_size && board[kingX - i][kingY + i] != '.' && board[kingX - i][kingY + i] == 'b') return true; // Bishop attack
        if (kingX + i < board_size && kingY - i >= 0 && board[kingX + i][kingY - i] != '.' && board[kingX + i][kingY - i] == 'b') return true; // Bishop attack
    }

    return false;
}

bool isKingInCheckmate(char board[board_size][board_size], int kingX, int kingY)
{
    // Check if the king is in check
    if (!isKingInCheck(board, kingX, kingY)) return false;

    // Check if the king has any valid move to escape check
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the current position

            int newX = kingX + i;
            int newY = kingY + j;

            // Make sure new position is within the board
            if (newX >= 0 && newX < board_size && newY >= 0 && newY < board_size) {
                // Check if the move puts the king out of check
                if (board[newX][newY] == '.' && !isKingInCheck(board, newX, newY)) {
                    return false;  // King can move to a safe square
                }
            }
        }
    }

    return true;  // King has no safe move, checkmate
}

void move(char board[board_size][board_size], string from, string to) {
    // Again calling this function to access the coordinates
    int f1, f2, t1, t2;
    findCoordinates(from, to, f1, f2, t1, t2);

    // Moving the peice to target position
    board[t1][t2] = board[f1][f2];
    board[f1][f2] = '.';
}

int main() {
    char board[board_size][board_size] = {
        // {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        // {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        // {'.', '.', '.', '.', '.', '.', '.', '.'},
        // {'.', '.', '.', '.', '.', '.', '.', '.'},
        // {'.', '.', '.', '.', '.', '.', '.', '.'},
        // {'.', '.', '.', '.', '.', '.', '.', '.'},
        // {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        // {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
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
            cout << "y" << endl;
            cout << "Invalid Move" << endl;
            continue;
        } 
        int f1 = from[1] - '1';
        int f2 = toupper(from[0]) - 'A';
        char piece = board[f1][f2];
        if (piece == 'R' || piece == 'r') {
            rookMove(board, from, to);
        } else if (piece == 'N' || piece == 'n') {
            knightMove(board, from, to);
        } else if (piece == 'B' || piece == 'b') {
            bishopMove(board, from, to);
        } else if (piece == 'Q' || piece == 'q') {
            queenMove(board, from, to); 
        } else {
            if (kill(board, from, to)) {
                cout << "Piece Killed" << endl;
            } else {
                move(board, from, to);
            }
        }
        turn = !turn; 
    }
    return 0;
}
