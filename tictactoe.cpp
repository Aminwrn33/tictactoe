#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void lovhe() 
{
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) cout << "|";
        }
        cout << "\n-------------\n";
    }
}

bool hereket(int move) {
    return (move >= 1 && move <= 9 && board[(move - 1) / SIZE][(move - 1) % SIZE] != 'X' && board[(move - 1) / SIZE][(move - 1) % SIZE] != 'O');
}

void hereketet(char player, int move) 
{
    board[(move - 1) / SIZE][(move - 1) % SIZE] = player;
}

bool qazananitap(char player) 
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool beraberetap() {
    for (int i = 0; i < SIZE; ++i) 
    {
        for (int j = 0; j < SIZE; ++j) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

int main() 
{
    char player = 'X';
    int move;

    while (true) 
    {
        lovhe();
        cout << "Oyuncu " << player << ", hansi hisseye oynamaq istediyinizi daxil edin (1 - 9): ";
        cin >> move;

        if (hereket(move)) 
        {
            hereketet(player, move);

            if (qazananitap(player)) {
                lovhe();
                cout << "Oyuncu " << player << " qazandi!\n";
                break;
            }

            if (beraberetap()) 
            {
                lovhe();
                cout << "Oyun bitdi ( Berabere )\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }
        else {
            cout << "yanlis hereket. yeniden cehd edin.\n";
        }
    }

    return 0;
}
 
//internetden axtaris etdim