#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {};
};

class List {
private:
    struct node{
        Point* data;
        node* next;
    };
    
    node* root; // указатель на первый элемент списка

public:
    List() {
        root = NULL;
    }
    
    void print(); // done
    void printReverse(); // done
    
    int size(); // done
    bool empty(); // done
    
    void insert(Point* p); // done
    void remove(unsigned int num); // done
    
    void sort(); // done можно написать сортировку со вложенными циклами
                    // идея как с массивами, только там мы ходили счетчиками int i, j
                    // а здесь будут указатели node* i, j

};

void List::insert(Point * p) {
    
    node *newNode = new node;
    newNode->data = p;
    newNode->next = root;
    root = newNode;
}
void List::print() {
	node *tmp = root;
	int counter = 1;
	while (tmp != NULL) {
		cout << counter << ": x = " << tmp->data->x << "; y = " << tmp->data->y << endl;
		tmp = tmp->next;
		counter++;
	}
	cout << endl;
}
void List::printReverse() {
	node *tmp = root;
	int counter = 0;
	while (tmp != NULL) {
		tmp = tmp->next;
		counter++;
	}
	node **array = new node*[counter];
	tmp = root;
	for (int i = 0; i < counter; i++) {
		array[i] = tmp;
		tmp = tmp->next;
	}
	for (int i = counter-1; i >= 0; i--) {
		cout << i+1 << ": x = " << array[i]->data->x << "; y = " << array[i]->data->y << endl;
	}
	cout << endl;
	delete[] array;
}
void List::remove(unsigned int member) {
	if (empty()) {
		cout << "Error in List::remove. List is empty" << endl;
	}
		else {
		if (member == 0) {
			cout << "Failed to remove node " << member << ". Invalid value" << endl;
		}
		else {
			node *tmp = root;
			if (member == 1) {
				root = tmp->next;
				delete tmp;
			}
			else {
				int counter = 1;
				bool isPresent = true;
				while(counter < member-1) {
					tmp = tmp->next;
					counter++;
					if (tmp == NULL) {
						cout << "Failed to remove node " << member << ". No such node" << endl;
						isPresent = false;
						break;
					}
				}
				if (isPresent) {
					node *tmp2 = tmp->next;
					tmp->next = tmp->next->next;
					delete tmp2;
				}
			}
		}
	}
}
int List::size() {
	int counter = 0;
	node *tmp = root;
	while (tmp != NULL) {
		tmp = tmp->next;
		counter++;
	}
	return counter;
}
bool List::empty() {
	return root == NULL;
}

// сортировка по возрастанию х
void List::sort() {
	
	if (size() > 1) {
		
		for (int count = 0; count < size(); count++) {
		
			if (root->data->x > root->next->data->x) {
				node *tmp = root->next;
				root->next = tmp->next;
				tmp->next = root;
				root = tmp;
			}
			
			node *i = root;
			node *j = i->next;
			node *k = j->next;
	
			while (k != NULL) {
				if (j->data->x > k->data->x) {
					i->next = k;
					j->next = k->next;
					k->next = j;
					node *tmp = j;
					j = k;
					k = tmp;
				}
				i = j;
				j = k;
				k = k->next;
			}
		}
	}
}

int main(int argc, const char * argv[]) {

    List l;
    
    for (int i = 0; i < 5; i++) {
        Point* p = new Point(rand() % 10, rand() % 10);
        l.insert(p);
    }
    
    l.print();
    l.remove(1);
    l.remove(3);
    l.printReverse();
    cout << l.size() << endl;
    cout << l.empty() << endl;
    l.print();
    l.remove(2);
    l.sort();
    l.remove(10);
    l.remove(0);
    l.print();

    return 0;
}
