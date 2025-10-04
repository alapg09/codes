
from twttr import shorten

def test_no_vowels():
    assert shorten("aeiou") == ""
    assert shorten("AEIOU") == ""

def test_mixed_characters():
    assert shorten("hello") == "hll"
    assert shorten("HELLO") == "HLL"

def test_numbers_and_symbols():
    assert shorten("1234") == "1234"
    assert shorten("@#hello123") == "@#hll123"

def test_empty_string():
    assert shorten("") == ""

def test_only_consonants():
    assert shorten("bcdfg") == "bcdfg"
    assert shorten("BCDFG") == "BCDFG"


def test_punctuation():
    assert shorten("hello, world!") == "hll, wrld!"
    assert shorten("Testing... 1, 2, 3!") == "Tstng... 1, 2, 3!"
    assert shorten("CS50: Python's best!") == "CS50: Pythn's bst!"
