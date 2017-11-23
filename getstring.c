int GetResult(char* str,int size)
{
    ParsRes result = ParsingMathExpr(str,size);
    switch (result){
        case PARS_BAD_SYM:
            printf("В выражении находятся недопустимые символы.\n");
            return INCORRECT_RES;
        case PARS_BRACK:
            printf("Неверная вложенность скобок.\n");
            return INCORRECT_RES;
        case PARS_INCORRECT:
            printf("Выражение составлено не верно!\n");
            return INCORRECT_RES;
        case PARS_NO_OPERANDS:
            printf("Вы выражении отсуствуют числа!\n");
            return INCORRECT_RES;
        default: printf("Выражение составлено верно!:)\n");
    }
    PNode root = MakeTreeSyntaxParsing(str,0,size);
    int res_expr = CalculationTree(root);
    DestroyTree(root);
    return res_expr;
}
