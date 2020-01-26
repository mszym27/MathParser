#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void S();
void Z();
void W();
void WPrime();
void P();
void R();
void RPrime();
void L();
void LPrime();
void C();
void O();

const char END_SYMBOL = '#';

string input;

int head = 0;

char currentSymbol;

struct ParserInvalidInputException : exception { };

void match(char symbol)
{
	if (currentSymbol == symbol)
	{
		currentSymbol = input[++head];
	}
	else
	{
		throw new ParserInvalidInputException();
	}
}

void init()
{
	input = input + END_SYMBOL; // dodanie sztucznego symbolu kończącego

	currentSymbol = input[head];
}

int main()
{
	//input = "(1.2*3)+5-(23.4+3)^3; 8:13;";

	input = "2";

	init();

	try {
		S();
	}
	catch (ParserInvalidInputException) {
		std::cout << "Invalid character: " << currentSymbol << std::endl;
	}

	getchar();

    return 0;
}


void S()
{
	std::cout << currentSymbol << " : S" << std::endl;

	W();

	match(';');
	
	Z();
}

void Z()
{
	std::cout << currentSymbol << " : Z" << std::endl;

	if (currentSymbol == END_SYMBOL)
	{
		/* do nothing */
	}
	else
	{
		W();

		match(';');

		Z();
	}
}

void W()
{
	std::cout << currentSymbol << " : W" << std::endl;

	P();

	WPrime();
}

void WPrime()
{
	std::cout << currentSymbol << " : WPrime" << std::endl;

	if (currentSymbol == END_SYMBOL)
	{
		/* do nothing */
	}
	else
	{
		O();

		W();
	}
}

void P()
{
	std::cout << currentSymbol << " : P" << std::endl;

	if (currentSymbol == '(')
	{
		match('(');

		W();

		match(')');
	}
	else
	{
		R();
	}
}

void R()
{
	std::cout << currentSymbol << " : R" << std::endl;

	L();

	RPrime();
}

void RPrime()
{
	std::cout << currentSymbol << " : RPrime" << std::endl;

	if (currentSymbol == END_SYMBOL)
	{
		/* do nothing */
	}
	else
	{
		match('.');

		L();
	}
}

void L()
{
	std::cout << currentSymbol << " : L" << std::endl;

	C();

	LPrime();
}

void LPrime()
{
	std::cout << currentSymbol << " : LPrime" << std::endl;

	if (currentSymbol == END_SYMBOL)
	{
		/* do nothing */
	}
	else
	{
		L();
	}
}

void C()
{
	std::cout << currentSymbol << " : C" << std::endl;

	if (currentSymbol == '0')
		match('0');
	else if (currentSymbol == '1')
		match('1');
	else if (currentSymbol == '2')
		match('2');
	else if (currentSymbol == '3')
		match('3');
	else if (currentSymbol == '4')
		match('4');
	else if (currentSymbol == '5')
		match('5');
	else if (currentSymbol == '6')
		match('6');
	else if (currentSymbol == '7')
		match('7');
	else if (currentSymbol == '8')
		match('8');
	else if (currentSymbol == '9')
		match('9');
}

void O()
{
	std::cout << currentSymbol << " : O" << std::endl;

	if (currentSymbol == '*')
		match('*');
	else if (currentSymbol == ':')
		match(':');
	else if (currentSymbol == '+')
		match('+');
	else if (currentSymbol == '-')
		match('-');
	else if (currentSymbol == '^')
		match('^');
}