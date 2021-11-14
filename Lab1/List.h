#include<iostream>

using namespace std;

class List {
public:
	List();
	~List();

	void push_back(int x) {
		if (isEmpty())
			head = new Num(x);
		else {
			Num* cur = head;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new Num(x);
		}
		size++;
	}

	void push_front(int x) {
		head = new Num(x, head);
		size++;
	}

	void pop_back() {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (size == 1) {	
				Num* temp = head;
				head = NULL;
				delete temp;
				size--;
			}
			else {
				Num* cur = head;
				Num* temp = head;
				while (temp->next != NULL) {
					cur = temp;
					temp = temp->next;
				}
				cur->next = NULL;
				delete temp;
				size--;
			}
		}
	}

	void pop_front() {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			Num* temp = head;
			head = temp->next;
			delete temp;
			size--;
		}
	}

	void insert(int x, size_t index) {
		if (index == 1)
			push_front(x);
		else if (index == size + 1)
			push_back(x);
		else {
			if (isEmpty())
				throw invalid_argument("Failed to execute the function 'insert'.\n");
			else {
				if (index < 1)
					throw invalid_argument("Failed to execute the function 'insert'.\n");
				else if (index > size + 1)
					throw invalid_argument("Failed to execute the function 'insert'.\n");
				else {
					Num* prev = head;
					size_t count = 1;
					while ((count < index - 1) && (prev->next != NULL)) {
						prev = prev->next;
						count++;
					}
					Num* num = new Num(x, prev->next);
					prev->next = num;
					size++;
				}
			}
		}
	}

	int at(size_t index) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index < 1) {
				throw invalid_argument("Failed to execute the function 'at'.\n");
			}
			else if (index > size)
				throw invalid_argument("Failed to execute the function 'at'.\n");
			else {
				Num* cur = head;
				size_t count = 1;
				while ((count < index) && (cur->next != NULL)) {
					cur = cur->next;
					count++;
				}
				return cur->n;
			}
		}
	}

	void remove(size_t index) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index == 1)
				pop_front();
			else if (index < 1)
				throw invalid_argument("Failed to execute the function 'remove'.\n");
			else if (index == size)
				pop_back();
			else if (index > size)
				throw invalid_argument("Failed to execute the function 'remove'.\n");
			else {
				Num* prev = head;
				size_t count = 1;
				while (count < index - 1) {
					prev = prev->next;
					count++;
				}
				Num* temp = prev->next;
				Num* cur = temp->next;
				prev->next = cur;
				delete temp;
				size--;
			}
		}
	}

	size_t get_size() {
		if (isEmpty())
			return 0;
		else {
			Num* cur = head;
			size_t count = 1;
			while (cur->next != NULL) {
				count++;
				cur = cur->next;
			}
			return count;
		}
	}

	void clear() {
		while (head != NULL)
			pop_front();
	}

	void set(size_t index, int x) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index < 1)
				throw invalid_argument("Failed to execute the function 'set'.\n");
			else if (index > size)
				throw invalid_argument("Failed to execute the function 'set'.\n");
			else {
				Num* cur = head;
				size_t count = 1;
				while ((count < index) && (cur->next != NULL)) {
					cur = cur->next;
					count++;
				}
				cur->n = x;
			}
		}
	}

	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& output, List& list)
	{
		if (list.isEmpty()) 
			output << "List is empty.";
		else {
			Num* cur = list.head;
			while (cur != NULL)
			{
				output << cur->n << (cur->next == NULL ? "" : ", ");
				cur = cur->next;
			}
		}
		return output;
	}

	bool contains(List& list2) {
		if ((isEmpty()) || (list2.isEmpty()))
			throw logic_error("List is empty.");
		else {
			Num* cur = head;
			Num* cur2 = list2.head;
			int count = 0;
			while (1) {
				if (cur2->n == cur->n) {
					cur = cur->next;
					cur2 = cur2->next;
					count++;
					if (count == list2.size) {
						return true;
						break;
					}
				}
				else {
					if (cur->next == NULL || cur2->next == NULL) {
						return false;
						break;
					}
					else {
						cur = cur->next;
						cur2 = list2.head;
						count = 0;
					}
				}
			}
		}
	}

private:
	class Num {
	public:
		int n;
		Num* next;

		Num(int n = int(), Num* next = NULL) {
			this->n = n;
			this->next = next;
		}
	};
	size_t size;
	Num* head;
};

List::List() {
	size = 0;
	head = NULL;
}

List::~List() {
	clear();
}