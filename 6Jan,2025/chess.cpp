#include<iostream> 

using namespace std;

const int board_size = 8; 

void printC(char board[board_size][board_size])
{
    cout << "            Black's side           " << endl;
    cout << "    a   b   c   d   e   f   g   h  " << endl;
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for(int i=0;i<board_size;i++){
            cout<<i+1;
        for(int j=0;j<board_size;j++){
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

int main()
{
   char board[board_size][board_size] = {
   {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
   {'.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.'},
   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
   {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
   };

   printC(board);

   return 0;

}
