// Q1 MENU DRIVEN

#include <iostream>
using namespace std;

#define MAX 100
class Stack {
    int arr[MAX], top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) {
        if (isFull()) cout << "Overflow\n";
        else arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) { cout << "Underflow\n"; return -1; }
        else return arr[top--];
    }
    int peek() {
        if (isEmpty()) { cout << "No element\n"; return -1; }
        else return arr[top];
    }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s; int ch, x;
    while (1) {
        cout << "1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> x; s.push(x); }
        else if (ch == 2) cout << s.pop() << endl;
        else if (ch == 3) cout << s.isEmpty() << endl;
        else if (ch == 4) cout << s.isFull() << endl;
        else if (ch == 5) s.display();
        else if (ch == 6) cout << s.peek() << endl;
        else if (ch == 7) break;
    }
    return 0;
}

// Q2 STRING REVERSE

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX]; int top;
public:
    Stack() { top = -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int main() {
    char str[MAX]; cin >> str;
    Stack s;
    for (int i = 0; str[i]; i++) s.push(str[i]);
    while (!s.isEmpty()) cout << s.pop();
    cout << endl;
    return 0;
}

// Q3 CHECK BALANCED PARAENTHSIS

#include <iostream>
using namespace std;

bool isBalanced(string expr) {
    int n = expr.length(), top = -1;
    char stack[n];
    for (char ch : expr) {
        if (ch=='('||ch=='{'||ch=='[') stack[++top] = ch;
        else if (ch==')'||ch=='}'||ch==']') {
            if (top==-1) return false;
            char last = stack[top--];
            if ((ch==')' && last!='(') ||
                (ch=='}' && last!='{') ||
                (ch==']' && last!='[')) return false;
        }
    }
    return top==-1;
}

int main() {
    string s; cin >> s;
    cout << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
}

// Q4 INFIX TO POSTFIX
#include <iostream>
#include <string>
using namespace std;

int precedence(char op) {
    if (op=='^') return 3;
    if (op=='*'||op=='/') return 2;
    if (op=='+'||op=='-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    string res; char stack[s.length()]; int top = -1;
    for (char ch : s) {
        if (isalnum(ch)) res += ch;
        else if (ch=='(') stack[++top] = ch;
        else if (ch==')') {
            while (top>-1 && stack[top]!='(') res += stack[top--];
            top--;
        }
        else {
            while (top>-1 && precedence(stack[top]) >= precedence(ch))
                res += stack[top--];
            stack[++top] = ch;
        }
    }
    while (top>-1) res += stack[top--];
    return res;
}

int main() {
    string s; cin >> s;
    cout << infixToPostfix(s) << endl;
}

//Q5 EVALUATION OF POSTFIX EXPRESSION
#include <iostream>
#include <cctype>
using namespace std;

int evalPostfix(string expr) {
    int stack[100], top=-1;
    for (char ch : expr) {
        if (isdigit(ch)) stack[++top]=ch-'0';
        else {
            int b=stack[top--], a=stack[top--];
            if(ch=='+') stack[++top]=a+b;
            if(ch=='-') stack[++top]=a-b;
            if(ch=='*') stack[++top]=a*b;
            if(ch=='/') stack[++top]=a/b;
        }
    }
    return stack[top];
}

int main() {
    string expr; cin >> expr;
    cout << evalPostfix(expr) << endl;
}


