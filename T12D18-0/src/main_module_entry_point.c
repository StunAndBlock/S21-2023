#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef PRINT
    print_log(print_char, Module_load_success_message);
#endif
#ifdef CHECK
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output(availability_mask, Documents_count, Documents);
    free(availability_mask);
#endif
    return 0;
}