/****
 * [Associativity And Unary Operators]
 * 
 * Syb      |   Pre     |   Asso
 * +,-      |   1       |   L-R
 * *,/      |   2       |   L-R
 * ^        |   3       |   R-L
 * -        |   4       |   R-L
 * ()       |   5       |   L-R
 * 
 * 
 * a + b + c - d
 * Have more than one operators having same precedents. 
 * -> (((a+b)+c)-d) -> left to right -> ab+c+d-
 * 
 * (a=(b=(c=5))) -> right to left -> abc===
 * 
 * 
 * a^b^c -> (a^(b^c))
 *      -> a^[bc^] -> abc^^
 * 
 * 
 * - a + b *logn! 
 * -> - a b * long[n!]
 * -> -a + b * [n!log]
 * -> [a-] + b * [n!log]
 * -> [a-] + [bn!log]
 * -> a-bn!log+
 * ***/