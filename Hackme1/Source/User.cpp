// User.cpp

#include "User.h"

User::User(std::string username, std::string password, std::string biography, int age, int maxRandomUsernameLength, int maxRandomPasswordLength) :
	m_randomUsernameMaxLength{ maxRandomUsernameLength },
	m_randomPasswordMaxLength{ maxRandomPasswordLength },
	m_username{ username.empty() ? Generator::GenerateRandomString(maxRandomUsernameLength) : std::move(username) },
	m_password{ password.empty() ? Generator::GenerateRandomString(maxRandomPasswordLength) : std::move(password) },
	m_biography{ std::move(biography) },
	m_age{ std::move(age) }

{}

int User::SetUsername(std::string username)
{
	assert(username.length() > 0 && "username parameter must not be empty");
	m_username = username;

	return 0;
}

int User::SetPassword(std::string password)
{
	assert(password.length() > 0 && "password parameter must not be empty");
	m_password = password;

	return 0;
}

int User::SetBiography(std::string biography)
{
	m_biography = biography;

	return 0;
}

int User::SetAge(int age)
{
	assert(age > 0 && "Age must be greater than 0");
	m_age = age;

	return 0;
}

std::string User::GetUsername()
{
	return m_username;
}

std::string User::GetPassword()
{
	return m_password;
}

std::string User::GetBiography()
{
	return m_biography;
}

int User::GetAge()
{
	return m_age;
}

void User::Introduction()
{
	std::cout << "Hello i am: " << m_username << ", im " << m_age << ", nice meeting you\n";
}
