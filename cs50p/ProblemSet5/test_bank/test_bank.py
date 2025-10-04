# test_bank.py
from bank import value

def test_hello():
    assert value("hello") == 0
    assert value("Hello") == 0
    assert value("HELLO there") == 0

def test_h_but_not_hello():
    assert value("hey") == 20
    assert value("hi") == 20
    assert value("how are you?") == 20

def test_other_starts():
    assert value("what's up") == 100
    assert value("good morning") == 100
    assert value("123hello") == 100

def test_edge_cases():
    assert value("") == 100  # Empty string
    assert value("!hello") == 100  # Starts with punctuation
    assert value("20hello") == 100  # Starts with a number
