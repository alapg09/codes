from um import count


def test_word():
    assert count("yummy") == 0

def test_space():
    assert count("hello, um, world") == 1
    assert count(" um ") == 1
    assert count("?um?") == 1

def test_case():
    assert count("Um, um, UM, uM") == 4
