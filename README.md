### Tic-Tac-Toe Project Using C++

This Tic-Tac-Toe project is a console-based game developed in C++. It allows players to either play against another human or against an AI with two levels of difficulty (Easy and Hard). Below is a detailed description of the components and functionality of the program.

#### Global Variables
- `char arr[3][3]`: A 3x3 matrix representing the game board, initialized with numbers 1-9.
- `int choice`: Stores the user's choice of cell.
- `int row, column`: Represents the row and column of the chosen cell.
- `char turn`: Keeps track of whose turn it is ('X' or 'O').
- `bool draw`: Indicates whether the game is a draw.
- `int winnerX, winnerO, tieXO`: Counters for the number of wins by 'X', 'O', and ties.


#### Functions
- **display()**: Displays the current state of the game board.
- **winner()**: Checks for a winner or a draw. Returns:
  - `2` if 'X' wins
  - `-2` if 'O' wins
  - `1` if the game is ongoing
  - `0` if it's a draw
- **easy_mode()**: Handles the game logic for playing against an AI in Easy mode. The AI makes random moves.
- **hard_mode(int depth, bool isMaximizing, bool firstTime = true)**: Implements the minimax algorithm for the Hard mode AI. This AI makes optimal moves by simulating all possible outcomes.
- **player2()**: Manages the game logic for a two-player mode.
- **game_mode(int m)**: Initiates the game based on the chosen mode (Easy or Hard).
- **welcome()**: Displays the welcome message and game mode options.
- **winnerXO(int winner)**: Updates and displays the win/tie counters after each game.

#### Main Function
The `main()` function controls the game flow:
1. Displays a welcome message and prompts the user to choose a game mode.
2. Depending on the chosen mode:
   - **Two-player mode**: Calls `player2()` in a loop until a winner or a draw is detected.
   - **AI mode**: Prompts for difficulty level (Easy or Hard) and calls `game_mode(m)`.
3. After each game, updates the win/tie counters using `winnerXO()`.
4. Asks if the player wants to play again. If yes, resets the game board; if no, exits the game.

### How to Play
1. Run the program.
2. Choose a mode:
   - **[1] 2 PLAYERS**: Play against another human.
   - **[2] AI**: Play against the computer.
3. If AI mode is selected, choose the difficulty:
   - **[1] Easy Mode**: AI makes random moves.
   - **[2] Hard Mode**: AI uses the minimax algorithm to make optimal moves.
4. Follow on-screen prompts to make your moves by entering the corresponding cell number.
5. The game will display the board after each move and check for a winner or a draw.
6. After the game ends, the program will display the updated win/tie counts and ask if you want to play again.
7. If you choose to play again, the board will reset. If not, the program will exit.

This project demonstrates basic game logic, AI implementation using the minimax algorithm, and user interaction through a console interface.
