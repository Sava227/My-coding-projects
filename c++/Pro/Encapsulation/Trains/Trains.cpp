#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;

class Time {
private:
	int hour;
	int minute;

public:
	Time() : hour(0), minute(0) {}
	Time(int h, int m) : hour(h), minute(m) {}

	void set_time(int h, int m) {
		hour = h;
		minute = m;
	}

	string get_time() const {
		ostringstream oss;
		oss << setw(2) << setfill('0') << hour << ":"
		    << setw(2) << setfill('0') << minute;
		return oss.str();
	}

	int to_minutes() const {
    	return hour * 60 + minute;
	}

	int diff_minutes(const Time& other) const {
		return other.to_minutes() - to_minutes();
	}
};

class Train {
private:
	string start_city;
	string end_city;
	Time leaving_time;
	char class_of_train;
	int tickets_amount;

public:
	void load_data(ifstream& file) {
		string line;
		getline(file, line);
		if (line.empty()) return;		// If the filled line is empty, skip it

		// Minsk - Brest route
		size_t pos = line.find('-');
		if (pos != string::npos) {
			start_city = line.substr(0, pos - 1);
			end_city = line.substr(pos + 2);
		}

		int h;
		int m;
		file >> h >> m;
		leaving_time.set_time(h, m);	// setting the leaving time here

		file >> class_of_train;
		file >> tickets_amount;
		file.ignore();
	}

	void show_info() const {									// trains info such as departure, class and tickets
        cout << left << setw(15) << start_city
             << " -> " << setw(15) << end_city
             << " | Departure: " << leaving_time.get_time()
             << " | Class: " << class_of_train
             << " | Tickets: " << tickets_amount << "\n";
    }

	bool available_to_get_ticket() const {
        return tickets_amount > 0;
    }

    bool buy_ticket() {
        if (!available_to_get_ticket()) return false;
        tickets_amount--;
        return true;
    }

    // return is allowed only if there is more than 60 minutes before departure here :D
    bool return_ticket(const Time& current_time) {
        int before = leaving_time.to_minutes() - current_time.to_minutes();
        if (before < 0) before += 24 * 60; // if current_time is after midnight, relative to departure
        if (before < 60) return false;

        tickets_amount++;
        return true;
    }
};

static void print_trains(const vector<Train>& trains) {
    cout << "\n=== Trains list ===\n";
    for (size_t i = 0; i < trains.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        trains[i].show_info();
    }
    cout << endl;
}

static Time input_time() {
    int h, m;
    cout << "Enter time (hh mm): ";
    cin >> h >> m;
    return Time(h, m);
}

int main() {
    ifstream file("trains.txt");
    if (!file.is_open()) {
        cout << "Cannot open trains.txt\n";
        return 0;
    }

    vector<Train> trains;
    while (true) {
        Train t;
        t.load_data(file);
        if (!file) break;              // stop if reading failed :(
        trains.push_back(t);
    }
    file.close();

    int choice = -1;
    while (choice != 0) {
        cout << "\nMenu:\n"
             << "1) Show all trains\n"
             << "2) Buy ticket\n"
             << "3) Return ticket\n"
             << "0) Exit\n"
             << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            print_trains(trains);
        }
        else if (choice == 2) {
            print_trains(trains);
            cout << "Train number: ";
            int idx;
            cin >> idx;
            if (idx < 1 || idx > (int)trains.size()) {
                cout << "Wrong number.\n";
                continue;
            }
            if (trains[idx - 1].buy_ticket())
                cout << "Ticket bought!\n";
            else
                cout << "No tickets left.\n";
        }
        else if (choice == 3) {
            print_trains(trains);
            cout << "Train number: ";
            int idx;
            cin >> idx;
            if (idx < 1 || idx > (int)trains.size()) {
                cout << "Wrong number.\n";
                continue;
            }
            Time now = input_time();
            if (trains[idx - 1].return_ticket(now))
                cout << "Ticket returned!\n";
            else
                cout << "Return is not allowed unless than 60 minutes before departure.\n";
        }
        else if (choice == 0) {
            cout << "see you later\n";
        }
        else {
            cout << "unknown option.\n";
        }
    }
    return 0;
}
