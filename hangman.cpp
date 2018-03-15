#include <iostream>
#include <string>
#include <vector>

using namespace std;

int game(string word)
{
	vector<char> c;
	int lives = 10;
	string display = word;
	for(int i = 0; i < display.length(); i++)
		display[i] = '*';

	while(lives > 0)
	{
		cout << "Previous input: ";
		for (std::vector<char>::const_iterator i = c.begin(); i != c.end(); ++i)
    		std::cout << *i << ' ';
    	std::cout << "\n";
		cout << "Enter a letter in word: ";
		cout << display << " : ";
		char response;
		cin >> response;
		bool duplicate = false;
		bool goodGuess = false;
		for(int i = 0; i < word.length(); i++)
		{
			if(response == display[i])
			{
				duplicate = true;
				break;
			}
			else if(response == word[i]) {
				display[i] = word[i];
				goodGuess = true;
			}
		}
		if(!duplicate)
		{
			c.push_back(response);
		}
		if(duplicate)
		{
			cout << response << " is a duplicate!\n";
		}
		else if (!goodGuess && !duplicate)
		{
			lives--;
			if(lives == 0)
				cout << response << " is not in word.\n";
			else
				cout << response << " is not in word. " << lives << " lives left.\n";
		}

		if(lives == 0)
		{
			std::cout << "You lose!\n";
		}
		if(display == word)
		{
			std::cout << "You win!\nThe word was " << word << ". You had " << lives << " lives left when you won.\n";
			break;
		}
		cout << "\n\n";
	}
	return lives;
}

int main()
{
	game("mudda");
	return 0;
}