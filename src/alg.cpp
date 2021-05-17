// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

char a, b;

int priority(char symbol) {
  if (symbol == '(')
    return 0;
  if (symbol == ')')
    return 1;
  if (symbol == '+' || symbol == '-')
    return 2;
  if (symbol == '*' || symbol == '/')
    return 3;
  return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack <char> stack1;
  std::string res;
  for (int i = 0; i < inf.length(); i++) {
    char a = inf[i];
    if (a >= '0' && a <= '9') {
      res += a;
      res += " ";
    } else if (a == '(') {
      stack1.push(a);
    } else if (priority(a) > priority(stack1.get()) || stack1.isEmpty()) {
      stack1.push(a);
    } else if (a == ')') {
      char q = stack1.get();
      stack1.pop();
      while (q != '(') {
        res += q;
        res += " ";
        q = stack1.get();
        stack1.pop();
      }
    } else {
      while (!stack1.isEmpty() && priority(stack1.get()) >= priority(a)) {
        res += stack1.get();
        res += " ";
        stack1.pop();
      }
      stack1.push(a);
    }
  }
  while (!stack1.isEmpty()) {
    res += stack1.get();
    res += " ";
    stack1.pop();
  }
  res.erase(res.end() - 1, res.end());
  return res;
}

int eval(std::string pst) {
  TStack<int> stack2;
  for (int i = 0; i < pst.length(); i++) {
    char b = pst[i];
    if (b >= '0' && b <= '9') {
      stack2.push(b - '0');
    } else if (b != ' ') {
      int n = stack2.get();
      stack2.pop();
      int m = stack2.get();
      stack2.pop();
      if (b == '+') {
        stack2.push(n + m);
      } else if (b == '-') {
        stack2.push(m - n);
      } else if (b == '*') {
        stack2.push(n * m);
      } else {
        stack2.push(m / n);
      }
    }
  }
  return stack2.get();
}
