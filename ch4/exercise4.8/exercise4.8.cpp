The logical AND and OR operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as short-circuit evaluation:
- The right side of an && is evaluated if and only if the left side is true.
- The right side of an || is evaluated if and only if the left side is false.

In C++, the order of evaluation of the operands of an equality operator is undefined.
