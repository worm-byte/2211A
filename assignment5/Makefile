assign5: interact.o linked_list.o main.o reminder.o
	gcc interact.o linked_list.o main.o reminder.o -o assign5

linked_list.o: linked_list.c linked_list.h reminder.h
	gcc -c linked_list.c

interact.o: interact.c interact.h reminder.h linked_list.h
	gcc -c interact.c

reminder.o: reminder.c reminder.h linked_list.h interact.h
	gcc -c reminder.c

