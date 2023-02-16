#include "parse.h"

// Вводим массив символов, без пробелов, максимальная длина выражения - 200 символов
char* input_arr(void) {
    char* input = malloc(sizeof(char) * 200);
    scanf("%199s", input);  // %199s нужен для того, чтобы максимум вбивали 200 символов
    return input;
}

// Функция возвращает "силу" оператора
int precedence(char op) {
    int result = -1;
    if (op == '+' || op == '-') {
        result = 1;
    } else if (op == '*' || op == '/') {
        result = 2;
    } else if (op == 's' || op == 'c' || op == 't' || op == 'g' || op == 'q' || op == 'n') {
        result = 3;
    }
    return result;
}

// Проверка на базовые операторы
int is_op(char ch) { return (ch == '+' || ch == '-' || ch == '*' || ch == '/'); }

// Проверка на функции, очень тупо и банально сделано, но работу выполняет
// result принимает значение для того, чтобы не делать 6 функций для каждой функции (тавтология)
int is_func(const char* input, int i) {
    int result = 0;
    if (strstr(input, "sin") == input + i) {
        result = 1;
    } else if (strstr(input, "cos") == input + i) {
        result = 2;
    } else if (strstr(input, "tan") == input + i) {
        result = 3;
    } else if (strstr(input, "ctg") == input + i) {
        result = 4;
    } else if (strstr(input, "sqrt") == input + i) {
        result = 5;
    } else if (strstr(input, "ln") == input + i) {
        result = 6;
    }
    return result;
}

// Основной метод конверции infix -> postfix, aka Reverse Polish Notation
char* convert(char* input, int len) {
    int error = 0;
    char* result = malloc((len + 2) * sizeof(char));
    char stack[200];  // Основной стек, для знаков
    int top = -1;  // Позиция относительно "головы" стека. -1 значит, что в стеке пусто
    int i, j;
    int check = 0;  // Переменная для проверки, особо полезна в случаях, когда число > 10
    for (i = 0, j = 0; i < len; i++) {
        if (!error) {
        // Изначальная проверка что вводится число
        if (((int)input[i] >= 48 && (int)input[i] <= 57) || (input[i] == 'x')) {
            // Цикл для того, чтобы вводить большие и дроные числа
            while (((int)input[i] >= 48 && (int)input[i] <= 57) || input[i] == '.' || (input[i] == 'x')) {
                result[j++] = input[i];
                check = 1;
                i++;
            }
            i--;
            // Если попадется скобка, то мы записываем все знаки после нее в стек, как обычно
            // А когда будет ), то выкидываем все знаки из стека
        } else if (input[i] == '(')
            push_op(stack, &top, input[i]);
        else if (input[i] == ')') {
            while (top > -1 && stack[top] != '(') {
                result[j++] = pop_op(stack, &top);
                result[j++] = ' ';
            }
            if (top > -1 && stack[top] != '(') {
                printf("\nInvalid expression, exiting...\n\n");
                error = 1;;  // !!!!!ИСПРАВИТЬ!!!!! Такая шняга приравнивается к return, надо создавать мусорную
                          // переменную
            } else
                top--;
            // Обычный скан операторов
        } else if (is_op(input[i]) || is_func(input, i)) {
            push_ops(input, &i, &j, result, &top, stack);
        } else {
            printf("\nInvalid expression, exiting...\n\n");
            error = 1;  // !!!!!ИСПРАВИТЬ!!!!! То же, что 2 строчки выше
        }
        // Это для разделения цифр пробелом
        if (check && !error) {
            result[j++] = ' ';
            check = 0;
        }
    }
    }
    // В конце мы просто вытаскиваем все, что осталось в стеке знаков
    if (!error) {
        while (top > -1) {
            result[j++] = pop_op(stack, &top);
            result[j++] = ' ';
        }
        // Так как это строка, то в конце должен быть нулевой символ
        result[j] = '\0';
    }
    return result;
}


// Функция для декомпозиции функции сверху
// Занимается распределением операторов в стек и итоговый массив
void push_ops(char* input, int* i, int* j, char* result, int* top, char* stack) {
    int func = is_func(input, *i);
    // Если у нас сейчас не функция, и оператор в стеке сильнее оператора с инпута
    // То мы выплевываем все операторы, пока соблюдается такое условие
    while (!func && *top > -1 && precedence(stack[*top]) >= precedence(input[*i])) {
        result[*j] = pop_op(stack, top);
        *j = *j + 1;
        result[*j] = ' ';
        *j = *j + 1;
    }
    // Иначе просто пушим в стек оператор
    if (!func) push_op(stack, top, input[*i]);
    // Меняем многобуквенное обозначение на однобуквенное и пушим в стек знаков
    // s = sin; c = cos; t = tan; g = ctg; q = sqrt; n = ln
    else if (func == 1) {
        push_op(stack, top, 's');
        *i = *i + 2;
    } else if (func == 2) {
        push_op(stack, top, 'c');
        *i = *i + 2;
    } else if (func == 3) {
        push_op(stack, top, 't');
        *i = *i + 2;
    } else if (func == 4) {
        push_op(stack, top, 'g');
        *i = *i + 2;
    } else if (func == 5) {
        push_op(stack, top, 'q');
        *i = *i + 3;
    } else if (func == 6) {
        push_op(stack, top, 'n');
        *i = *i + 1;
    }
}
