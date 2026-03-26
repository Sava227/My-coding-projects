#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Exam {
public:
    string Subject;
    string Teacher;
    int Grade;        // 1..6
    string Effort;
    string Attitude;
    string Comment;

    Exam()
        : Subject("Mathematics"), Teacher(""), Grade(2),
          Effort("Satisfactory"), Attitude("Satisfactory"), Comment("") {}

    Exam(string subject, string teacher, int grade, string effort, string attitude, string comment)
        : Subject(subject), Teacher(teacher), Grade(grade),
          Effort(effort), Attitude(attitude), Comment(comment) {}

    bool isFail() { return Grade == 2; }
};

class Student {
public:
    string Name, Surname;
    int SchoolNumber;
    vector<Exam> Exams;

    Student() : Name(""), Surname(""), SchoolNumber(0) {}
    Student(string name, string surname, int schoolNumber)
        : Name(name), Surname(surname), SchoolNumber(schoolNumber) {}

    void addExam(Exam e) { Exams.push_back(e); }

    void PrintReportCard() {
        cout << "\n==================== REPORT CARD ====================\n";
        cout << "Name: " << Name << "\n";
        cout << "Surname: " << Surname << "\n";
        cout << "School number: " << SchoolNumber << "\n";
        cout << "=====================================================\n";

        cout << "SUBJECT | TEACHER | GRADE | EFFORT | ATTITUDE\n";
        cout << "-----------------------------------------------------\n";

        bool anyFail = false;

        for (int i = 0; i < (int)Exams.size(); i++) {
            // Not aligned nicely, but simple:
            cout << Exams[i].Subject << " | "
                 << Exams[i].Teacher << " | "
                 << Exams[i].Grade << " | "
                 << Exams[i].Effort << " | "
                 << Exams[i].Attitude << "\n";

            if (Exams[i].Grade == 2) anyFail = true;
        }

        cout << "-----------------------------------------------------\n";
        cout << "Overall result: " << (anyFail ? "FAIL (has grade 2)" : "PASS") << "\n";
        cout << "=====================================================\n";

        cout << "\nTeacher comments:\n";
        for (int i = 0; i < (int)Exams.size(); i++) {
            cout << "\n--- " << Exams[i].Subject << " ---\n";
            cout << "Teacher: " << Exams[i].Teacher << "\n";
            cout << "Grade: " << Exams[i].Grade << " (" << (Exams[i].Grade == 2 ? "FAIL" : "PASS") << ")\n";
            cout << "Effort: " << Exams[i].Effort << "\n";
            cout << "Attitude: " << Exams[i].Attitude << "\n";
            cout << "Comment: " << Exams[i].Comment << "\n";
        }

        cout << "\n";
    }
};

// helpers
int readInt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Try again.\n";
    }
}

string readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int chooseFromList(const string& title, const vector<string>& options) {
    cout << title << "\n";
    for (int i = 0; i < (int)options.size(); i++) {
        cout << "  " << (i + 1) << ") " << options[i] << "\n";
    }
    while (true) {
        int c = readInt("Choose (1-" + to_string(options.size()) + "): ");
        if (c >= 1 && c <= (int)options.size()) return c - 1;
        cout << "Out of range. Try again.\n";
    }
}

int readGrade1to6() {
    while (true) {
        int g = readInt("Grade (1-6): ");
        if (g >= 1 && g <= 6) return g;
        cout << "Grade must be from 1 to 6.\n";
    }
}

int main() {
    vector<string> subjects = { "English", "Mathematics", "Science", "History", "Computing", "STEM+" };
    vector<string> effort = { "Excellent", "Very good", "Good", "Satisfactory", "Needs improvement" };
    vector<string> attitude = { "Excellent", "Very good", "Good", "Satisfactory", "Needs improvement" };

    cout << "=== Student info ===\n";
    string name = readLine("Name: ");
    string surname = readLine("Surname: ");
    int schoolNo = readInt("School number: ");

    Student st(name, surname, schoolNo);

    int n = readInt("How many subjects to add? ");
    for (int i = 0; i < n; i++) {
        cout << "\n--- Subject " << (i + 1) << " ---\n";

        int subjIdx = chooseFromList("Select subject:", subjects);
        string teacher = readLine("Teacher name: ");
        int grade = readGrade1to6();
        int effIdx = chooseFromList("Select effort:", effort);
        int attIdx = chooseFromList("Select attitude:", attitude);
        string comment = readLine("Teacher comment: ");

        st.addExam(Exam(subjects[subjIdx], teacher, grade, effort[effIdx], attitude[attIdx], comment));
    }

    st.PrintReportCard();
    return 0;
}
