from project import initialize_grid, valid_move, count_adj_mines
import pytest


def test_initialize_grid():
    grid = initialize_grid(3, 3)
    assert len(grid) == 3  # 3 rows
    assert len(grid[0]) == 3  # 3 columns

def test_valid_move():
    assert valid_move(1, 1, 5, 5) == True  # Inside grid
    assert valid_move(-1, 2, 5, 5) == False  # Out of bounds (negative row)
    assert valid_move(2, 5, 5, 5) == False  # Out of bounds (column)

def test_count_adj_mines():
    grid = [
        ['.', '*', '.'],
        ['*', '.', '.'],
        ['.', '.', '*']
    ]
    assert count_adj_mines(1, 1, 3, 3, grid) == 2  # Mines at (0,1) and (1,0)
    assert count_adj_mines(0, 0, 3, 3, grid) == 2  # Mine at (0,1) and (1,0)
    assert count_adj_mines(2, 2, 3, 3, grid) == 0  # No adjacent mines
