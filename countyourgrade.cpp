#include <iostream>

using namespace std;
 
int main()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "If there is a rational number use dot instead comma.\n";
    cout << "Written in ZSTH Zagan, for usage I recommend contact with this school";
	cout << "---------------------------------------------------------------------\n";
 
	int number_of_grades, not_counted, denominator;
 
	cout << "\nEnter the number of grades: ";
	cin >> number_of_grades; 
	cout << "\n";
 
	float grades[8]; // dynamic allocation of memory, pointers?
	int weights_of_grades[8]; // 
 
	int nominator = 0;
 
	for (nominator; nominator < number_of_grades; nominator++) // ta petla ma za zadanie zapelnienie tablic ocenami i wagami
	{
		cout << "\nWpisz ocene: ";
		cin >> grades[nominator];
 
		cout << "Wpisz wage: ";
		cin >> weights_of_grades[nominator];
 
	}
 
	float main_nominator = 0;
 
	for (nominator=0; nominator < number_of_grades; nominator++)
		main_nominator += grades[nominator] * weights_of_grades[nominator];
 
	cout << "\nPoints not_counted to maximum: ";
	cin >> not_counted;
 
	main_nominator += not_counted;
    
    float result = 0;

	cout << "\nTYour result is: " << main_nominator;
 
	nominator = 0;
	denominator = 0;
 
	for (nominator=0; nominator < number_of_grades; nominator++)
		denominator += 6 * weights_of_grades[nominator];
 
	cout << "\nYour maximum is:" << denominator;
 
	result = 0;
 
	result = (main_nominator / denominator) * 100;
    cout.precision(2);
	cout << "\nPercentage: " << result; // !!! result bedzie wyswietlany z dokladnoscia co do dwoch liczb po przecinku
	cout << "\n\nYour percent gives grade";
 
	if (result > 0 && result < 30)
		cout << " insufficient";
	if (result >= 30 && result < 45)
		cout << " 2";
	if (result >= 45 && result < 65)
		cout << " sufficient";
	if (result >= 65 && result < 80)
		cout << " Good";
	if (result >= 80 && result < 95)
		cout << " Very Good";
	if (result >= 95 && result <= 100)
		cout << "";
 
	_getwch();
	return 0;
}