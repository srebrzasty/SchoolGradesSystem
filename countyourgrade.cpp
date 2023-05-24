#include <iostream>
#include <vector>
#include <limits>
//Definiuje kody błędu
#define GRADES_ERROR 0
#define WEIGHTS_OF_GRADES_ERROR 1
using namespace std;

/*
	Dodano funkcje i_readInput i f_readInput, które umożliwiają wczytywanie danych od użytkownika z jednoczesnym sprawdzaniem błędu.
	Funkcja i_readInput służy do wczytywania wartości typu int, natomiast f_readInput do wartości typu float.
	Dodano pętlę while, która umożliwia ponowne obliczenie ocen.
	Po zakończeniu programu użytkownik jest pytany, czy chce ponownie obliczyć oceny.
*/


// i_readInput i f_readInput służą do pobierania wartość od użytkownika
// i_readInput - dla zmiennych typu int
// f_readInput - dla zmiennych typu float
void i_readInput(int& arg){
	while(!(std::cin>>arg)){
		std::cout<<"Podaj wartosc liczbowa"<<std::endl;
		std::cin.clear(); //usuwa flagi błędu
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//ignoruje znaki w buforze wejściowym do '\n'
	}
}
void f_readInput(float& arg){
	while(!(std::cin>>arg)){
		std::cout<<"Podaj wartosc liczbowa"<<std::endl;
		std::cin.clear(); //usuwa flagi błędu
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//ignoruje znaki w buforze wejściowym do '\n'
	}
}

void edit_vector_in_case_of_error(std::vector<float>&grades,std::vector<int>&weights_of_grades,int pos,int err_code){
	int i_arg;
	float f_arg; 
	if(err_code == GRADES_ERROR){
		std::cout<<"Grade is grater then 6"<<std::endl;
		i_readInput(i_arg);
		grades[pos] = i_arg;
	}
	if(err_code == WEIGHTS_OF_GRADES_ERROR){
		std::cout<<"weights of this grade is grater then 6"<<std::endl;
		f_readInput(f_arg);
		weights_of_grades[pos] = f_arg;
	}
}


int main()
{
	cout << "---------------------------------------------------------------------\n";
	cout << "If there is a rational number use dot instead comma.\n";
    cout << "Written in ZSTH Zagan, for usage I recommend contact with this school\n";
	cout << "---------------------------------------------------------------------\n";
	while(true){
		int number_of_grades, not_counted, denominator,loop_arg;

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
			f_readInput(inital_grade);

			grades.push_back(inital_grade);//Dodanie wartość inital_grade do końca wektora

			cout << "Wpisz wage: ";
			i_readInput(uinital_grade);

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
		i_readInput(not_counted);

	
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
			cout << " insufficient\n";
		if (result >= 30 && result < 45)
			cout << " 2\n";
		if (result >= 45 && result < 65)
			cout << " sufficient\n";
		if (result >= 65 && result < 80)
			cout << " Good\n";
		if (result >= 80 && result < 95)
			cout << " Very Good\n";
		if (result >= 95 && result <= 100)
			cout << "\n";

		std::cout<<"Do you want to count grades again?=(1)-yes/(0)-no"<<std::endl;
		i_readInput(loop_arg);
		if(loop_arg == 1){
			grades.clear();
			weights_of_grades.clear();
		}
		if(loop_arg == 0){break;}
	}
	_getwch();
	return 0;
}