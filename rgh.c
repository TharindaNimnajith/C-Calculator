/*  Project	     : A Basic Calculator using C Programming Language
	Author       : Tharinda Nimnajith Rajapakshe
	Date Started : 25.10.2018
	Last Updated : 26.11.2018  						                 */

#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

// #define _USE_MATH_DEFINES
// #define PI 3.1415926535898
// #define PI acos(-1.0)
// #define PI 4.0 * atan(1.0)
// #define PI 2.0 * asin(1.0)
// #define E 2.7182818284590

FILE *cfPtr;
double answer, intPart, fracPart;
int ans;

void display() {
	printf("\n\n \t\t\t\t C Calculator! \n\n");
	printf("\n This is a basic calculator that is built using the C programming language! \n");
	printf("\n You can choose a theme for the calculator interface from the below list: \n");
	printf("\n\t Theme Index \t Text Colour \t   Background Colour \n");

	/*  		 Colour Codes:-

		0 = Black			8 = Gray
	    1 = Blue			9 = Light Blue
	    2 = Green			A = Light Green
	    3 = Aqua			B = Light Aqua
	    4 = Red 			C = Light Red
	    5 = Purple 		    D = Light Purple
	    6 = Yellow			E = Light Yellow
	    7 = White			F = Bright White  	 */

	printf("\n\t 0 <Default> \t    White \t\t Black \n");
	printf("\t    1 \t\t    Black \t\t White \n");
	printf("\t    2 \t\t    Red \t\t White \n");
	printf("\t    3 \t\t    Green \t\t White \n");
	printf("\t    4 \t\t    Blue \t\t White \n");
	printf("\t    5 \t\t    Light Green \t Black \n");
	printf("\t    6 \t\t    Light Blue \t\t Black \n");
	printf("\t    7 \t\t    Purple \t\t White \n");
	printf("\t    8 \t\t    Bright White \t Black \n");
	printf("\t    9 \t\t    Black \t\t Bright White \n");

	printf("\n Enter the index number of your preferred theme: ");
}

void colour(int c) {
	switch(c) {
		case 1 : system("COLOR 70"); break;
		case 2 : system("COLOR 74"); break;
		case 3 : system("COLOR 72"); break;
		case 4 : system("COLOR 71"); break;
		case 5 : system("COLOR 0A"); break;
		case 6 : system("COLOR 09"); break;
		case 7 : system("COLOR 75"); break;
		case 8 : system("COLOR 0F"); break;
		case 9 : system("COLOR F0"); break;
		default: system("COLOR 07");
	}
}

void displayOperators() {
	printf("\n\n Operators: \n" );
	printf("\n +  => Addition \n");
	printf(" -  => Subtraction \n");
	printf(" *  => Multiplication \n");
	printf(" /  => Division \n");
	printf(" %%  => Modulo/Modulus (for Integers only) \n");
	printf(" &  => Absolute value of Remainder (Integer & Fraction parts seperately) \n");
	printf(" ^  => Power \n");
	printf(" #  => Square \n");
	printf(" $  => Cube \n");
	printf(" ~  => Square Root \n");
	printf(" ?  => Cube Root \n");
	printf(" !  => Factorial \n");
	printf(" :  => 10^x \n");
	printf(" ;  => 2^x \n");
	printf(" X   => x^x \n");
	printf(" m  => Absolute value of integers \n");
	printf(" M  => Absolute value of floating point numbers \n");
	printf(" <  => Floor (The highest integer value lower than x) \n");
	printf(" >  => Ceil (The lowest integer value higher than x) \n");
	printf(" =  => Round \n");
	printf(" .  => Percentage \n");
	printf(" ,  => PI value \n");
	printf(" E  => e value \n");
	printf(" \\  => 1/x \n");
	printf(" L  => Natural Logarithm (base-e logarithm -> ln x) \n");
	printf(" l  => Common Logarithm (base-10 logarithm -> lg x) \n");
	printf(" e  => Exponential (e^x) \n");
	printf(" c  => Cosine (cos x) \n");
	printf(" s  => Sine (sin x) \n");
	printf(" t  => Tangent (tan x) \n");
	printf(" S  => Secant (sec x) \n");
	printf(" C  => Cosecant (cosec x) \n");
	printf(" T  => Cotangent (cot x) \n");
	printf(" _  => asin (sin inverse) \n");
	printf(" |  => acos (cos inverse) \n");
	printf(" (  => atan (tan inverse) \n");
	printf(" )  => sinh \n");
	printf(" [  => cosh \n");
	printf(" ]  => tanh \n");
	printf(" {  => sinh inverse \n");
	printf(" }  => cosh inverse \n");
	printf(" `  => tanh inverse \n");
	printf(" @  => y root of x \n");
	printf(" n  => Convert to scientific notation \n")
	printf(" x  => Conversion between different number systems \n");

	printf("\n Enter which type of operation you want to perform from the above list: ");
}

double addition(double x, double y) {
    answer = x + y;
	return answer;
}

double subtraction(double x, double y) {
    answer = x - y;
    return answer;
}

double multiplication(double x, double y) {
    answer = x * y;
    return answer;
}

double division(double x, double y) {
    answer = x / y;
    return answer;
}

int modulo(int x, int y) {
    ans = x % y;
    return ans;
}

double remainder(double x, double y) {
	intPart = 0, fracPart = 0;
	answer = fabs(fmod(x, y));
	fracPart = modf(answer, &intPart);
	return answer;
}

double power(double x, double y) {
    answer = pow(x, y);
    return answer;
}

double square(double x) {
	answer = pow(x, 2);
	return answer;
}

double cube(double x) {
	answer = pow(x, 3);
	return answer;
}

double squareRoot(double x) {
	answer = sqrt(x);
	return answer;
}

double cubeRoot(double x) {
	answer = cbrt(x);
	return answer;
}

int factorial(int x) {
	if(x <= 1)
		ans = 1;
	else
		ans = x * factorial(x - 1);

	return ans;
}

void testAddition() {
	assert(addition(20.14, -4.04) == 16.1);
	assert(addition(-20.14, 4.04) == -16.1);
	assert(addition(-20.14, -4.04) == -24.18);
	assert(addition(20.14, 4.04) == 24.18);

	printf(" All addition unit test cases passed! \n");
}

void testSubtraction() {
	assert(subtraction(20.14, 4.04) == 16.1);
	assert(subtraction(-20.14, 4.04) == -24.18);
	assert(subtraction(20.14, -4.04) == 24.18);
	assert(subtraction(-20.14, -4.04) == -16.1);

	printf(" All subtraction unit test cases passed! \n");
}

void testMultiplication() {
	assert(multiplication(20.14, -4.04) == -81.3656);
	assert(multiplication(20.14, 1) == 20.14);
	assert(multiplication(20.14, 0) == 0);
	assert(multiplication(-20.14, -4.04) == 81.3656);

	printf(" All multiplication unit test cases passed! \n");
}

void testDivision() {
	assert(division(22.2, -1.2) == -18.5);
	assert(division(-22.2, -1.2) == 18.5);
	assert(division(0, -1.2) == 0);
	assert(division(2.31, 1) == 2.31);

	printf(" All division unit test cases passed! \n");
}

void testModulo() {
	assert(modulo(20, 5) == 0);
	assert(modulo(24, 7) == 3);
	assert(modulo(0, 7) == 0);
	assert(modulo(7, 8) == 7);

	printf(" All modulo unit test cases passed! \n");
}

void testRemainder() {
	assert(remainder(20, 5) == 0);
	assert(remainder(24, 7) == 3);
	assert(remainder(0, -7.12) == 0);
	//assert(remainder(3.4, 3) == 0.4);
	//assert(remainder(3.4, 4) == 3.4);
	//assert(remainder(-8.2, 5.7) == 2.5);
	//assert(remainder(8.2, -5.7) == 2.5);
	//assert(remainder(-8.2, -5.7) == 2.5);

	printf(" All remainder unit test cases passed! \n");
}

void testPower() {
	assert(power(1.5, 5) == 7.59375);
	assert(power(10, -1) == 0.1);
	assert(power(-10, -1) == -0.1);
	assert(power(-10, 5) == -100000);
	assert(power(10, 0) == 1);

	printf(" All power unit test cases passed! \n");
}

void testSquare() {
	assert(square(1.234) == 1.522756);
	assert(square(-1.234) == 1.522756);
	assert(square(0) == 0);
	//assert(square(2.35) == 5.5225);
	//assert(square(-2.35) == 5.5225);

	printf(" All square unit test cases passed! \n");
}

void testCube() {
	assert(cube(8.76) == 672.221376);
	assert(cube(-8.76) == -672.221376);
	assert(cube(0) == 0);
	//assert(cube(2.35) == 12.977875);
	//assert(cube(-2.35) == -12.977875);

	printf(" All cube unit test cases passed! \n");
}

void testSquareRoot() {
	assert(squareRoot(5.29) == 2.3);
	assert(squareRoot(0) == 0);

	printf(" All squareRoot unit test cases passed! \n");
}

void testCubeRoot() {
	assert(cubeRoot(12.977875) == 2.35);
	assert(cubeRoot(-12.977875) == -2.35);
	assert(cubeRoot(0) == 0);

	printf(" All cubeRoot unit test cases passed! \n");
}

void testFactorial() {
	assert(factorial(5) == 120);
	assert(factorial(0) == 1);
	assert(factorial(1) == 1);

	printf(" All factorial unit test cases passed! \n");
}

void tests() {
	testAddition();
	testSubtraction();
	testMultiplication();
	testDivision();
	testModulo();
	testRemainder();
	testPower();
	testSquare();
	testCube();
	testSquareRoot();
	testCubeRoot();
	testFactorial();

	printf("\n All unit test cases passed! \n\n\n");
}

void calculation(char ch, double a, double b, int c, int d) {
	switch(ch) {
		case '+': printf("\n %.15g %c %.15g = %.15g \n", a, ch, b, addition(a, b)); break;
		case '-': printf("\n %.15g %c %.15g = %.15g \n", a, ch, b, subtraction(a, b)); break;
		case '*': printf("\n %.15g x %.15g = %.15g \n", a, b, multiplication(a, b)); break;
		case '/': printf("\n %.15g %c %.15g = %.15g \n", a, ch, b, division(a, b)); break;
		case '%': printf("\n %d %c %d = %d \n", c, ch, d, modulo(c, d)); break;
		case '^': printf("\n %.15g %c %.15g = %.15g \n", a, ch, b, power(a, b)); break;
		case '#': printf("\n %.15g ^ 2 = %.15g \n", a, square(a)); break;
		case '$': printf("\n %.15g ^ 3 = %.15g \n", a, cube(a)); break;
		case '~': printf("\n Square Root of %.15g = %.15g \n", a, squareRoot(a)); break;
		case '?': printf("\n Cube Root of %.15g = %.15g \n", a, cubeRoot(a)); break;
		case '!': printf("\n %d%c = %d \n", c, ch, factorial(c)); break;
		case '&': printf("\n %.15g %% %.15g = %.15g \n", a, b, remainder(a, b));
				  printf("\n The Integral part: %.15g", intPart);
				  printf("\n The Fraction part: %.15g \n", fracPart);
	}
}

void file(char ch, double a, double b, int c, int d) {
	switch(ch) {
		case '-': case '/': case '^': case '+': case '*': fprintf(cfPtr, "%f %c %f = %f \n", a, ch, b, answer); break;
		case '%': fprintf(cfPtr, "%d %c %d = %d \n", c, ch, d, ans); break;
		case '#': fprintf(cfPtr, "%f ^ %d = %f \n", a, 2, answer); break;
		case '$': fprintf(cfPtr, "%f ^ %d = %f \n", a, 3, answer); break;
		case '~': fprintf(cfPtr, "Square Root of %f = %f \n", a, answer); break;
		case '?': fprintf(cfPtr, "Cube Root of %f = %f \n", a, answer); break;
		case '!': fprintf(cfPtr, "%d%c = %d \n", c, ch, ans); break;
		case '&': fprintf(cfPtr, "%f %% %f = %f \n", a, b, answer);
	}
}

void clrscr() {
	system("@cls||clear");
}

void prompt() {
	printf("\n\n To do another calculation using the answer of the previous calculation, press 'Z' ");
	printf("\n To do a different calculation, press 'Y' ");
	printf("\n Press any other key to exit: ");
}

void error() {
	printf("\n Invalid operator!");
	printf("\n Press 'Y' to try again, Press any other key to exit: ");
}

int main() {
	int color;
    char again;
    clrscr();

    cfPtr = fopen("calculator.dat", "a+");
    if(cfPtr == NULL) {
        printf("\n\n ERROR: File cannot be opened! \n");
        exit(1);
    }

    printf("\n File creation successful! \n\n\n");
    tests();
    system("pause");
    clrscr();

    display();
	scanf("%d", &color);
	colour(color);
	clrscr();

	do {
		double n1 = 0, n2 = 0;
		int no1 = 0, no2 = 0;
		char symbol;

		label_1:
		displayOperators();
		scanf(" %c", &symbol);

		switch(symbol) {
			case '-': case '^': case '+': case '*':
				printf("\n Enter the first number : ");
				scanf("%lf", &n1);
				printf(" Enter the second number: ");
				scanf("%lf", &n2);
				break;

			case '/': case '&':
				printf("\n Enter the dividend: ");
				scanf("%lf", &n1);
				printf(" Enter the divisor : ");
				scanf("%lf", &n2);
				while(n2 == 0) {
					printf("\n Invalid input! You can't divide with 0. Please try again... \n");
					printf("\n Enter the divisor again: ");
					scanf("%lf", &n2);
				}
				break;

			case '%':
				printf("\n Enter a positive integer (dividend): ");
				scanf("%d", &no1);
				while(no1 < 0) {
					printf("\n Invalid input! Please try again... \n");
					printf("\n Enter a positive integer (dividend): ");
					scanf("%d", &no1);
				}
				printf(" Enter a positive integer (divisor) : ");
				scanf("%d", &no2);
				while(no2 <= 0) {
					if (no2 == 0)
						printf("\n Invalid input! You can't divide with 0. Please try again... \n");
					else
						printf("\n Invalid input! Please try again... \n");

					printf("\n Enter a positive integer (divisor) : ");
					scanf("%d", &no2);
				}
				break;

			case '#': case '$': case '?':
				printf("\n Enter the number: ");
				scanf("%lf", &n1);
				break;

			case '~':
				printf("\n Enter a non negative number: ");
				scanf("%lf", &n1);
				while(n1 < 0) {
					printf("\n Invalid input! Please try again... \n");
					printf("\n Enter a non negative number: ");
					scanf("%lf", &n1);
				}
				break;

			case '!':
				printf("\n Enter a non negative integer: ");
				scanf("%d", &no1);
				while(no1 < 0) {
					printf("\n Invalid input! Please try again... \n");
					printf("\n Enter a non negative integer: ");
					scanf("%d", &no1);
				}
				break;

			default:
				error();
				scanf(" %c", &again);
				clrscr();
				if(again == 'Y' || again == 'y')
					goto label_1;
				else
					goto label_2;
		}

		answer = 0, ans = 0;
		calculation(symbol, n1, n2, no1, no2);
		file(symbol, n1, n2, no1, no2);

		prompt();
		scanf(" %c", &again);

		while(again == 'z' || again == 'Z') {
			double n1 = 0, n2 = 0;
			int no1 = 0, no2 = 0;

			label_3:
			displayOperators();
			scanf(" %c", &symbol);

			switch(symbol) {
				case '-': case '^': case '+': case '*':
					printf("\n Enter the number : ");
					scanf("%lf", &n1);
					break;

				case '/': case '&':
					printf(" Enter the divisor : ");
					scanf("%lf", &n2);
					while(n2 == 0) {
						printf("\n Invalid input! You can't divide with 0. Please try again... \n");
						printf("\n Enter the divisor again: ");
						scanf("%lf", &n2);
					}
					break;

				case '%':
					printf(" Enter a positive integer (divisor) : ");
					scanf("%d", &no2);
					while(no2 <= 0) {
						if (no2 == 0)
							printf("\n Invalid input! You can't divide with 0. Please try again... \n");
						else
							printf("\n Invalid input! Please try again... \n");

						printf("\n Enter a positive integer (divisor) : ");
						scanf("%d", &no2);
					}
					break;

				default:
					error();
					scanf(" %c", &again);
					clrscr();
					if(again == 'Y' || again == 'y')
						goto label_3;
					else
						goto label_2;
			}

			// Do the calculation
			// Write to the file

			prompt();
			scanf(" %c", &again);
		}

		clrscr();
	} while(again == 'Y' || again == 'y');

	label_2:
	system("COLOR 07");
	fclose(cfPtr);
	return 0;
}