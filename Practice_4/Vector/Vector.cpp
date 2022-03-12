#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct race_data{
	string destin;
	int case_number;
	string date_departure;
	string departure_time;
	string arrival_time;
	int free_places;
	int delay;
	
};
struct Board {
	vector<race_data> mas;
};

race_data create_new();

void add_race(Board& airport1);

void print_race(Board airport1, int i);

void print_board(Board airport1);

void insert_race(Board& airport);

race_data delete_race(Board& airportboard, int id);

void to_reserve(Board& airportboard, Board& reserve, int id);

void print_withoutdelay_list(Board airport);

void find_flights_to(Board airport, string destination, vector<int>& masssive);

int main(){
	setlocale(LC_ALL, "");
	Board airport1;
	Board reserve;
	vector<int> mas;
	int id;
	int menu;
	string destination;
	cout << "Пользовательское меню: \n0- Для выхода;\n1- Для добавления рейса в таблицу;\n2- Удаление рейса из таблицы;\n3- Вывод таблицы на экран;\n4-Вставить информацию по новому рейсу в таблицу перед рейсом с большим номером\n5-Удалить информацию об вылетевшем рейсе и сохранить ее в архивной таблице;\n6-Вывести рейсы, готовые к вылету по расписанию (за 2 часа до времени вылета);\n7-Сформировать список номеров рейсов, вылетающих в заданный пункт назначения.\n8 - Вывести архивную таблицу рейсов\n";
	cin >> menu;
	while (menu) {
		switch (menu) {
		case 1:
			add_race(airport1);
			break;
		case 2:
			cout << "\nВведите id рейса\n";
			cin >> id;
			delete_race(airport1, id);
			break;
		case 3:
			print_board(airport1);
			break;
		case 4:
			insert_race(airport1);
			break;
		case 5:
			cout << "\nВведите id рейса\n";
			cin >> id;
			to_reserve(airport1, reserve, id);
			break;
		case 6:
			print_withoutdelay_list(airport1);
			break;
		case 7:
			cout << "\nВведите пункт назначения\n";
			cin >> destination;
			find_flights_to(airport1, destination, mas);
			break;
		case 8:
			print_board(reserve);
			break;
		}
		cout << "Пользовательское меню: \n0- Для выхода;\n1- Для добавления рейса в таблицу;\n2- Удаление рейса из таблицы;\n3- Вывод таблицы на экран;\n4-Вставить информацию по новому рейсу в таблицу перед рейсом с большим номером\n5-Удалить информацию об вылетевшем рейсе и сохранить ее в архивной таблице;\n6-Вывести рейсы, готовые к вылету по расписанию (за 2 часа до времени вылета);\n7-Сформировать список номеров рейсов, вылетающих в заданный пункт назначения.\n8 - Вывести архивную таблицу рейсов\n";
		cin >> menu;
	}
}

race_data create_new() {
	race_data race;
	cout << "ИНФОРМАЦИЯ О РЕЙСЕ " << endl;
	cout << "Введите пункт назначения: ";
	cin >> race.destin;
	cout << "\nНомер рейса: ";
	cin >> race.case_number;
	cout << "\nДату вылета(Например, 1990.10.23):";
	cin >> race.date_departure;
	cout << "\nВведите время вылета: ";
	cin >> race.departure_time;
	cout << "\nВремя прибытия: ";
	cin >> race.arrival_time;
	cout << "\nВведите кол-во свободных мест: ";
	cin >> race.free_places;
	cout << "\nВведите задержку рейса в часах: ";
	cin >> race.delay;
	return race;
}

void add_race(Board& airport1) {
	race_data race = create_new();
	airport1.mas.push_back(race);
}

void print_race(Board airport1, int i) {
	cout << "|" << setw(10 + ((airport1.mas[i].destin).length() / 2)) << airport1.mas[i].destin << setw(10 - ((airport1.mas[i].destin).length() / 2)) << "|";
	cout << setw(8 + to_string(airport1.mas[i].case_number).length() / 2) << airport1.mas[i].case_number << setw(9 - to_string(airport1.mas[i].case_number).length() / 2) << "|";
	cout << setw(15) << airport1.mas[i].date_departure << setw(5) << "|";
	cout << setw(13) << airport1.mas[i].departure_time << setw(7) << "|";
	cout << setw(11) << airport1.mas[i].arrival_time << setw(7) << "|";
	cout << setw(14) << airport1.mas[i].free_places << setw(12) << "|";
	cout << setw(6) << airport1.mas[i].delay << setw(4) << "|" << endl;
}

void print_board(Board airport1) {
	cout << "|" << setw(15) << "Destination" << setw(5) << "|";
	cout << setw(15) << "Number of race" << setw(2) << "|";
	cout << setw(17) << "Despature date" << setw(3) << "|";
	cout << setw(17) << "Despature time" << setw(3) << "|";
	cout << setw(15) << "Arrival time" << setw(3) << "|";
	cout << "Number of available seats" << "|";
	cout << setw(7) << "Delay" << setw(3) << "|" << endl;
	for (int i = 0; i < airport1.mas.size(); i++) {
		print_race(airport1, i);
	}
}

void insert_race(Board& airport) {
	race_data insert_race = create_new();
	int max_number = airport.mas[0].case_number;
	int id_race = 0;
	for (int i = 0; i < airport.mas.size(); i++) {
		if (max_number < airport.mas[i].case_number) {
			max_number = airport.mas[i].case_number;
			id_race = i;
		}
	}
	airport.mas.insert(airport.mas.begin() + id_race, insert_race);
}


race_data delete_race(Board& airportboard, int id) {
	race_data deleted_race;
	int index;
	for (int i = 0; i < airportboard.mas.size(); i++) {
		if (airportboard.mas[i].case_number == id) {
			deleted_race = airportboard.mas[i];
			index = i;
			break;
		}
	}
	airportboard.mas.erase(airportboard.mas.begin() + index);
	return deleted_race;

}

void to_reserve(Board& airportboard, Board& reserve, int id) {
	race_data archive = delete_race(airportboard, id);
	reserve.mas.push_back(archive);
}

void print_withoutdelay_list(Board airport) {
	cout << "\nРейсы без задержки\n";
	for (int i = 0; i < airport.mas.size(); i++) {
		if (airport.mas[i].delay == 0) {
			print_race(airport, i);
		}
	}
}

void find_flights_to(Board airport, string destination, vector<int> & masssive) {
	for (int i = 0; i < airport.mas.size(); i++) {
		if (airport.mas[i].destin == destination) {
			masssive.push_back(airport.mas[i].case_number);
		}
	}
	cout << "\nНомера рейсов в " << destination << " : ";
	for (int i = 0; i < masssive.size(); i++) {
		cout << masssive[i] << " ";
	}
	cout << endl;

}