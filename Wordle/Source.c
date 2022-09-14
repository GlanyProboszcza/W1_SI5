#include <stdio.h>
#include <conio.h>
#include <string.h>

void wordle_menu();
void check_letters_possition(char code_word[], char code_word_check[], char good_letters[]);
void display_snake_case(int number_of_letters, char good_letters[]);

void wordle_menu(){
	printf("  ------------------------------- \n");
	printf("|                                 |\n");
	printf("|    Press 1  to Start the game   |\n");
	printf("|                                 |\n");
	printf(" --------------------------------\n\n");
}

void check_letters_possition(char code_word[], char code_word_check[], char good_letters[]) {

	for (int position_in_code_word = 0; position_in_code_word < strlen(code_word); position_in_code_word++) {
		for (int position_in_code_word_check = 0; position_in_code_word_check < strlen(code_word_check); position_in_code_word_check++) {
			if (code_word[position_in_code_word] == code_word_check[position_in_code_word_check]
				&& position_in_code_word == position_in_code_word_check) {
				good_letters[position_in_code_word] = code_word_check[position_in_code_word_check];
			}
			else if (code_word[position_in_code_word] == code_word_check[position_in_code_word_check]) {
				printf("%c\n", code_word[position_in_code_word]);
			}
		}
	}
	display_snake_case(strlen(code_word) - 1, good_letters);
	printf("\n\n");
}

void display_snake_case(int number_of_letters, char good_letters[]) {
	for (int i = 0; i <= number_of_letters; i++) {
		if (good_letters[i] == 0) {
			printf("_ ");
		}
		else {
			printf("%c", good_letters[i]);
		}
	}
}

int main() {
	wordle_menu();

	int character_position = 0, lenght, attempts = 1, lifes = 7, length2;
	char choice, code_word[8], code_word_check[8], ch, good_letters[8] = { 0,0,0,0,0,0,0,0 };

	choice = _getch();

	if (choice == '1')
	{
		system("cls");
		printf("Please enter code-word(max 7 letters): ");

		while (1)
		{
			ch = _getch();
			if (ch == 13)
			{
				break;			//when user press "enter"
			}
			else if (ch == 8)
			{
				character_position--;
				code_word[character_position] = '\0';			//when user press "backspace" its going back by 1 array
				printf("\b \b");
			}
			else if (ch == 32 || ch == 9)
			{
				continue;			//when user press space or tab ignore it
			}
			else
			{
				if (character_position < 7)
				{
					code_word[character_position] = ch;
					character_position++;
					printf("*");
				}
				else
				{
					printf("Your input exceeds maximum code-word lenght.\n");
					break;
				}
			}
		}
		code_word[character_position] = '\0';
		printf("\n");
		if (strlen(code_word) == 0)
		{
			printf("No word entered");
		}
		else
		{
			lenght = strlen(code_word);
			printf("Code-word lenght: %d\n\n", lenght);
		}
		while (lifes > 0)
		{
			printf("Try to guess: ");
			scanf_s("%s", code_word_check, 8);
			if (strcmp(code_word, code_word_check) == 0)
			{
				printf("GAME OVER. YOU WIN. You win in %d attempts\n", attempts);
				return 0;
			}
			else
			{
				check_letters_possition(code_word, code_word_check, good_letters);
				lifes--;
				attempts++;
				printf("Wrong. %d lifes left\n", lifes);
			}
		}
		printf("GAME OVER. YOU LOSE");
	}
	return 0;
}