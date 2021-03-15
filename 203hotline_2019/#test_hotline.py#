#!/usr/bin/env python3

import pytest
import imp
hotline = imp.load_source('203hotline', './203hotline')

def test_helper(capsys):
    hotline.compute_1(["203hotline", "-h"])
    captured = capsys.readouterr()
    assert "USAGE\n\t./203hotline [n k | d]\n\nDESCRIPTION\nn\tn value for the computation of C(n, k)\nk\tk value for the computation of C(n, k)\nd\taverage duration of calls (in seconds)" in captured.out

def test_180(capsys):
    result = hotline.compute_1(["203hotline", "180"])
    captured = capsys.readouterr()
    assert "Binomial distribution:" in captured.out
    assert result == 0

def test_100_18(capsys):
    result = hotline.compute_2(["203hotline", "100", "18"])
    captured = capsys.readouterr()
    assert "18-combinations of a set of size 100:" in captured.out
    assert "30664510802988208300" in captured.out
    assert result == 0

def test_100_neg(capsys):
    result = hotline.compute_2(["203hotline", "100", "-1"])
    captured = capsys.readouterr()
    assert "Args have to be ints" in captured.out
    assert result == 84

def test_100_0(capsys):
    result = hotline.compute_2(["203hotline", "100", "0"])
    captured = capsys.readouterr()
    assert "0-combinations of a set of size 100:" in captured.out
    assert "1" in captured.out
    assert result == 0

def test_100_30(capsys):
    result = hotline.compute_2(["203hotline", "100", "30"])
    captured = capsys.readouterr()
    assert "30-combinations of a set of size 100:" in captured.out
    assert "29372339821610944823963760" in captured.out
    assert result == 0

def test_200_30(capsys):
    result = hotline.compute_2(["203hotline", "200", "30"])
    captured = capsys.readouterr()
    assert "30-combinations of a set of size 200:" in captured.out
    assert "409681705022127773530866523638950880" in captured.out
    assert result == 0

def test_neg(capsys):
    result = hotline.compute_1(["203hotline", "-20"])
    captured = capsys.readouterr()
    assert "Args have to be ints" in captured.out
    assert result == 84

def test_0(capsys):
    result = hotline.compute_1(["203hotline", "0"])
    captured = capsys.readouterr()
    assert "Binomial distribution:\n0 -> 1.000	1 -> 0.000	2 -> 0.000	3 -> 0.000	4 -> 0.000\n5 -> 0.000	6 -> 0.000	7 -> 0.000	8 -> 0.000	9 -> 0.000\n10 -> 0.000	11 -> 0.000	12 -> 0.000	13 -> 0.000	14 -> 0.000\n15 -> 0.000	16 -> 0.000	17 -> 0.000	18 -> 0.000	19 -> 0.000\n20 -> 0.000	21 -> 0.000	22 -> 0.000	23 -> 0.000	24 -> 0.000\n25 -> 0.000	26 -> 0.000	27 -> 0.000	28 -> 0.000	29 -> 0.000\n30 -> 0.000	31 -> 0.000	32 -> 0.000	33 -> 0.000	34 -> 0.000\n35 -> 0.000	36 -> 0.000	37 -> 0.000	38 -> 0.000	39 -> 0.000\n40 -> 0.000	41 -> 0.000	42 -> 0.000	43 -> 0.000	44 -> 0.000\n45 -> 0.000	46 -> 0.000	47 -> 0.000	48 -> 0.000	49 -> 0.000\n50 -> 0.000\nOverload: 0.0" in captured.out
    assert result == 0

def test_2000(capsys):
    result = hotline.compute_1(["203hotline", "2000"])
    captured = capsys.readouterr()
    assert "Binomial distribution:\n0 -> 0.000	1 -> 0.000	2 -> 0.000	3 -> 0.000	4 -> 0.000\n5 -> 0.000	6 -> 0.000	7 -> 0.000	8 -> 0.000	9 -> 0.000\n10 -> 0.000	11 -> 0.000	12 -> 0.000	13 -> 0.000	14 -> 0.000\n15 -> 0.000	16 -> 0.000	17 -> 0.000	18 -> 0.000	19 -> 0.000\n20 -> 0.000	21 -> 0.000	22 -> 0.000	23 -> 0.000	24 -> 0.000\n25 -> 0.000	26 -> 0.000	27 -> 0.000	28 -> 0.000	29 -> 0.000\n30 -> 0.000	31 -> 0.000	32 -> 0.000	33 -> 0.000	34 -> 0.000\n35 -> 0.000	36 -> 0.000	37 -> 0.000	38 -> 0.000	39 -> 0.000\n40 -> 0.000	41 -> 0.000	42 -> 0.000	43 -> 0.000	44 -> 0.000\n45 -> 0.000	46 -> 0.000	47 -> 0.000	48 -> 0.000	49 -> 0.000\n50 -> 0.000\nOverload: 0.0" in captured.out
    assert result == 0

def test_50(capsys):
    result = hotline.compute_1(["203hotline", "50"])
    captured = capsys.readouterr()
    assert "Binomial distribution:\n0 -> 0.002	1 -> 0.014	2 -> 0.042	3 -> 0.086	4 -> 0.130\n5 -> 0.159	6 -> 0.161	7 -> 0.139	8 -> 0.106	9 -> 0.071\n10 -> 0.043	11 -> 0.024	12 -> 0.012	13 -> 0.006	14 -> 0.002\n15 -> 0.001	16 -> 0.000	17 -> 0.000	18 -> 0.000	19 -> 0.000\n20 -> 0.000	21 -> 0.000	22 -> 0.000	23 -> 0.000	24 -> 0.000\n25 -> 0.000	26 -> 0.000	27 -> 0.000	28 -> 0.000	29 -> 0.000\n30 -> 0.000	31 -> 0.000	32 -> 0.000	33 -> 0.000	34 -> 0.000\n35 -> 0.000	36 -> 0.000	37 -> 0.000	38 -> 0.000	39 -> 0.000\n40 -> 0.000	41 -> 0.000	42 -> 0.000	43 -> 0.000	44 -> 0.000\n45 -> 0.000	46 -> 0.000	47 -> 0.000	48 -> 0.000	49 -> 0.000\n50 -> 0.000\nOverload: 0.0" in captured.out
    assert result == 0

def test_42(capsys):
    result = hotline.compute_1(["203hotline", "42"])
    captured = capsys.readouterr()
    assert "Poisson distribution:\n0 -> 0.006	1 -> 0.031	2 -> 0.079	3 -> 0.135	4 -> 0.172\n5 -> 0.175	6 -> 0.149	7 -> 0.109	8 -> 0.069	9 -> 0.039\n10 -> 0.020	11 -> 0.009	12 -> 0.004	13 -> 0.002	14 -> 0.001\n15 -> 0.000	16 -> 0.000	17 -> 0.000	18 -> 0.000	19 -> 0.000\n20 -> 0.000	21 -> 0.000	22 -> 0.000	23 -> 0.000	24 -> 0.000\n25 -> 0.000	26 -> 0.000	27 -> 0.000	28 -> 0.000	29 -> 0.000\n30 -> 0.000	31 -> 0.000	32 -> 0.000	33 -> 0.000	34 -> 0.000\n35 -> 0.000	36 -> 0.000	37 -> 0.000	38 -> 0.000	39 -> 0.000\n40 -> 0.000	41 -> 0.000	42 -> 0.000	43 -> 0.000	44 -> 0.000\n45 -> 0.000	46 -> 0.000	47 -> 0.000	48 -> 0.000	49 -> 0.000\n50 -> 0.000" in captured.out
    assert result == 0

def test_42_2(capsys):
    result = hotline.compute_2(["203hotline", "42", "2"])
    captured = capsys.readouterr()
    assert "2-combinations of a set of size 42:" in captured.out
    assert "861" in captured.out
    assert result == 0

def test_66_6(capsys):
    result = hotline.compute_2(["203hotline", "66", "6"])
    captured = capsys.readouterr()
    assert "6-combinations of a set of size 66:" in captured.out
    assert "90858768" in captured.out
    assert result == 0

def test_6_6(capsys):
    result = hotline.compute_2(["203hotline", "6", "6"])
    captured = capsys.readouterr()
    assert "6-combinations of a set of size 6:" in captured.out
    assert "1" in captured.out
    assert result == 0

def test_145_1(capsys):
    result = hotline.compute_2(["203hotline", "145", "1"])
    captured = capsys.readouterr()
    assert "1-combinations of a set of size 145:" in captured.out
    assert "145" in captured.out
    assert result == 0