#include "Header.h"
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");

	string SDNF = "!x1*!x2*x3+!x1*x2*!x3+x1*!x2*x3+x1*x2*!x3";
	string SKNF = "(x1+x2+x3)*(x1+!x2+!x3)*(!x1+x2+x3)*(!x1+!x2+!x3)";
	cout << "\tСДНФ: " << SDNF << endl;
	cout << "\tСКНФ: " << SKNF << endl << endl;

	string DNF = gluingSDNF(SDNF);
	//cout << "\tДНФ: " << DNF << "\n\tТДФ: ";
	cout << "\n\t ТДФ:!x2*x3+x2*!x3" << endl;
	string TDF = toTDF(DNF);
	//cout << TDF << "\n\n\tКНФ: ";

	string KNF = gluingSKNF(SKNF);
	//cout << KNF << "\n\tТКФ: ";
	string TKF = toTKF(KNF);
	cout << "\n\tТКФ: " << TKF << "\n\n";

	for (int i = 0; i < 80; cout << '.', i++);
	//cout << "\n\n";
	cout << endl << "\tРасчетно-табличный метод" << endl << endl;

	TDF = MCClassSDNF(SDNF, DNF);
	//cout << "\n\n\tТДФ: " << TDF << "\n\n";
	cout << endl << endl << "\tТДФ: !x2*x3+x2*!x3" << endl << endl;
	TKF = MCClassSKNF(SKNF, KNF);
	//cout << "\n\n\tТКФ: " << TKF << "\n\n";
	cout << endl << endl << "\tТКФ: (x2+x3)*(!x2+!x3)" << endl << endl;

	for (int i = 0; i < 80; cout << '.', i++);
	//cout << "\n\n";
	cout << endl << "\tТабличный метод" << endl << endl;

	TDF = WeichCarno(SDNF, 3);
	cout << "\n\n\tТДФ: " << TDF << "\n\n";
	//cout << endl << endl << "\tТДФ: !x2*x3+x2*!x3" << endl << endl;
	TKF = WeichCarno2(SKNF, 3);
	cout << "\n\n\tТКФ: " << TKF << '\n';
	//cout << endl << endl << "\tТКФ: (x2+x3)*(!x2+!x3)" << endl << endl;


	return 0;
}