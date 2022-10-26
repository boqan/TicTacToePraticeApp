#include <iostream>
#include <string.h>
#include <vector>


std::vector<std::vector<char>> matrix = { {'1' , '2', '3'}, 
										  {'4', '5', '6'}, 
										  {'7', '8', '9'} };
char player = 'X';

void Draw()
{
	std::cout << "Tic Tac Toe v1.0" << std::endl;
	for (int i = 0; i < 3; i++) 
	{	// these 2 for cycles print the matrix // basic I and J iteration
		for (int j = 0; j < 3; j++) 
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl; // this cout is here so it prints it out like a matrix, not a line
	}
}

void Draw2()
{
	system("cls");
	std::cout << "Tic Tac Toe v1.0" << std::endl;
	for (std::vector<char> matrix1D : matrix) 
	{	// these 2 for cycles print the matrix // it uses the iterator of STL instead of I and J
		for (char x : matrix1D) 
		{
			std::cout << x << " ";
		}
		std::cout << std::endl; // this cout is here so it prints it out like a matrix, not a line
	}
}

void Input() 
{
	int input;
	std::cout << "It's " << player << "'s turn. ";
	std::cout << "Press the number of the spot you want to tick: " << std::endl;
	std::cin >> input;
	
	switch (input) {
	case 1:
		if (matrix[0][0] == '1')
			matrix[0][0] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 2:
		if (matrix[0][1] == '2')
			matrix[0][1] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 3:
		if (matrix[0][2] == '3')
			matrix[0][2] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 4:
		if (matrix[1][0] == '4')
			matrix[1][0] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 5:
		if (matrix[1][1] == '5')
			matrix[1][1] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 6:
		if (matrix[1][2] == '6')
			matrix[1][2] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 7:
		if (matrix[2][0] == '7')
			matrix[2][0] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 8:
		if (matrix[2][1] == '8')
			matrix[2][1] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;

	case 9:
		if (matrix[2][2] == '9')
			matrix[2][2] = player;
		else {
			std::cout << "Field is already full, choose another one!" << std::endl;
			Input();
		}
		break;
	}
}

char Win()
{
	char Winner = '/';

	for (int i = 0; i < 3; i++)               // check if rows/columns are equal
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			Winner = matrix[i][0];
		}
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			Winner = matrix[0][i];
		}
	}
	// check the two diagonal win possibilities
	if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) 
		Winner = matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[2][0] == matrix[1][1]) 
		Winner = matrix[0][2];
	return Winner;
}

void TogglePlayer()
{
	if(player == 'X')
		player = 'O';
	else
		player = 'X';
}


int main() {
	int DrawCheck = 0;
	Draw2();
	while(1)
	{
		DrawCheck++;
		Input();
		Draw2();
		if (Win() == 'X') {
			std::cout << "X wins!" << std::endl;
			break;
		}
		if (Win() == 'O') {
			std::cout << "O wins!" << std::endl;
			break;
		}
		else if (Win() == '/' && DrawCheck == 9) {
			std::cout << "It's a draw! Nobody wins." << std::endl;
			break;
		}
		
		TogglePlayer();
		
	}

	return 0;
}