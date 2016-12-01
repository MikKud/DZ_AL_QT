#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <gmpxx.h>
#include <gmp.h>
#include <stdio.h>
using namespace std;

extern vector<vector<pair<mpz_class,mpz_class>>> tasks;

void Factor(mpz_class);
