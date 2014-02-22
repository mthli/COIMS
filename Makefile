COIMS: main_window.o \
	help_about.o \
	new_person.o \
	cancel.o \
	photo_choose.o \
	birthday_choose.o \
	happened_choose.o \
	into_choose.o \
	out_choose.o \
	panss.o
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
		`pkg-config --cflags --libs gtk+-2.0`

main_window.o: main_window.c coims.h
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
help_about.o: help_about.c coims.h
	gcc -c help_about.c `pkg-config --cflags --libs gtk+-2.0`
new_person.o: new_person.c coims.h
	gcc -c new_person.c `pkg-config --cflags --libs gtk+-2.0`
cancel.o: cancel.c coims.h
	gcc -c cancel.c `pkg-config --cflags --libs gtk+-2.0`
photo_choose.o: photo_choose.c coims.h
	gcc -c photo_choose.c `pkg-config --cflags --libs gtk+-2.0`
birthday_choose.o: birthday_choose.c coims.h
	gcc -c birthday_choose.c `pkg-config --cflags --libs gtk+-2.0`
happened_choose.o: happened_choose.c coims.h
	gcc -c happened_choose.c `pkg-config --cflags --libs gtk+-2.0`
into_choose.o: into_choose.c coims.h
	gcc -c into_choose.c `pkg-config --cflags --libs gtk+-2.0`
out_choose.o: out_choose.c coims.h
	gcc -c out_choose.c `pkg-config --cflags --libs gtk+-2.0`
panss.o: panss.c coims.h
	gcc -c panss.c `pkg-config --cflags --libs gtk+-2.0`

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
		panss.o
