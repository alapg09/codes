from seasons import validate
import pytest

def test_invalidformats():
    with pytest.raises(SystemExit):
        validate("January 1, 1999")
    with pytest.raises(SystemExit):
        validate("01-01-1999")
    with pytest.raises(SystemExit):
        validate("1st Jan 1998")
    with pytest.raises(SystemExit):
        validate("1999-1-1")


