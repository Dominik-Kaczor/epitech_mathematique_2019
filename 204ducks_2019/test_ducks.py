#!/usr/bin/env python3                                                          
import pytest
import imp
import os
ducks = imp.load_source('204ducks', './204ducks')

def test_helper(capsys):
    ducks.main(["204ducks", "-h"])
    captured = capsys.readouterr()
    assert "USAGE\n\t./204ducks a\n\nDESCRIPTION\n\ta\tconstant"

def test_bad_argument_1(capsys):
    result = ducks.main(["204ducks"])
    captured = capsys.readouterr()
    assert "Error Bad argument 0 <= a <= 2.5" in captured.out
    assert result == 84

def test_bad_argument_2(capsys):
    result = ducks.main(["204ducks", "bad"])
    captured = capsys.readouterr()
    assert "Error Bad argument 0 <= a <= 2.5" in captured.out
    assert result == 84

def test_bad_argument_3(capsys):
    result = ducks.main(["204ducks", "1", "3"])
    captured = capsys.readouterr()
    assert "Error Bad argument 0 <= a <= 2.5" in captured.out
    assert result == 84

def test_bad_argument_4(capsys):
    result = ducks.main(["204ducks", "-1"])
    captured = capsys.readouterr()
    assert "Error Bad argument 0 <= a <= 2.5" in captured.out
    assert result == 84

def test_bad_argument_5(capsys):
    result = ducks.main(["204ducks", "7"])
    captured = capsys.readouterr()
    assert "Error Bad argument 0 <= a <= 2.5" in captured.out
    assert result == 84

def test_0_2(capsys):
    result = ducks.main(["204ducks", "0.2"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_0_2.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_0(capsys):
    result = ducks.main(["204ducks", "0"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_0.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_2_5(capsys):
    result = ducks.main(["204ducks", "2.5"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_2_5.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_1_6(capsys):
    result = ducks.main(["204ducks", "1.6"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_1_6.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_1(capsys):
    result = ducks.main(["204ducks", "1"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_1.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_2(capsys):
    result = ducks.main(["204ducks", "2"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_2.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0

def test_2_333(capsys):
    result = ducks.main(["204ducks", "2.333"])
    captured = capsys.readouterr()
    mon_fichier = open("ex/ex_2_333.txt", "r")
    contenu = mon_fichier.read()
    mon_fichier.close()
    assert contenu in captured.out
    assert result == 0
