#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {};
};

bool comparePoints (Point *a, Point *b) {
	if (a->x == a->y) {
		return a->y < b->y;
	}
	return a->x < b->x;
}

void pPrint (Point *p) {
	cout << "x = " << p->x << "; y = " << p->y << endl;
}

class List {
private:
    struct node{
        Point* data;
        node* next;
    };
    
    node* root; // указатель на первый элемент списка
    void printReverse (node * aNode, int counter);

public:
    List() {
        root = NULL;
    }
    
    void print(); // done
    void printReverse(); // done
    
    int size(); // done
    bool empty(); // done
    
    void insert(Point* p); // done
    void remove(int num); // done
    
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
	int counter = 0;
	while (tmp != NULL) {
		cout << counter << ": "; pPrint(tmp->data);
		tmp = tmp->next;
		counter++;
	}
	cout << endl;
}
void List::printReverse() {
	printReverse(root, 0);
}
void List::printReverse(node *aNode, int counter) {
	if(aNode->next != NULL) {
		printReverse(aNode->next, counter + 1);
	}
	cout << counter << ": "; pPrint(aNode->data);
}
void List::remove(int member) {
	if (empty()) {
		cout << "Error in List::remove. List is empty" << endl;
		return;
	}
	if (member < 0) {
		cout << "Failed to remove node " << member << ". Invalid value" << endl;
		return;
	}

	node *tmp = root;
	if (member == 0) {
		root = tmp->next;
		delete tmp;
	}
	else {
		bool isPresent = true;
		for (int counter = 1; counter < member - 1; counter++) {
			tmp = tmp->next;
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

void List::sort() {
	
	int s = size();
	
	if (s > 1) {
		
		for (int count = 0; count < s; count++) {
		
			if (!comparePoints(root->data, root->next->data)) {
				node *tmp = root->next;
				root->next = tmp->next;
				tmp->next = root;
				root = tmp;
			}
			
			node *i = root;
			node *j = i->next;
			node *k = j->next;
	
			while (k != NULL) {
				if (!comparePoints(j->data, k->data)) {
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
    l.remove(0);
    l.remove(10);
    l.print();
   

    return 0;
}
