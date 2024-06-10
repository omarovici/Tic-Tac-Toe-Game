#include <iostream>
using namespace std;
char arr[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int choice;
int row, column;
char turn = 'X';
bool draw = false;
int winnerX = 0 , winnerO = 0 , tieXO  = 0 ;
void display()
{
    cout << "☆ T i C • T A C • T O E ☆" << endl;
    cout << "----------------------" << endl;
    cout << "|      |      |      |" << endl;
    cout << "|   " << arr[0][0] << "  |   " << arr[0][1] << "  |   " << arr[0][2] << "  |" << endl;
    cout << "----------------------" << endl;
    cout << "|      |      |      |" << endl;
    cout << "|   " << arr[1][0] << "  |   " << arr[1][1] << "  |   " << arr[1][2] << "  |" << endl;
    cout << "----------------------" << endl;
    cout << "|      |      |      |" << endl;
    cout << "|   " << arr[2][0] << "  |   " << arr[2][1] << "  |   " << arr[2][2] << "  |" << endl;
    cout << "----------------------" << endl;
}
int winner() {
    if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')return 2;
    else if (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')return 2;
    else if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')return 2;
    else if (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')return 2;
    else if (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')return 2;
    else if (arr[2][0] == 'X' && arr[1][1] == 'X' && arr[0][2] == 'X')return 2;
    else if (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')return 2;
    else if (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')return 2;
    else if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')return -2;
    else if (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')return -2;
    else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')return -2;
    else if (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')return -2;
    else if (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')return -2;
    else if (arr[2][0] == 'O' && arr[1][1] == 'O' && arr[0][2] == 'O')return -2;
    else if (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')return -2;
    else if (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')return -2;
    else {
        for (int i = 0; i < 3; i++)
            if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
                return 0;

        if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
            return 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (arr[i][j] != 'X' && arr[i][j] != 'O')
                    return 1;
        draw = 1;
        return 0;
    }
}
void easy_mode() {

    if (turn == 'X') {
        cout << "\nPlayer - 1 [X] turn : ";
        cin >> choice;
    }
    else {
        choice = rand() % 9 + 1;
    }
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            if (turn == 'X') {
                cout << "Invalid Move";
            }
    }

    if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'O';
        turn = 'X';
    }
    else {
        if (turn == 'X') {
            cout << "Box already filled!\n Please choose another!!\n\n";
        }
        easy_mode();
    }
}
int hard_mode(int depth, bool isMaximizing, bool firstTime = true) {
    int result = winner();
    if (depth == 0 || result != 1) {
        return result;
    }
    if (isMaximizing) {
        int finalScore = -10;
        int finalI, finalJ;
        char k;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] !='X' && arr[i][j] != 'O') {
                    k = arr[i][j];
                    arr[i][j] = 'X';
                    int score = hard_mode(depth - 1, false, false);
                    arr[i][j] = k;
                    if (score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }
        }
        if (firstTime) {
            arr[finalI][finalJ] = 'O';
        }
        return finalScore;
    }
    else {
        int finalScore = 10;
        int finalI, finalJ;
        char k;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] != 'X' && arr[i][j] != 'O') {
                    k = arr[i][j];
                    arr[i][j] = 'O';
                    int score = hard_mode(depth - 1, true, false);
                    arr[i][j] = k;
                    if (score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                }
            }
        }
        if (firstTime) {
            arr[finalI][finalJ] = 'O';
        }
        return finalScore;
    }
}
void player2() {
    if (turn == 'X') {
        cout << "\nPlayer - 1 [X] turn : ";
    }
    else if (turn == 'O') {
        cout << "\nPlayer - 2 [O] turn : ";
    }
    cin >> choice;
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move";
    }

    if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        arr[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "Box already filled!\n Please choose another!!\n\n";
        player2();
    }
}
void game_mode(int m) {
    if (m == 1) {
        srand(time(0));
        while (winner() == 1) {
            system("cls");
            display();
            easy_mode();
            winner();
        }
        display();
    }
    else if (m == 2) {
        int x, y;
        int choice;
        bool has_winner = false;
        char player = 'X';
        while (!has_winner) {
            system("cls");
            display();
            cin >> choice;
            switch (choice) {
                case 1: x = 0; y = 0; break;
                case 2: x = 0; y = 1; break;
                case 3: x = 0; y = 2; break;
                case 4: x = 1; y = 0; break;
                case 5: x = 1; y = 1; break;
                case 6: x = 1; y = 2; break;
                case 7: x = 2; y = 0; break;
                case 8: x = 2; y = 1; break;
                case 9: x = 2; y = 2; break;
                default:
                    cout << "Invalid Move";
            }
            if (arr[x][y] != 'X'&& arr[x][y] != 'O') {
                arr[x][y] = player;
                int result = hard_mode(100, false);
                display();
                has_winner = winner() != 1;
            }
            else {
                cout << "The field is not empty \n";
            }
        }
    }

}
void welcome(){
    cout << "                Welcome To The TIC TAC TOE Game! ツ" << endl;
    cout << "       Please Choose If You Want To Play Against AI Or A Second Player " << endl;
    cout << "             [1] - 2 PLAYERS           [2] - AI " << endl;
}
void winnerXO(int winner){
    if(winner==2) winnerX++;
    else if(winner==-2) winnerO++;
    else tieXO++;
    cout << "                         The Winning List " << endl;
    cout << "[X] - " << winnerX << endl << "[O] - " << winnerO << endl << "[Tie] - " << tieXO <<  endl;
}
int main() {

    while (1) {
        welcome();
        int n, m; cin >> n;
        switch (n)
        {
            case 1:
                while (winner() == 1) {
                    system("cls");
                    display();
                    player2();
                    winner();
                }
                display();
                winnerXO(winner());
                break;
            case 2:
                cout << "Please Choose If You Want The AI On Easy Mode Or Hard Mode" << endl;
                cout << "[1] - Easy Mode           [2] - Hard Mode " << endl;
                cin >> m;
                if (m == 1 || m == 2) {
                    game_mode(m);
                    winnerXO(winner());
                }
                else {
                    cout << "invalid input! try again!";
                    main();
                }
                break;
            default:
                cout << "invalid input! try again!";
                main();
                break;
        }
        cout << "do you want to play again?!" << endl;
        cout << "\t[1] play again\t [2] exit" << endl;
        int p; cin >> p;
        if (p == 1) {
            int cnt = '1' ;
            for (int i = 0 ; i < 3 ; ++i) {
                for (int j = 0 ; j < 3 ; ++j) {
                    arr[i][j] = cnt;
                    cnt++;
                }
            }
            continue;
        }
        else break;
    }
}