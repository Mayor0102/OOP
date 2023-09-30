// Practic1(SEM3-2023).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>

using namespace std;


class Patient
{
public:
    string firstName;
    string lastName;
    string dateOfBirth;
    string phoneNumber;
    string address;
    string patientCardNumber;
    string bloodGroup;

    Patient()
        : firstName("Nothing"), lastName("Nothing"), dateOfBirth("Nothing"),
        phoneNumber("Nothing"), address("Nothing"), patientCardNumber("Nothing"),
        bloodGroup("Nothing") {}

    Patient(const string& firstName, const string& lastName, const string& dateOfBirth,
        const string& phoneNumber, const string& address, const string& patientCardNumber,
        const string& bloodGroup)
        : firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth),
        phoneNumber(phoneNumber), address(address), patientCardNumber(patientCardNumber),
        bloodGroup(bloodGroup) {}

    ~Patient() {}

    friend ostream& operator<<(ostream& s, const Patient& patient);
    friend istream& operator>>(istream& s, Patient& patient);

    bool operator>(const Patient& patient);
    bool operator<(const Patient& patient);
    bool operator==(const Patient& patient);
};

ostream& operator<<(ostream& stream, const Patient& patient) {
    return stream << "Firstname: " << patient.firstName << ", Lastname: " << patient.lastName << ", Date Of Birth: " << patient.dateOfBirth << ", Phone Number: " << patient.phoneNumber << ", Address: " << patient.address << ", Patient Card Number: " << patient.patientCardNumber << ", Blood Group: " << patient.bloodGroup;
}

istream& operator>>(istream& stream, Patient& patient) {
    return stream >> patient.firstName >> patient.lastName >> patient.dateOfBirth >> patient.phoneNumber >> patient.address >> patient.patientCardNumber >> patient.bloodGroup;
}

bool Patient::operator<(const Patient& patient) {
    if (patientCardNumber != patient.patientCardNumber)
        return patientCardNumber < patient.patientCardNumber;
    if (bloodGroup != patient.bloodGroup)
        return bloodGroup < patient.bloodGroup;
    if (firstName + lastName != patient.firstName + patient.lastName)
        return firstName + lastName < patient.firstName + patient.lastName;
    return false;
}

bool Patient::operator>(const Patient& patient) {
    if (patientCardNumber != patient.patientCardNumber)
        return patientCardNumber > patient.patientCardNumber;
    if (bloodGroup != patient.bloodGroup)
        return bloodGroup > patient.bloodGroup;
    if (firstName + lastName != patient.firstName + patient.lastName)
        return firstName + lastName > patient.firstName + patient.lastName;
    return false;
}

bool Patient::operator==(const Patient& patient) {
    if (patientCardNumber != patient.patientCardNumber)
        return patientCardNumber == patient.patientCardNumber;
    if (bloodGroup != patient.bloodGroup)
        return bloodGroup == patient.bloodGroup;
    if (firstName + lastName != patient.firstName + patient.lastName)
        return firstName + lastName == patient.firstName + patient.lastName;
    return false;
};

template<class T>
void push(list<T>& lst, const T value)
{
    auto it = lst.begin();
    while (it != lst.end() && *it > value)
    {
        ++it;
    }
    lst.insert(it, value);
}
template<class T>
T pop(list<T>& lst)
{
    if (!lst.empty()) {
        T highestPriority = lst.front();
        lst.pop_front();
        return highestPriority;
    }
}

bool pred(char x)
{
    return isalpha(x) && !strchr("AEIOUaeiou", x);
}

template <typename T, typename Predicate>
list<T> filter(const list<T>& lst, Predicate pred)
{
    list<T> result;
    for (T c : lst)
    {
        if (pred(c))
            result.push_back(c);
    }
    return result;
}
int main()
{
    list<Patient> patientList;
    push(patientList, Patient("John", "Doe", "01.01.1980", "123456789", "123 Street, City", "000", "A+"));
    push(patientList, Patient("Julia", "Roberts", "04.03.1972", "987654324", "444 Avenue, City", "002", "0-"));
    push(patientList, Patient("Aram", "Mkhitaryan", "20.09.2004", "9175661964", "444 Avenue, City", "002", "0-"));
    push(patientList, Patient("Alice", "Johnson", "03.03.1990", "555555555", "789 Road, Village", "003", "AB+"));
    push(patientList, Patient("Bob", "Williams", "04.04.1985", "111111111", "987 Lane, County", "004", "O+"));
    push(patientList, (Patient("Jane", "Smith", "02.02.1975", "987654321", "456 Avenue, Town", "002", "B+")));
    push(patientList, Patient("Emily", "Brown", "05.05.2000", "999999999", "654 Drive, State", "005", "A-"));

    cout << "List after using push method: " << endl;
    for (Patient c : patientList)
    {
        cout << c << ' ';
        cout << endl;
    }

    cout << "Poped element: ";
    if (!patientList.empty())
    {
        Patient highestPriority = pop(patientList);
        cout << highestPriority << " ";
    }
    cout << endl;

    list<char> lst = {'A'};

    push(lst, 'B');
    push(lst, 'C');
    push(lst, 'P');
    push(lst, 'b');

    cout << "List after using push method: ";
    for (char c : lst)
    {
        cout << c << ' ';
    }

    cout << endl;

    cout << "Poped element: ";
    if (!lst.empty())
    {
        char highestPriority = pop(lst);
        cout << highestPriority << " ";
    }
    cout << endl;

    list<char> filteredCharList = filter(lst, pred);

    cout << "Filtered Char List (Consonants): ";
    for (char c : filteredCharList) {
        cout << c << " ";
    }
    cout << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
