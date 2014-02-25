COIMS: main_window.o \
	help_about.o \
	new_person.o \
	cancel.o \
	photo_choose.o \
	birthday_choose.o \
	happened_choose.o \
	into_choose.o \
	out_choose.o \
	panss.o \
	check_sure.o \
	get_row_and_column.o \
	search_hsp.o \
	insert_hsp.o \
	update_hsp.o
	gcc -o COIMS \
		main_window.o \
		help_about.o \
		new_person.o \
		cancel.o \
		photo_choose.o \
		birthday_choose.o \
		happened_choose.o \
		into_choose.o \
		out_choose.o \
		panss.o \
		check_sure.o \
		get_row_and_column.o \
		search_hsp.o \
		insert_hsp.o \
		update_hsp.o \
		`pkg-config --cflags --libs gtk+-2.0` -l sqlite3

main_window.o: main_window.c coims.h
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

help_about.o: help_about.c coims.h
	gcc -c help_about.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

new_person.o: new_person.c coims.h
	gcc -c new_person.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

cancel.o: cancel.c coims.h
	gcc -c cancel.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

photo_choose.o: photo_choose.c coims.h
	gcc -c photo_choose.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

birthday_choose.o: birthday_choose.c coims.h
	gcc -c birthday_choose.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

happened_choose.o: happened_choose.c coims.h
	gcc -c happened_choose.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

into_choose.o: into_choose.c coims.h
	gcc -c into_choose.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

out_choose.o: out_choose.c coims.h
	gcc -c out_choose.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

panss.o: panss.c coims.h
	gcc -c panss.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

check_sure.o: check_sure.c coims.h
	gcc -c check_sure.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

get_row_and_column.o: get_row_and_column.c coims.h
	gcc -c get_row_and_column.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

search_hsp.o: search_hsp.c coims.h
	gcc -c search_hsp.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

insert_hsp.o: insert_hsp.c coims.h
	gcc -c insert_hsp.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3

update_hsp.o: update_hsp.c coims.h
	gcc -c update_hsp.c `pkg-config --cflags --libs gtk+-2.0` -l sqlite3


clean:
	rm main_window.o \
		help_about.o \
		new_person.o \
		cancel.o \
		photo_choose.o \
		birthday_choose.o \
		happened_choose.o \
		into_choose.o \
		out_choose.o \
		panss.o \
		check_sure.o \
		get_row_and_column.o \
		search_hsp.o \
		insert_hsp.o \
		update_hsp.o
