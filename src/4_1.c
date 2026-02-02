#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"


static bool is_balanced(char * str);


static bool
is_balanced(char * str) {
	struct stk_astack * stack = NULL;
	if (! stk_anew(&stack)) {
		return false;
	}

	bool is_ok = false;
	int pop = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		switch (str[i]) {
			case '(':
				stk_apush(stack, str[i]);
				break;
			case '[':
				stk_apush(stack, str[i]);
				break;
			case '{':
				stk_apush(stack, str[i]);
				break;
			case ')':
				if (stk_ais_empty(stack)) {
					goto CLEAN_UP;
				}
				stk_apop(stack, &pop);
				if (pop != '(') {
					goto CLEAN_UP;
				}
				break;
			case ']':
				if (stk_ais_empty(stack)) {
					goto CLEAN_UP;
				}
				stk_apop(stack, &pop);
				if (pop != '[') {
					goto CLEAN_UP;
				}
				break;
			case '}':
				if (stk_ais_empty(stack)) {
					goto CLEAN_UP;
				}
				stk_apop(stack, &pop);
				if (pop != '{') {
					goto CLEAN_UP;
				}
				break;
		}
	}

	is_ok = stk_ais_empty(stack);
CLEAN_UP:
	stk_afree(&stack);
	if (is_ok) {
		PRINT_LOG("[%s] is balanced.", str);
	} else {
		PRINT_LOG("[%s] is not balanced.", str);
	}
	return is_ok;
}


int
main(void) {
	char test1[] = "() {() [()]}";
	char test2[] = "() {() ([)]}";
	bool is_ok = false;

	is_ok = is_balanced(test1);
	assert(is_ok == true);
	is_ok = is_balanced(test2);
	assert(is_ok == false);

	PRINT_LOG("Passed.");
	exit(EXIT_SUCCESS);
}
