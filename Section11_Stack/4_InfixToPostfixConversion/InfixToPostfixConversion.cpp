/***
 * Infix: Operand operator Operand
 *  eg: a + b
 * Prefix: operator Operand Operand
 *  eg: +ab
 * Postfix: Operand Operand operator
 *  eg: ab+
 * 
 * 
 * Symbol   | Precedence
 *  +,-     |   1
 *  *, /    |   2
 *  ()      |   3
 * 
 * 1: a + b * c
 * 2: a + b + c * d
 * -> Whenever write an expression, actually should make it fully parenthesized, fully parenthesized, cannot should not write an expression without parenthesis.
 * Parenthesis are not given. Actually compiler needs fully parenthesized expression. Everything should be parenthesized. No operator should be left open. Then when they're not parenthesized, them compiler will parenthesize it, not physically, logically, it'll parenthesize it. -> How? Using Precedence
 * Precedence doesn't mean order of execution. 
 * That is having higher precedence means first put that one inside the bracket. 
 * First you parenthesize that one, then you parenthesize additions and subtractions. That is the meaning of precedence. So precedences as well as associativities are meant for parenthesization.
 * So let do parenthesization and then convert infix to prefix and postfix. 
 * 
 * a + b * c
 * Parenthesize:  a + (b * c) -> (a + (b * c)) 
 * -> prefix (a + [*bc]) -> + a *bc
 * -> postfix (a + [bc*]) -> abc*+
 * 
 * infix: operator is in between.
 * postfix: operator is at the end. 
 * prefix: operator is in front. 
 * 
 * a + b + c * d
 * -> prefix: a + b + *[cd] -> + [ab] + *[cd] -> ++ab*cd
 * -> postfix: a + b + [cd*] -> [ab+] + [cd*] -> ab+cd*+
 * 
 * (a + b) * (c - d)
 * -> prefix: [+ab] * (c-d) -> [+ab] * [-cd] -> *+ab-cd
 * -> postfix: [ab+] * (c - d) -> [ab+] * [cd-] -> ab+cd-*
 * ***/