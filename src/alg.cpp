// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
  // добавьте сюда нужный код
  return std::string("");
}

int eval(std::string pst) {
  // добавьте сюда нужный код
  return 0;
}

int priority(char a) {
    int p = 0;
    if (a == '(')
        p = 0;
    if (a == ')')
        p = 1;
    if (a == '+' || a == '-')
        p = 2;
    if (a == '*' || a == '/')
        p = 3;
    return p;
}
