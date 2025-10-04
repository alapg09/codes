from fuel import convert, gauge
import pytest

def test_convert_valid():
    assert convert("1/4") == 25
    assert convert("1/2") == 50
    assert convert("99/100") == 99
    assert convert("0/1") == 0

def test_convert_invalid():
    with pytest.raises(ValueError):
        convert("4/3")  
    with pytest.raises(ValueError):
        convert("1/")  
    with pytest.raises(ValueError):
        convert("a/b")  
    with pytest.raises(ZeroDivisionError):
        convert("1/0")  

def test_gauge():
    assert gauge(1) == "E"
    assert gauge(99) == "F"
    assert gauge(0) == "E"
    assert gauge(50) == "50%"
    assert gauge(75) == "75%"
