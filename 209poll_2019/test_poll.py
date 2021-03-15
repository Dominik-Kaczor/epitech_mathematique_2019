#!/usr/bin/env python3

import pytest
import imp
poll = imp.load_source('209poll', './209poll')

def test_helper(capsys):
    poll.main(["209poll", "-h"])
    captured = capsys.readouterr()
    assert "USAGE\n\t./209poll pSize sSize p\n\nDESCRIPTION\n\tpSize\tsize of the population\n\tsSize\tsize of the sample (supposed to be representative)\n\tp\tpercentage of voting intentions for a specific candidate" in captured.out

def test_10000_500_42_24(capsys):
    result = poll.main(["209poll", "10000", "500", "42.24"])
    captured = capsys.readouterr()
    assert "[38.02%; 46.46%]" in captured.out
    assert "0.000464" in captured.out
    assert result == 0

def test_10000_100_45(capsys):
    result = poll.main(["209poll", "10000", "100", "45"])
    captured = capsys.readouterr()
    assert "[35.30%; 54.70%]" in captured.out
    assert "0.002450" in captured.out
    assert result == 0

def test_300_100_45(capsys):
    result = poll.main(["209poll", "300", "100", "45"])
    captured = capsys.readouterr()
    assert "[34.50%; 55.50%]" in captured.out
    assert "0.001656" in captured.out
    assert result == 0

def test_100_200_300(capsys):
    result = poll.main(["209poll", "100", "200", "300"])
    captured = capsys.readouterr()
    assert "[255.09%; 100.00%]" in captured.out
    assert "0.030303" in captured.out
    assert result == 0

def test_458_9_23_673(capsys):
    result = poll.main(["209poll", "458.9", "23", "673"])
    captured = capsys.readouterr()
    assert "invalid literal for int()" in captured.out
    assert result == 84

def test_1234_5_1234_5_1234_5(capsys):
    result = poll.main(["209poll", "1234.5", "1234.5", "1234.5"])
    captured = capsys.readouterr()
    assert "invalid literal for int()" in captured.out
    assert result == 84

def test_neg():
    result = poll.main(["209poll", "-10000", "-500", "-42.24"])
    assert result == 84

def test_bad_arg():
    result = poll.main(["209poll", "10000", "500"])
    assert result == 84

def test_0_0_0(capsys):
    result = poll.main(["209poll", "0", "0", "0"])
    captured = capsys.readouterr()
    assert "float division by zero" in captured.out
    assert result == 84
