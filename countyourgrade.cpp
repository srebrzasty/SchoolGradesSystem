#include <iostream>
#include <vector>
#include <limits>
//Definiuje kody błędu
#define GRADES_ERROR 0
#define WEIGHTS_OF_GRADES_ERROR 1
using namespace std;
 
void edit_vector_in_case_of_error(std::vector<float>&grades,std::vector<int>&weights_of_grades,int pos,int err_code){
	int ARG;
	if(err_code == GRADES_ERROR){
		std::cout<<"Grade is grater then 6"<<std::endl;
		std::cin>>ARG;
		grades[pos] = ARG;
	}
	if(err_code == WEIGHTS_OF_GRADES_ERROR){
		std::cout<<"weights of this grade is grater then 6"<<std::endl;
		std::cin>>ARG;
		weights_of_grades[pos] = ARG;
	}
}

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
 
	std::vector<float>grades; // vector zamiast tablicy ponieważ automatycznie alokuje pamięć i nie prowadzi do buffer overflow
	float inital_grade; //zmienna uzywana do przechowania liczby by potem dodać ją do vectora grades

	std::vector<int>weights_of_grades;
	int uinital_grade;

	int nominator = 0;
	for (nominator; nominator < number_of_grades; nominator++) // ta petla ma za zadanie zapelnienie tablic ocenami i wagami
	{
		cout << "\nWpisz ocene: ";
		while(!(std::cin>>inital_grade)){
			std::cout<<"Podaj wartosc liczbowa"<<std::endl;
			std::cin.clear(); //usuwa flagi błędu
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//ignoruje znaki w buforze wejściowym do '\n'
		}

		grades.push_back(inital_grade);//Dodanie wartość inital_grade do końca wektora

		cout << "Wpisz wage: ";
		while(!(std::cin>>uinital_grade)){
			std::cout<<"Podaj wartosc liczbowa"<<std::endl;
			std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
 		weights_of_grades.push_back(uinital_grade);

		if(grades[nominator] > 6){
			edit_vector_in_case_of_error(grades,weights_of_grades,nominator,GRADES_ERROR);
		}
		if(weights_of_grades[nominator] > 6){
			edit_vector_in_case_of_error(grades,weights_of_grades,nominator,WEIGHTS_OF_GRADES_ERROR);
		}

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