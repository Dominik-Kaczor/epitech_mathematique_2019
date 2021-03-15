#!/usr/bin/env python3

import pytest
import imp
yams = imp.load_source('201yams', './201yams')

def test_loi():
    assert yams.loi_bin(1, 1) == 0

def test_pair():
    assert yams.do_pair(1, 2, 3, 4, 5, 2) == 0

def test_three():
    assert yams.do_three(1, 2, 3, 4, 5, 2) == 0

    
