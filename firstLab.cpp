#include <iostream>
#include <sstream>
#if (defined(linux) || defined(__MACH__))
#define CLS system("clear")
#else
#define CLS system("cls")
#endif /* OS_TYPE */

using namespace std;


struct node {

	node* next;
	int value;

	node (int i) {

		value = i;
		next = nullptr;
	}

};

static void print_list(node *p);
static void insert_node(node **pp, node *pn);
static void delete_node(node **pp);
node* last_node(node* phead);


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


int massln(int* mass) {

	int i;

	for (i = 0; i < 10; i++) {

		if (mass[i] == -1) break;
	}

	return i;
}

int* get_mass() {

	static int mass[10];
	int* arr;
	int n, flag = 1, i;
	string s, substr;

	while (flag) {

		for (int i = 0; i < 10; mass[i++] = -1);

		stringstream ss;
		getline(cin, s);
		ss << s;
		flag = 0;
		i = 0;

		while(ss.rdbuf()->in_avail() && !flag) {

			ss >> substr;
			stringstream num;
			num << substr, num >> n;;

			if (n == 0 || n >= 10 || n < 0 || substr.size() > 1) {

				if (substr[0] != '0') flag = 1;
		
			}

			if (!flag && !in_set(mass, n)) mass[i++] = n;
		}
		
	}

	arr = new int[massln(mass) + 1];
	for (int i = 0; i < massln(mass); i++) arr[i] = mass[i];
	arr[massln(mass)] = -1;
	
	return arr;

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


static void print_list(node *p) {

	while(p) {

		cout << p->value << " ";
		p = p->next;
	}

	cout << endl;
}

static void insert_node(node **pp, node* pn) {

	pn->next = *pp;
	*pp = pn;
}

static void delete_node(node **pp) {

	if (*pp == nullptr) return;

	node *ptmp = *pp;
	*pp = (*pp)->next;
	delete ptmp;
}

node* last_node(node* phead) {

	node* pn = phead;
	while(pn->next) pn = pn->next;	

	return pn;
}