from numb3rs import validate

def test_firstbyteonly():
    assert validate("127.0.0.1") == True
    assert validate("258.5.5.1") == False
    assert validate("127.255.256.257") == False

def test_fivebyte():
    assert validate("123.12.25.25.255") == False
    assert validate("124.22") == False


