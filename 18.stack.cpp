// result: ok
// spent: an hour (didn't get the point of the task at once)

#include <iostream>
#include <stack>

using namespace std;

int main () {
	
	stack <int> s;
	char *tmp = new char;
	while (cin >> *tmp) {
		int t;
		switch (*tmp) {
			case '+': t = s.top();
			s.pop();
			t += s.top();
			s.pop();
			s.push(t);
			break;
			case '-': t = 0 - s.top();
			s.pop();
			t += s.top();
			s.pop();
			s.push(t);
			break;
			case '*': t = s.top();
			s.pop();
			t *= s.top();
			s.pop();
			s.push(t);
			break;
			default: s.push(atoi(tmp));
		}
	}
	
	cout << s.top() << endl;
}
