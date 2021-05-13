// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  TStack<char> stack;
  std::string result;
  for (int i = 0; i < inf.length(); i++) {
    a = inf[i];
    if (a >= '0' && a <= '9') {
      result += a;
      result += ' ';
    } else if (a == '(') {
      stack.push(a);
    } else if (priority(a) > priority(stack.get()) || stack.isEmpty()) {
      stack.push(a);
    } else if (a == ')') {
      while (!stack.isEmpty() && stack.get() != '(') {
        result += stack.get();
        result += ' ';
        stack.pop();
      }
      if (stack.get() == '(') {
        stack.pop();
      }
    } else {
      while (!stack.isEmpty() && priority(stack.get()) >= priority(a)) {
        result += stack.get();
        result += ' ';
        stack.pop();
      }
      stack.push(a);
    }
  }
  while (!stack.isEmpty()) {
    result += stack.get();
    result += ' ';
    stack.pop();
  }
  while (result[result.length() - 1] == ' ') {
    result = result.substr(0, result.length()-1);
  }

  return result;
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
}

int priority(char symbol) {
    int p = 0;
    if (symbol == '(')
        return 0;
    if (symbol == ')')
        return 1;
    if (symbol == '+' || a == '-')
        return 2;
    if (symbol == '*' || a == '/')
        return 3;
    return -1;
}
