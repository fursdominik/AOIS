#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

struct Plav {
	vector <bool> mantissa;
	vector <bool> index;
};

const vector <bool> oneM{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
const vector <bool> zero{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
vector <bool> one{ 0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 1 };


void Print(vector <bool> help)
{
	for (int i : help)
	{
		cout << i;
	}
}

vector <bool> changeStraight(int num)
{
	int k, i = 0, j, array[100], number;
	k = num;
	number = num;
	/*if (num < 0)
	{
		num = num * (-1);
	}*/
	i = 0;
	while (num)
	{
		i++;
		num = num / 2;
		j = k - num * 2;
		array[i] = j;
		k = num;
	}


	vector <bool> zapic;
	if (number > 0)
	{
		int m = i;
		while (m != 16)
		{
			zapic.push_back(0);
			m++;
		}
	}
	else
	{
		int n = i;
		zapic.push_back(1);
		while (n != 15)
		{
			zapic.push_back(0);
			n++;
		}
	}

	for (j = i; j >= 1; j--)
	{
		zapic.push_back(array[j]);
	}

	return zapic;
}

vector <bool> changeReverse(int num)
{
	int n;
	if (num > 0)
	{
		return changeStraight(num);
	}
	if (num < 0)
	{
		vector <bool> help = changeStraight(num);
		for (int i = 0; i < help.size(); i++)
		{
			if (help[i] == 0)
			{
				help[i] = 1;
				continue;
			}
			else
			{
				help[i] = 0;
				continue;
			}
		}
		help[0] = 1;
		return help;
	}
}

vector <bool> changeDop(int num)
{
	if (num > 0)
	{
		return changeStraight(num);
	}
	if (num < 0)
	{
		vector <bool> help1 = changeReverse(num);
		vector <bool> help2 = changeStraight(1);

		vector <bool> rezult;
		bool flag = false;

		for (int i = 15; i >= 0; i--)
		{
			if (help1[i] == 0 && help2[i] == 0 && flag == false)
			{
				rezult.emplace(rezult.begin(), 0);  //вставка в начало вектора
				flag = false;
			}

			else if (help1[i] == 0 && help2[i] == 0 && flag == true)
			{
				rezult.emplace(rezult.begin(), 1);
				flag = false;
			}
			else if (help1[i] == 1 && help2[i] == 0 && flag == false)
			{
				rezult.emplace(rezult.begin(), 1);
				flag = false;
			}
			else if (help1[i] == 1 && help2[i] == 0 && flag == true)
			{
				rezult.emplace(rezult.begin(), 0);
				flag = true;
			}
			else if (help1[i] == 0 && help2[i] == 1 && flag == false)
			{
				rezult.emplace(rezult.begin(), 1);
				flag = false;
			}
			else if (help1[i] == 0 && help2[i] == 1 && flag == true)
			{
				rezult.emplace(rezult.begin(), 0);
				flag = true;
			}
			else if (help1[i] == 1 && help2[i] == 1 && flag == false)
			{
				rezult.emplace(rezult.begin(), 0);
				flag = true;
			}
			else if (help1[i] == 1 && help2[i] == 1 && flag == true)
			{
				rezult.emplace(rezult.begin(), 1);
				flag = true;
			}
		}

		return rezult;
	}
}

//сумма
vector <bool> sum(vector <bool> help1, vector <bool> help2)
{

	vector <bool> rezult;
	vector <bool> rez;

	bool flag = false;

	for (int i = 15; i >= 0; i--)
	{
		if (help1[i] == 0 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);  //вставка в начало вектора    
			flag = false;
		}

		else if (help1[i] == 0 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = true;
		}
	}

	return rezult;
}


vector <bool> fromRevToStr(vector <bool> help)
{
	if (help[0] == 1)
	{
		for (int i = 0; i < 16; i++)
		{
			help[i] = !help[i];
		}
		help[0] = 1;
		return help;
	}
	else return help;
};
vector <bool> fromDopToRev(vector <bool> help)
{
	if (help[0] == 1)
	{
		help = sum(help, oneM);
		return help;
	}
	else return help;
}
vector <bool> fromStrToDop(vector <bool> help)
{
	if (help[0] == 1)
	{
		for (int i = 0; i < help.size(); i++)
		{
			help[i] = !help[i];
		}
		help[0] = 1;
		return help;
	}
	else return help;
}
vector <bool> strToRev(vector <bool> help)
{
	if (help[0] == 1)
	{
		for (int i = 0; i < help.size(); i++)
		{
			help[i] = !help[i];
		}
		help[0] = 1;
	}
	return help;
}
vector <bool> strToDop(vector <bool> help)
{
	if (help[0] == 1)
	{
		for (int i = 0; i < help.size(); i++)
		{
			help[i] = !help[i];
		}
		help = sum(help, one);
		help[0] = 1;
	}
	return help;
}


vector <bool> sumDop(vector <bool> help1, vector<bool> help2) {
	vector <bool> rezult;
	vector <bool> rez;

	bool flag = false;

	for (int i = 15; i >= 0; i--)
	{
		if (help1[i] == 0 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);  //вставка в начало вектора   
			flag = false;
		}

		else if (help1[i] == 0 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = true;
		}
	}
	rez = fromRevToStr(rezult);
	vector <bool> Rezz = sum(rez, one);

	return Rezz;
}
vector <bool> sumRev(vector <bool> help1, vector<bool> help2) {
	vector <bool> rezult;
	vector <bool> rez;

	bool flag = false;

	for (int i = 15; i >= 0; i--)
	{
		if (help1[i] == 0 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);  //вставка в начало вектора  
			flag = false;
		}

		else if (help1[i] == 0 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 1 && help2[i] == 0 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = false;
		}
		else if (help1[i] == 0 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == false)
		{
			rezult.emplace(rezult.begin(), 0);
			flag = true;
		}
		else if (help1[i] == 1 && help2[i] == 1 && flag == true)
		{
			rezult.emplace(rezult.begin(), 1);
			flag = true;
		}
	}

	if (flag == true) {
		rezult = sum(rezult, one);
		return rezult;
	}
	else {
		return rezult;
	}
}


//умножение 
vector <bool> multiStraight(vector <bool> help1, vector <bool> help2)
{
	vector <bool> rezult{ 0,0,0,0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool flag = false;
	if (help1[0] == help2[0])
	{
		flag = true;
	}

	if (help2[0] == 1)
	{
		help2[0] = 0;
	}

	while (help2 != zero)
	{
		rezult = sum(help1, rezult);
		help2 = sum(help2, oneM);
	}

	if (flag == true)
	{
		rezult[0] = 0;
	}
	else
	{
		rezult[0] = 1;
	}

	return rezult;
}


//деление
void del(vector <bool> help1, vector <bool> help2)
{
	vector <bool> rezult{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	vector <bool> res;
	vector <bool> rem;
	vector <bool> b_plus;
	int off_a = 0;
	int off_b = 0;
	int off = 0;
	bool sign = false;

	if (help1[0] == help2[0])
	{
		sign = true;
	}

	if (help1[0] == 1)
	{
		help1 = fromRevToStr(fromDopToRev(help1));
		help1[0] = 0;
	}

	if (help2[0] == 1)
	{
		help2 = fromRevToStr(fromDopToRev(help2));
		help2[0] = 0;
	}
	b_plus = help2;

	do
	{
		off_a++;
	} while (help1[off_a] != 1);

	do
	{
		off_b++;
	} while (help2[off_b] != 1);

	off = off_b - off_a;
	for (int i = 0; i < off; i++)
	{
		help2.push_back(0);
		help2.erase(help2.begin());
	}
	help2[0] = 1;
	help2 = fromStrToDop(help2);
	rem = sum(help1, help2);
	if (rem[0] == 1)
	{
		res.emplace(res.begin(), 0);
	}
	else
	{
		res.emplace(res.begin(), 1);
	}

	for (int i = 0; i < off; i++)
	{
		b_plus.push_back(0);
		b_plus.erase(b_plus.begin());
		rem.push_back(0);
		rem.erase(rem.begin());

		if (rem[0] == 1)
		{
			rem = sum(rem, b_plus);
		}
		else
		{
			rem = sum(rem, help2);
		}

		if (rem[0] == 1)
		{
			res.push_back(0);
		}
		else
		{
			res.push_back(1);
		}
	}

	if (rem[0] == 1)
	{
		rem = sum(rem, b_plus);
	}

	for (int i = 0; i < off; i++)
	{
		rem.erase(rem.begin() + 15);
		rem.emplace(rem.begin(), 0);
	}

	int sz = res.size();
	for (int i = 0; i < 16 - sz; i++)
	{
		res.emplace(res.begin(), 0);
	}

	if (!sign)
	{
		res[0] = 1;
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
	}
	cout << ',';
	for (int i = 11; i < rem.size(); i++)
	{
		cout << rem[i];
	}
	cout << endl;
}

//плавающая точка
void plav(Plav a, Plav b)
{
	Plav res;
	bool sign = true;
	if (a.mantissa[0] != b.mantissa[0])
	{
		sign = false;
	}
	while (a.index != b.index)
	{
		a.index = sum(a.index, one);
		a.mantissa.emplace(a.mantissa.begin(), 0);
		a.mantissa.erase(a.mantissa.begin() + 1);
	}
	res.mantissa = sum(a.mantissa, b.mantissa);
	res.index = a.index;

	if (!sign)
		cout << "0,";
	for (size_t i = 0; i < res.mantissa.size(); i++)
	{
		cout << res.mantissa[i];
	}
	cout << "*2^";
	for (size_t i = 0; i < res.index.size(); i++)
	{
		cout << res.index[i];
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "rus");

	vector <bool> help;
	int number1, number2;
	//ввод чисел------------------------------
	char string[100];
	cout << "Введите первое целое число: ";
	gets_s(string); 
	number1 = atoi(string);//конвертация строки в числовой вид

	cout << "Введите второе целое число: ";
	gets_s(string);
	number2 = atoi(string);
	cout << endl;
	//-------------------------------------------


	//------------КОД------------------------------
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << number1 << ":\t";

	vector <bool> KOD;
	KOD = changeStraight(number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number1);
	Print(KOD);
	cout << endl;

	cout << number2 << ":\t";
	KOD = changeStraight(number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number2);
	Print(KOD);
	cout << endl;
	//-------------------
	cout << -number1 << ":\t";
	KOD = changeStraight(-number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number1);
	Print(KOD);
	cout << endl;

	cout << -number2 << ":\t";
	KOD = changeStraight(-number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number2);
	Print(KOD);
	cout << endl;
	cout << endl << "\t" << "------------------------------------------------" << endl;

	//--------------------------------------------------------------------

	//-----------------СУММА-----------------------------------------------
	cout << "\t\t\t" << "СУММА" << endl << endl;
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	//           X1 + X2
	cout << "\t\t------\t" << number1 << " + " << number2 << " = " << number1 + number2 << "  -------" << endl;
	//---------------------
	cout << number1 << ":\t";
	KOD = changeStraight(number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number1);
	Print(KOD);
	cout << endl;

	cout << number2 << ":\t";
	KOD = changeStraight(number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number2);
	Print(KOD);
	cout << endl;
	//---------------------
	vector <bool> symma = sum(changeStraight(number1), changeStraight(number2));
	cout << "\t";
	Print(symma);
	cout << "\t";
	symma = sumDop(changeDop(number1), changeDop(number2));
	Print(symma);
	cout << "\t\t";
	symma = sumRev(changeReverse(number1), changeReverse(number2));
	Print(symma);
	cout << endl << endl;


	//          X1 - X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t" << number1 << " - " << number2 << " = " << number1 - number2 << "  -------" << endl;
	int num2 = -number2;
	//---------------------
	cout << number1 << ":\t";
	KOD = changeStraight(number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number1);
	Print(KOD);
	cout << endl;

	cout << -number2 << ":\t";
	KOD = changeStraight(-number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	if (abs(number1) > abs(number2))
	{
		symma = sum(changeStraight(number1), changeDop(num2));
		Print(symma);
		cout << "\t";
		symma = sumDop(changeDop(number1), changeDop(-number2));
		Print(symma);
		cout << "\t\t";
		symma = sumRev(changeReverse(number1), changeReverse(-number2));
		Print(symma);
		cout << endl << endl;
	}
	else
	{
		symma = sumDop(changeStraight(number1), changeDop(num2));
		Print(fromRevToStr(fromDopToRev(symma)));
		cout << "\t";
		Print(symma);
		cout << "\t\t";
		Print(fromDopToRev(symma));
	}
	cout << endl << endl;

	//             -X1 + X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t-" << number1 << " + " << number2 << " = " << -number1 + number2 << "  -------" << endl;
	//---------------------
	cout << -number1 << ":\t";
	KOD = changeStraight(-number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number1);
	Print(KOD);
	cout << endl;

	cout << number2 << ":\t";
	KOD = changeStraight(number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	int num1 = -number1;
	if (abs(number1) > abs(number2))
	{
		symma = sum(changeDop(num1), changeStraight(number2));
		Print(fromRevToStr(fromDopToRev(symma)));
		cout << "\t";
		Print(symma);
		cout << "\t\t";
		Print(fromDopToRev(symma));
		cout << endl;
	}
	else
	{
		symma = sum(changeStraight(number2), changeDop(num1));
		for (int i = 0; i < 3; i++)
		{
			Print(symma);
			if (i == 1) cout << "\t\t";
			else
				cout << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//        -X1 - X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t" << "- " << number1 << " - " << number2 << " = " << -number1 - number2 << "  -------" << endl;
	cout << -number1 << ":\t";
	KOD = changeStraight(-number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number1);
	Print(KOD);
	cout << endl;

	cout << -number2 << ":\t";
	KOD = changeStraight(-number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	int numMM1 = -number1;
	int numMM2 = -number2;
	symma = sum(changeDop(numMM1), changeDop(numMM2));
	Print(fromRevToStr(fromDopToRev(symma)));
	cout << "\t";
	Print(symma);
	cout << "\t\t";
	Print(fromDopToRev(symma));
	cout << endl << endl;

	//----------------------------------------------------

	//-----------ПРОИЗВЕДЕНИЕ-----------------------------
	cout << "\t\t\t" << "ПРОИЗВЕДЕНИЕ " << endl << endl;
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	vector <bool> multS1, multS2, multD1, multD2, multR1, multR2, multS2M, multS1M;
	multS1 = changeStraight(number1);
	multS2 = changeStraight(number2);
	multS2M = changeStraight(numMM2);
	multS1M = changeStraight(numMM1);
	multD1 = changeDop(number1);
	multD2 = changeDop(number2);
	multR1 = changeReverse(number1);
	multR2 = changeReverse(number2);
	//                                          X1 * X2
	cout << "\t\t------\t" << number1 << " * " << number2 << " = " << number1 * number2 << "  -------" << endl;
	//---------------------
	cout << number1 << ":\t";
	KOD = changeStraight(number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number1);
	Print(KOD);
	cout << endl;

	cout << number2 << ":\t";
	KOD = changeStraight(number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	vector <bool> mult = multiStraight(multS1, multS2);
	Print(mult);
	cout << "\t";
	mult = multiStraight(multD1, multD2);
	Print(mult);
	cout << "\t\t";
	mult = multiStraight(multR1, multR2);
	Print(mult);
	cout << endl << endl;

	//                                          X1 * -X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t" << number1 << " * ( -" << number2 << ") = " << number1 * numMM2 << "  -------" << endl;
	//---------------------
	cout << number1 << ":\t";
	KOD = changeStraight(number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number1);
	Print(KOD);
	cout << endl;

	cout << -number2 << ":\t";
	KOD = changeStraight(-number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	mult = multiStraight(multS1, multS2M);
	Print(mult);
	cout << "\t";
	Print(strToDop(mult));
	cout << "\t\t";
	Print(strToRev(mult));
	cout << endl << endl;

	//                                           -X1 * X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t(-" << number1 << ") * " << number2 << " = " << numMM1 * number2 << "  -------" << endl;
	//---------------------
	cout << -number1 << ":\t";
	KOD = changeStraight(-number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number1);
	Print(KOD);
	cout << endl;

	cout << number2 << ":\t";
	KOD = changeStraight(number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	mult = multiStraight(multS1M, multS2);
	Print(mult);
	cout << "\t";
	Print(strToDop(mult));
	cout << "\t\t";
	Print(strToRev(mult));
	cout << endl << endl;

	//                                             -X1 * -X2
	cout << "\t" << "Прямой код: " << "\t\t" << "Дополнительный код: " << "\t\t" << "Обратный код: " << endl;
	cout << "\t\t------\t(-" << number1 << ") * (-" << number2 << ") = " << numMM1 * numMM2 << "  -------" << endl;
	cout << -number1 << ":\t";
	KOD = changeStraight(-number1);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number1);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number1);
	Print(KOD);
	cout << endl;

	cout << -number2 << ":\t";
	KOD = changeStraight(-number2);
	Print(KOD);
	cout << "\t";

	KOD = changeDop(-number2);
	Print(KOD);
	cout << "\t\t";

	KOD = changeReverse(-number2);
	Print(KOD);
	cout << endl;
	//---------------------
	cout << "\t";
	mult = multiStraight(multS1M, multS2M);
	Print(mult);
	cout << "\t";
	Print(strToDop(mult));
	cout << "\t\t";
	Print(strToRev(mult));
	cout << endl << endl;
	//-----------------------------------------------------


	//-------------------------------------------------

	//                             ДЕЛЕНИЕ
	vector <bool> delenie;
	//                              X1 / X2
	cout << "\t\t\t" << "ДЕЛЕНИЕ " << endl;
	//cout << "\t" << "Прямой код: " << "\t" << "Дополнительный код: " << "\t" << "Обратный код: " << endl << endl;
	cout << "\t\t\t X1 / X2" << endl;
	multS1 = changeStraight(number1);
	multS2 = changeStraight(number2);
	del(multS1, multS2);

	//                              X1 / (-X2)
	cout << "\t\t\t X1 / (-X2)" << endl;
	multS1 = changeStraight(number1);
	multS2 = changeDop(-number2);
	del(multS1, multS2);

	//                              (-X1) / X2
	cout << "\t\t\t (-X1) / X2" << endl;
	multS1 = changeDop(-number1);
	multS2 = changeStraight(number2);
	del(multS1, multS2);

	//                              (-X1) / (-X2)
	//-------------------------------------------------
	cout << "\t\t\t (-X1) / (-X2)" << endl;
	multS1 = changeDop(-number1);
	multS2 = changeDop(-number2);
	del(multS1, multS2);

	//                        С ПЛАВАЮЩЕЙ ТОЧКОЙ
	cout << "\t\t\t Сумма с плавающей точкой:" << endl;
	const Plav plavP1 = { changeStraight(number1),
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
	const Plav plavM1 = { changeStraight(-number1),
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 } };
	const Plav plavP2 = { changeStraight(number2),
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } };
	const Plav plavM2 = { changeStraight(-number2),
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 } };
	cout << "\t\t";
	plav(plavP1, plavP2);

	return 0;
}