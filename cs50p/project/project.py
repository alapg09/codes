import re
import os
import random
from colorama import Fore, Back, Style, init    # for colors

init(autoreset=True)

def main():
    restart = True

    while restart:  # for resarting the game
        while True:
            #   MAIN_MENU
            print("***********************************************")
            print("*                                             *")
            print("*           Welcome to MINE ESCAPE            *")
            print("*                                             *")
            print("*          Please Select an Option            *")
            print("*                                             *")
            print("*    'e' for Easy   |      'h' for Hard       *")
            print("*    'q' to quit    |     'r' for Rules       *")
            print("*                                             *")
            print("***********************************************")
            ans = input("").strip().lower()

            # validated input
            if re.fullmatch(r"[ehqr]", ans ):
                break
            else:
                print("Invalid Input! Please enter a valid input(e/h/q/r)")

        match ans:
            case 'e':       # easy grid
                grid = initialize_grid(5, 5)    # creating the grid
                place_mines(5, 5, grid)
                rows, columns = 5, 5
            case 'h':       # hard grid
                grid = initialize_grid(8, 8)
                place_mines(8, 8, grid)
                rows, columns = 8, 8
            case 'r':
                show_rules()

                # going back to main-menu
                returning = input("Press 'r' to return to main menu or 'q' to quit").strip().lower()
                while returning != 'r' and returning != 'q':    # validation
                    returning = input("Invalid Input. Press (q/r)").strip().lower()

                if returning == 'r':
                    continue
                else:
                    break
            case 'q':
                break
            case _:
                pass

        # initialization of the grid to be displayed
        displayed_grid = initialize_grid(rows, columns)
        displayed_grid[0][0] = 'S'
        displayed_grid[rows-1][columns-1] = 'E'

        player_row, player_column = 0, 0

        while True:     # gameloop
            clear_screen()

            # display
            print("********MINE MAZE***********")
            display_grid(rows, columns, displayed_grid, player_row, player_column)
            print("****************************")

            player_row, player_column = movement(player_row, player_column, rows, columns, grid, displayed_grid)    # player movements

            # checking loosing conditon
            if grid[player_row][player_column] == '*':
                clear_screen()
                print("***********************************************")
                print("*                                             *")
                print("*          OOPS!!! You hit a mine!            *")
                print("*                GAME OVER!                   *")
                print("*                                             *")
                print("***********************************************")

                print("Here is the grid:")
                display_grid(rows, columns, grid, player_row, player_column)
                break

            # checking winning condition
            if player_row == rows - 1 and player_column == columns - 1:
                clear_screen()

                print("***********************************************")
                print("*                                             *")
                print("*          Congratulations! You reached       *")
                print("*                the goal.                    *")
                print("*                                             *")
                print("***********************************************")

                print("Here is the grid:")
                display_grid(rows, columns, grid, player_row, player_column)
                break
            # hint calculation
            adj_mines = count_adj_mines(player_row, player_column, rows, columns, grid)

            adj_mines = str(adj_mines)
            displayed_grid[player_row][player_column] = adj_mines

        while True:
            # asking for restarting or quitting
            temp = input("Do you want to go back to the main menu? (y/n)").strip().lower()
            if temp == 'y':
                restart = True
                break
            elif temp == 'n':
                restart = False
                break
            else:
                continue
    print("GoodBye!")

def show_rules():
    print("\n***************************************************************")
    print("*                           RULES                             *")
    print("***************************************************************")
    print("* 1. Use W (up), A (left), S (down), and D (right) to move.   *")
    print("* 2. The game ends if you step on a mine ('*').               *")
    print("* 3. Reach the bottom-right corner to win the game.           *")
    print("* 4. The number displayed on a cell shows adjacent mines.     *")
    print("* 5. Moves outside the grid are not allowed.                  *")
    print("* 6. If you choose 'r' from the menu, these rules will show.  *")
    print("***************************************************************\n\n")

def clear_screen():
    # Clear the console screen
        if os.name == 'nt':  # For Windows
            os.system('cls')
        else:  # For Unix/Linux/Mac
            os.system('clear')


def initialize_grid(rows, columns):
    # this creates a 2D list
    grid = [['.' for _ in range(columns)] for _ in range(rows)]
    return grid


def place_mines(rows, columns, grid):
    if rows == 5:
        num_mines = 5
    else:
        num_mines = 8
    placed_mines = 0

    while placed_mines < num_mines:
        r, c = random.randint(0, rows-1), random.randint(0, columns-1)
        if grid[r][c] != '*':  # Ensure mine is placed on an empty cell
            grid[r][c] = '*'
            placed_mines += 1



# Initialize colorama
init(autoreset=True)

def display_grid(rows, columns, grid, player_row, player_column):

    # printing the 2D array as a grid with different colours for different entities
    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == '*':  # Mine
                print(Fore.RED + grid[i][j], end=' ')
            elif grid[i][j] == '.':  # Empty space
                print(Fore.GREEN + grid[i][j], end=' ')
            else:
                if i == player_row and j == player_column:  # Player position
                    print(Fore.YELLOW + grid[i][j], end=' ')
                else:
                    print(Fore.WHITE + grid[i][j], end=' ')
        print()



def count_adj_mines(player_row, player_column, rows, columns, grid):
    adj_mines = 0

    # Check the top cell if it's within bounds
    if player_row - 1 >= 0 and grid[player_row - 1][player_column] == '*':
        adj_mines += 1

    # Check the bottom cell
    if player_row + 1 < rows and grid[player_row + 1][player_column] == '*':
        adj_mines += 1

    # Check the left cell
    if player_column - 1 >= 0 and grid[player_row][player_column - 1] == '*':
        adj_mines += 1

    # Check the right cell
    if player_column + 1 < columns and grid[player_row][player_column + 1] == '*':
        adj_mines += 1

    return adj_mines

def valid_move(new_row, new_col, rows, columns):
    """Checks if the move is within grid boundaries."""
    return 0 <= new_row < rows and 0 <= new_col < columns

def movement(player_row, player_column, rows, columns, grid, displayed_grid):
    """
    Handles player movement based on user input.
    Returns updated player_row and player_column.
    """
    new_row, new_column = player_row, player_column  # Temporary variables

    while True:
        move = input("Use W, A, S, D to move (up, left, down, right):\n").strip().lower()

        # validation
        if not re.fullmatch(r"[wasd]", move):
            print("Invalid input! Please enter a valid character (w/a/s/d).")
            continue  # Ask again if input is invalid

        if move == 'w':
            new_row -= 1
        elif move == 's':
            new_row += 1
        elif move == 'a':
            new_column -= 1
        elif move == 'd':
            new_column += 1


        if valid_move(new_row, new_column, rows, columns):
            player_row, player_column = new_row, new_column  # Valid move, return new position
            return player_row, player_column
        else:
            print("Invalid move! You can't go outside the grid.")
            new_row, new_column = player_row, player_column  # Reset invalid move

if __name__ == "__main__":
    main()
