import sys


class Operator(object):
    def __init__(self, symbol):
        self.symbol = symbol
        self.priority = {'+': 1,
                         '-': 1,
                         '*': 2,
                         '/': 2,
                         '%': 2,
                         '**': 3}[symbol]
        self.associativity = {'+': 'l',
                              '-': 'l',
                              '*': 'l',
                              '/': 'l',
                              '%': 'l',
                              '**': 'r'}[symbol]

    def __call__(self, first_operand, second_operand):
        if self.symbol == '/':
            return first_operand / second_operand
        elif self.symbol == '*':
            return first_operand * second_operand
        elif self.symbol == '-':
            return first_operand - second_operand
        elif self.symbol == '+':
            return first_operand + second_operand
        elif self.symbol == '**':
            return first_operand ** second_operand

    def __str__(self):
        return self.symbol


class Stack(object):

    def __init__(self):
        self.stack = []

    def __str__(self):
        return str(self.stack)

    def empty(self):
        if len(self.stack) > 0:
            return 0
        else:
            return 1

    def top(self):
        if not self.empty():
            return self.stack[-1]
        else:
            return "Stack is Empty!"

    def push(self, value):
        self.stack.append(value)
        return value

    def pop(self):
        if not self.empty():
            top = self.top()
            self.stack = self.stack[:-1]
            return top
        else:
            return "Stack is Empty!"


def isoperator(symbol):
    if symbol in ['+', '-', '*', '/', '**']:
        return True
    else:
        return False


class RPN(object):
    def __init__(self, expression):
        self.rpn = []
        stack = Stack()
        for symbol in expression.split():
            if symbol.isdigit():
                self.rpn.append(symbol)
            if not isoperator(symbol) and symbol.startswith('-'):
                self.rpn.append('!' + symbol[1:])
            if '.' in symbol:
                self.rpn.append(symbol)
            elif isoperator(symbol):
                operator = Operator(symbol)
                while (not stack.empty() and
                       isinstance(stack.top(), Operator) and
                       (operator.associativity == 'l' and
                        operator.priority <= stack.top().priority or
                        operator.associativity == 'r' and
                        operator.priority < stack.top().priority)):
                    self.rpn.append(stack.pop())
                stack.push(operator)
            elif symbol == '(':
                stack.push(symbol)
            elif symbol == ')':
                while not stack.empty() and stack.top() != '(':
                    self.rpn.append(stack.pop())
                if stack.top() == '(':
                    stack.pop()
                else:
                    print 'Incorrect expression!'
        while not stack.empty():
            self.rpn.append(stack.pop())

    def __str__(self):
        return ''.join([str(x) for x in self.rpn])

    def calc(self):
        stack = Stack()
        for symbol in self.rpn:
            if isinstance(symbol, Operator):
                b = stack.pop()
                a = stack.pop()
                stack.push(symbol(float(a), float(b)))
            elif symbol.isdigit():
                stack.push(symbol)
            elif symbol.startswith('!'):
                stack.push('-' + symbol[1:])
            elif '.' in symbol:
                stack.push(symbol)
        if stack.top() == int(stack.top()):
            return int(stack.pop())
        else:
            return stack.pop()

expression = sys.stdin.readline()
rpn = RPN(expression)
print rpn.calc()
