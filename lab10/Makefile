lab10: interact.o person.o linked_list.o database.o
	gcc interact.o person.o linked_list.o database.o -o lab10

linked_list.o: linked_list.c linked_list.h person.h interact.h
	gcc -c linked_list.c

person.o: person.c linked_list.h person.h interact.h
	gcc -c person.c

interact.o: interact.c interact.h linked_list.h
	gcc -c interact.c
