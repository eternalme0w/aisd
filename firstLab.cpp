#include <iostream>
#if (defined(linux) || defined(__MACH__))
#define CLS system("clear")
#else
#define CLS system("cls")
#endif /* OS_TYPE */

using std::cin, std::cout, std::endl;


bool in_set(int* mass, int el) {

	bool ans = 0; 

	for (int i = 0; i < 10; i++) {

		if (mass[i] == el) {

			ans = 1;
			break;
		}
	}

	return ans;
}

int* get_mass() {

	static int mass[10];
	static int arr;

	for (int i = 0; i < 10; mass[i++] = -1);

	int a = 1024;
	int i = 0;

	cout << "Enter 10 or less numbers from 0 to 9: ";

	while(cin.peek() != 10 || a > 9 || a <= 0) {

		CLS;

		if (cin.fail()) {

			i = 0;
			cin.clear();
			cin.ignore(1024, '\n');
		}

		cout << "Enter 10 or less numbers from 0 to 9: ";

		if (cin >> a &&  a < 10 && a > 0 && !in_set(mass, a)) mass[i++] = a;	
	}

	CLS;

	return mass;
}


int massln(int* mass) {

	int i;

	for (i = 0; i < 10; i++) {

		if (mass[i] == -1) break;
	}

	return i;
}

void print_mass(int* mass) {

	for (int i = 0; i < massln(mass); cout << mass[i++] << " ");
	cout << endl;
}


int main() {

	int* mass = get_mass();

	print_mass(mass);	

	return 0;
}
