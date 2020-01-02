#include "rules.h"

bool is_cell_alive_next_gen(bool currently_alive, int living_neighbors) {
    return living_neighbors == 3 || (currently_alive && living_neighbors == 2);
}