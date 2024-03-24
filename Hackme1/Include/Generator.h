#pragma once
#include "smath.h"

#include <iostream>
#include <string>
#include <random>

namespace Generator
{
	// Generates a random number from 1 to 99 by default
	int GenerateRandomNumber(int from = 1, int to = 99);

	// Generate a random sequence of numbers
	int GenerateRandomNumberSequence(short maxLength, int from, int to);

	std::string GenerateRandomString(short maxLength);

	// "Generate" fake user biography
	std::string GenerateBiography();
};

