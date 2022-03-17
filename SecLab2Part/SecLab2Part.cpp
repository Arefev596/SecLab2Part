#include <iostream>
using namespace std;

int sizeStack = 0;
const int N = 3;

class Stack {
public:
	int Items[N];
	int Up;
};

typedef struct Stack st;

void InitStack(st* s) {
	s->Up = -1;
}

int IsFullStack(st* s) {
	if (s->Up == N - 1)
		return 1;
	else
		return 0;
}

void PushStack(st* s, int newitem) {
	if (IsFullStack(s)) {
		printf("Стек заполнен");
	}
	else {
		s->Up++;
		s->Items[s->Up] = newitem;
	}
	sizeStack++;
}

void FindStack(st* s, int findItem) {
	bool YesOrNo = 0;
	for (int i = 0; i < N; i++)
	{
		if (s->Items[i] == findItem) {
			cout << "\nНужный элемент " << findItem << " найден!\n";
			cout << "Для этого понадобилось " << i+1 << " операций";
			YesOrNo = true;
			break;
		}
	}
	if (YesOrNo == false) {
		cout << "Нужного элемента не найдено :(\n";
	}
}

void PrintStack(st* s) {
	cout << "Наши элементы стека: \n";
	for (int i = 0; i < N; i++) {
		cout << i << " "<< s->Items[i] << "\n";
	}
	cout << endl;
}
////////////////////////////////////////////////
class Queue { //FIFO
private:
	int items[N], first, last;

public:
	Queue() {
		first = -1;
		last = -1;
	}

	bool isFull() {
		if (first == 0 && last == N - 1) {
			return true;
		}
		return false;
	}

	bool isEmpty() {
		if (first == -1)
			return true;
		else
			return false;
	}

	void enQueue(int element) {
		if (isFull()) {
			cout << "Очередь заполнена!";
		}
		else {
			if (first == -1) {
				first = 0;
			}
			last++;
			items[last] = element;
		}
	}

	int deQueue() {
		if (isEmpty()) {
			cout << "Очередь пуста!\n";
			return (-1);
		}
		else {
			int element = items[first];
			if (first >= last) {
				first = -1;
				last = -1;
			} /* Внутри Q только один элемент, поэтому очередь сбрасывается
			  в начальное состояние после удаления последнего элемента */
			else {
				first++;
			}
			cout << endl
				<< "Удален элемент: " << element << endl;
			return (element);
		}
	}

	void PrintQueue() {
		cout << "Наши элементы очереди: ";
		for (int i = first; i <= last; i++) {
			cout << i <<" " << items[i] << " \n ";
		}
	}

	void FindQueue(int whatfind) {
		bool YesOrNo = 0;
		for (int i = first; i <= last; i++) {
			if (items[i] == whatfind) {
				cout << "\nНужный элемент " << whatfind << " найден!\n";
				YesOrNo = true;
				cout << "Для этого понадобилось " << i+1 << " операций";
				break;
			}
		}
		if (YesOrNo == false) {
			cout << "Нужного элемента не найдено :(\n";
		}
	}
};



int main() {
	setlocale(LC_ALL, "rus");
	int elem;
	cout << "Какой элемент хотите искать? \n";
	cin >> elem;
	cout << "1.Стек\n2.Массив\n3.Очередь\n";
	int whale;
	cin >> whale;

	if (whale == 1) {
		int number;
		st* s = (st*)malloc(sizeof(st)); //выделяем динамическую память

		InitStack(s);

		cout << "Введите элементы стека: \n";
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			PushStack(s, number);
		}

		PrintStack(s);

		FindStack(s, elem);

	}

	else if (whale == 2) {
		int mas[N];
		cout << "Введите элементы массива: \n";
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			mas[i] = a;
		}
		cout << "Наши элементы массива: \n";
		for (int i = N - 1; i > -1; i--)
		{
			cout << i << " " << mas[i] << "\n ";
		}

		for (int i = 0; i < N; i++)
		{
			if (mas[i] = elem) {
				cout << "\nНужный элемент " << elem << " найден!\n";
				cout << "Для этого понадобилось " << i+1 << " операций";
				break;
			}
			else {
				cout << "Нужного элемента нет!";
				break;
			}

		}
	}
	else {
		Queue q;
		int number;
		cout << "Введите элементы очереди: \n";
		for (int i = 0; i < N; i++)
		{
			cin >> number;
			q.enQueue(number);
		}
		q.PrintQueue();
		q.FindQueue(elem);

	}

	return 0;
