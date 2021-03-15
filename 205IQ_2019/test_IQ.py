#!/usr/bin/env python3

import pytest
import imp
import os
iq = imp.load_source('205IQ', './205IQ')

def test_helper(capsys):
    iq.main(["205IQ", "-h"])
    captured = capsys.readouterr()
    assert "USAGE\n\t./205IQ u q [IQ1] [IQ2] \n\nDESCRIPTION\n\tu\tmean\n\ts\tstandard deviation\n\tIQ1\tminimum IQ\n\tIQ2\tmaximum IQ" in captured.out

def test_bad_argument_1(capsys):
    result = iq.main(["205IQ", "-1"])
    assert result == 84

def test_bad_argument_2(capsys):
    result = iq.main(["205IQ", "-1", "-1"])
    assert result == 84

def test_bad_argument_3(capsys):
    result = iq.main(["205IQ", "10", "10", "dom"])
    assert result == 84

def test_bad_argument_4(capsys):
    result = iq.main(["205IQ", "10", "0", "10"])
    captured = capsys.readouterr()
    assert "float division by zero" in captured.out
    assert result == 84

def test_bad_argument_5(capsys):
    result = iq.main(["205IQ", "10", "10","10", "10", "10", "10"])
    assert result == 84

def test_argument_2_1(capsys):
    result = iq.main(["205IQ", "60", "1120"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_1.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_argument_2_2(capsys):
    result = iq.main(["205IQ", "1", "2"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_2.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_argument_3_1(capsys):
    result = iq.main(["205IQ", "3", "2", "43"])
    captured = capsys.readouterr()
    assert "93.4% of people have an IQ inferior to 43" in captured.out
    assert result == 0

def test_argument_3_2(capsys):
    result = iq.main(["205IQ", "131", "13", "13"])
    captured = capsys.readouterr()
    assert "0.0% of people have an IQ inferior to 13" in captured.out
    assert result == 0

def argument_3_3(capsys):
    result = iq.main(["205IQ", "1", "2", "3"])
    captured = capsys.readouterr()
    assert "53.4% of people have an IQ inferior to 3" in captured.out
    assert result == 0

def test_argument_4(capsys):
    result = iq.main(["205IQ", "10", "10", "10", "10"])
    captured = capsys.readouterr()
    assert "0.0% of people have an IQ between 10 and 10" in captured.out
    assert result == 0
