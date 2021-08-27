#include <iostream>
#include <time.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)


struct Student {
	char* name;
	int id;
	float mark;
};

struct node {
	Student data;
	node* next;
};

struct list {
	node* head;
};

void initlist(list& l) {
	l.head = nullptr;
}

void printAStudent(Student x) {
	cout << "\n\t\tName: " << x.name;
	cout << "\n\t\tID: " << x.id;
	cout << "\n\t\tMark: " << x.mark << endl;
}

void printlist(list l) {
	int i = 1;
	while (l.head != nullptr) {
		cout << "\n\t\t================ STUDENT " << i++ << "================";
		printAStudent(l.head->data);
		l.head = l.head->next;
	}
}

node* createnode(Student x) {
	node* t = new node;
	if (t == nullptr) return nullptr;
	t->data = x;
	t->next = nullptr;
	return t;
}

void addhead(list& l, Student x) {
	node* t = createnode(x);
	if (t == nullptr) {
		cout << "invalid memory !";
		return;
	}
	
	if (l.head == nullptr) {
		l.head = t;
	}
	else {
		t->next = l.head;
		l.head = t;
	}
}

void addtail(list& l, Student x) {
	node* t = createnode(x);
	if (t == nullptr) {
		cout << "invalid memory !";
		return;
	}

	if (l.head == nullptr) {
		l.head = t;
	}
	else {
		node* temp = l.head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = t;
	}
}

void inputAStudent(Student& x) {
	cout << "\nenter ID: ";
	cin >> x.id;
	cout << "enter mark: ";
	cin >> x.mark;
	cin.ignore();
	cout << "enter name: ";
	char temp[20];
	cin.getline(temp, 21);
	x.name = new char[strlen(temp)];
	strcpy(x.name, temp);
}

void addafterhead(list &l, Student& x) {
	node* t = createnode(x);
	if (t == nullptr) {
		cout << "invalid memory !";
		return;
	}

	t->next = l.head->next;
	l.head->next = t;
}

void addbeforetail(list& l, Student& x) {
	node* t = createnode(x);
	if (t == nullptr) {
		cout << "invalid memory !";
		return;
	}

	node* temp = l.head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}

	t->next = temp->next;
	temp->next = t;
}

Student randomStudent() {
	srand(time(0));
	Student x;
	char a[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	char temp[5];
	for (int i = 0; i < 5; i++) {
		temp[i] = a[rand() % 51];
	}
	x.name = new char[5];
	strcpy(x.name, temp);
	x.id = rand() % 100000;
	x.mark = rand() % 10;
	return x;
}

void deletehead(list& l) {
	if (l.head == nullptr) {
		cout << "nothing to do !";
		return;
	}

	node* temp = l.head;
	l.head = l.head->next;
	delete temp;
}

void deletetail(list& l) {
	if (l.head == nullptr) {
		cout << "nothing to do";
		return;
	}

	node* temp = l.head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	
	node* t = temp->next;
	temp->next = nullptr;
	delete t;
}

void verselist(list& l) {
	if (l.head == nullptr) return;
	node* pre = nullptr;
	node* newhead = l.head;
	node* next = l.head->next;
	while (next != nullptr) {
		l.head->next = pre;
		pre = l.head;
		l.head = next;
		next = next->next;
		newhead = l.head;
	}
	newhead->next = pre;
	l.head = newhead;
}

bool iscirlist(list l) {
	if (l.head == nullptr || l.head->next == nullptr) return true;
	
	node* slow = l.head;
	node* fast = l.head->next;
	while (!fast && !fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow != fast) return true;
	}

	return false;
}

void swap(node*& a, node*& b) {
	int x = b->data.id;
	float y = b->data.mark;
	char temp[20];
	strcpy(temp, b->data.name);

	b->data.id = a->data.id;
	b->data.mark = a->data.mark;
	strcpy(b->data.name, a->data.name);

	a->data.id = x;
	a->data.mark = y;
	strcpy(a->data.name, temp);
}

void sort(list& l) {
	for (node* i = l.head; i->next != nullptr; i = i->next) {
		for (node* j = i->next; j != nullptr; j = j->next) {
			if (j->data.mark < i->data.mark) {
				swap(j, i);
			}
		}
	}
}

void insertnode(list& l, Student x) {
	if (l.head == nullptr) {
		addhead(l, x);
		return;
	}
	
	node* t = createnode(x);
	if (t == nullptr) {
		return;
	}

	node* temp = l.head;
	node* pre = new node;
	while (temp != nullptr) {
		if (temp->data.mark > x.mark) {
			break;
		}

		pre = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		addtail(l, x);
	}
	else {
		t->next = temp;
		pre->next = t;
	}
}

list findH(list l) {
	list ans;
	initlist(ans);

	node* temp = l.head;
	while (temp != nullptr) {
		if (temp->data.name[0] == 'H') {
			addtail(ans, temp->data);
		}
		temp = temp->next;
	}

	return ans;
}

void updatelist(list& l, Student x) {
	if (l.head == nullptr) {
		addhead(l, x);
		return;
	}

	node* t = createnode(x);
	if (t == nullptr) {
		return;
	}

	node* temp = l.head;
	while (temp != nullptr) {
		if (temp->data.id == x.id) {
			temp->data = x;
			break;
		}

		temp = temp->next;
	}

	if (temp == nullptr) {
		addtail(l, x);
	}
}

int main() {
	list l;
	initlist(l);

	cout << "\n================MENU================";
	cout << "\n\t0. break";
	cout << "\n\t1. print list";
	cout << "\n\t2. addhead";
	cout << "\n\t3. addtail";
	cout << "\n\t4. add before head";
	cout << "\n\t5. add after tail";
	cout << "\n\t6. add head 5 random student";
	cout << "\n\t7. delete head";
	cout << "\n\t8. delete tail";
	cout << "\n\t9. verse list";
	cout << "\n\t10. check list is circle";
	cout << "\n\t11. sort";
	cout << "\n\t12. insert";
	cout << "\n\t13. find H";
	cout << "\n\t14. update node";
	cout << "\n====================================\n";

	while (1) {
		int choise = 0;
		cout << "enter your choise: ";
		cin >> choise;
		switch (choise)
		{
		case 1: {
			printlist(l);
			break;
		}
		case 2: {
			Student x;
			inputAStudent(x);
			addhead(l, x);
			break;
		}
		case 3:
		{
			Student x;
			inputAStudent(x);
			addtail(l, x);
			break;
		}
		case 4:
		{
			Student x;
			inputAStudent(x);
			addafterhead(l, x);
			break;
		}
		case 5:
		{
			Student x;
			inputAStudent(x);
			addbeforetail(l, x);
			break;
		}
		case 6:
		{
			Student x;
			for (int i = 0; i < 5; i++) {
				x = randomStudent();
				addhead(l, x);
			}
			break;
		}
		case 7:
		{
			deletehead(l);
			break;
		}
		case 8:
		{
			deletetail(l);
			break;
		}
		case 9:
		{
			verselist(l);
			break;
		}
		case 10:
		{
			if (iscirlist(l)) {
				cout << "\ntrue";
			}
			else {
				cout << "\nfalse";
			}
		}
		case 11:
		{
			sort(l);
			break;
		}
		case 12:
		{
			Student x;
			inputAStudent(x);
			insertnode(l, x);
			break;
		}
		case 13:
		{
			l = findH(l);
			break;
		}
		case 14:
		{
			Student x;
			inputAStudent(x);
			updatelist(l, x);
			break;
		}
		default:
			return 0;
			break;
		}
	}
	return 0;
}