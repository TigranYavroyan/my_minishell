#include "./includes/set.h"

#include <stdio.h>

int main () {
	t_set_ptr set = init_set();

	insert_set(set, make_node("asdfasdf"));
	insert_set(set, make_node("afdasdfads1"));
	
}