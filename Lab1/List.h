#include<iostream>

using namespace std;

class List {
public:
	List();
	~List();

	void push_back(int x) {
		if (isEmpty())
			head = new List_Element(x);
		else {
			List_Element* current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = new List_Element(x);
		}
		size++;
	}

	void push_front(int x) {
		head = new List_Element(x, head);
		size++;
	}

	void pop_back() {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (size == 1) {	
				List_Element* temporary = head;
				head = NULL;
				delete temporary;
				size--;
			}
			else {
				List_Element* current = head;
				List_Element* temporary = head;
				while (temporary->next != NULL) {
					current = temporary;
					temporary = temporary->next;
				}
				current->next = NULL;
				delete temporary;
				size--;
			}
		}
	}

	void pop_front() {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			List_Element* temporary = head;
			head = temporary->next;
			delete temporary;
			size--;
		}
	}

	void insert(int x, size_t index) {
		if (index == 0)
			push_front(x);
		else if (index == size)
			push_back(x);
		else {
			if (isEmpty())
				throw invalid_argument("Failed to execute the function 'insert'.\n");
			else {
				if (index < 0)
					throw invalid_argument("Failed to execute the function 'insert'.\n");
				else if (index > size)
					throw invalid_argument("Failed to execute the function 'insert'.\n");
				else {
					List_Element* current = head;
					size_t count = 0;
					while ((count < index - 1) && (current->next != NULL)) {
						current = current->next;
						count++;
					}
					List_Element* element = new List_Element(x, current->next);
					current->next = element;
					size++;
				}
			}
		}
	}

	int at(size_t index) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index < 0) {
				throw invalid_argument("Failed to execute the function 'at'.\n");
			}
			else if (index > size - 1)
				throw invalid_argument("Failed to execute the function 'at'.\n");
			else {
				List_Element* current = head;
				size_t count = 0;
				while ((count < index) && (current->next != NULL)) {
					current = current->next;
					count++;
				}
				return current->n;
			}
		}
	}

	void remove(size_t index) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index == 0)
				pop_front();
			else if (index < 0)
				throw invalid_argument("Failed to execute the function 'remove'.\n");
			else if (index == size - 1)
				pop_back();
			else if (index > size - 1)
				throw invalid_argument("Failed to execute the function 'remove'.\n");
			else {
				List_Element* previous = head;
				size_t count = 0;
				while (count < index - 1) {
					previous = previous->next;
					count++;
				}
				List_Element* temporary = previous->next;
				List_Element* current = temporary->next;
				previous->next = current;
				delete temporary;
				size--;
			}
		}
	}

	size_t get_size() {
		return size;
	}

	void clear() {
		while (head != NULL)
			pop_front();
	}

	void set(size_t index, int x) {
		if (isEmpty())
			throw logic_error("List is empty.");
		else {
			if (index < 0)
				throw invalid_argument("Failed to execute the function 'set'.\n");
			else if (index > size - 1)
				throw invalid_argument("Failed to execute the function 'set'.\n");
			else {
				List_Element* current = head;
				size_t count = 0;
				while ((count < index) && (current->next != NULL)) {
					current = current->next;
					count++;
				}
				current->n = x;
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
			List_Element* current = list.head;
			while (current != NULL)
			{
				output << current->n << (current->next == NULL ? "" : ", ");
				current = current->next;
			}
		}
		return output;
	}

	bool contains(List& list2) {
		if ((isEmpty()) || (list2.isEmpty()))
			throw logic_error("List is empty.");
		else {
			List_Element* current = head;
			List_Element* current2 = list2.head;
			size_t index = 0, index2 = 0;
			bool check = 0;
			int count = 0;
			while (index < size && index2 < list2.get_size()) {
				if (current2->n == current->n) {
					count++;
					current = current->next;
					current2 = current2->next;
					index++;
					index2++;
					if (count == list2.size) {
						check = 1;
						break;
					}
				}
				else {
					current = current->next;
					index++;
					current2 = list2.head;
					index2 = 0;
					count = 0;
				}
			}
			return check;
		}
	}

private:
	class List_Element {
	public:
		int n;
		List_Element* next;

		List_Element(int n = int(), List_Element* next = NULL) {
			this->n = n;
			this->next = next;
		}
	};
	size_t size;
	List_Element* head;
};

List::List() {
	size = 0;
	head = NULL;
}

List::~List() {
	clear();
}