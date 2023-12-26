#ifndef SEM_ERRORS
#define SEM_ERRORS

#include <stdio.h>
#include <stdlib.h>

/*
Arguments
value -> value returned by semUp() or semDown functions
op -> semaphore operation:
0 if up
1 if down
ent -> identify entity:
0 if chef
1 if group
2 if waiter
3 if receptionist
*/
void verifySemError(int value, int op, int ent) {
    const char *entities[] = {"Chef", "Group", "Waiter", "Receptionist"};
    const char *operations[] = {"up", "down"};

    if (op < 0 || op > 1 || ent < 0 || ent > 3) {
        perror("Error using verifySemError function (check access handle_semaphore_access.h for more information)");
        exit(EXIT_FAILURE);
    }

    if (value == -1) {
        fprintf(stderr, "Error on the %s operation for semaphore access (%s)\n", operations[op], entities[ent]);
        perror("Semaphore operation error");
        exit(EXIT_FAILURE);
    }
}

#endif
