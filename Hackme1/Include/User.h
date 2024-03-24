#pragma once
#include "Generator.h"

#include <iostream>
#include <string>
#include <cassert>

class User
{
private:
	int m_randomUsernameMaxLength{};
	int m_randomPasswordMaxLength{};

	std::string m_username{};
	std::string m_password{};
	std::string m_biography{};
	int m_age{};


public:
	User(std::string username = "",
		std::string password = "",
		std::string biography = Generator::GenerateBiography(),
		int age = Generator::GenerateRandomNumber(18, 99),
		int randomUsernameMaxLength = 12,
		int randomPasswordMaxLength = 8);

	int SetUsername(std::string username);
	int SetPassword(std::string password);
	int SetBiography(std::string biography);
	int SetAge(int age);

	std::string GetUsername();
	std::string GetPassword();
	std::string GetBiography();

	int GetAge();

	void Introduction();
};

