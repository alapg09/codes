from plates import is_valid

def test_length():
    assert is_valid("AA") == True
    assert is_valid("A") == False
    assert is_valid("ABCDEFG") == False

def test_start_with_letters():
    assert is_valid("AB123") == True
    assert is_valid("123AB") == False
    assert is_valid("1AB23") == False
    assert is_valid("A123") == False

def test_numbers_at_end():
    assert is_valid("ABC123") == True
    assert is_valid("ABC12D") == False
    assert is_valid("ABC1234") == False

def test_no_leading_zero():
    assert is_valid("AB012") == False
    assert is_valid("AB120") == True

def test_no_special_characters():
    assert is_valid("AB@12") == False
    assert is_valid("AB 12") == False
    assert is_valid("AB12!") == False
