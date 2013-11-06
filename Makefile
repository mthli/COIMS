FWD : main_window.o menu_bar_help_callback.o
	gcc -o FWD main_window.o menu_bar_help_callback.o `pkg-config --cflags --libs gtk+-2.0`
main_window.o : main_window.c
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
menu_bar_help_callback.o : menu_bar_help_callback.c
	gcc -c menu_bar_help_callback.c `pkg-config --cflags --libs gtk+-2.0`

clean :
	rm FWD main_window.o menu_bar_help_callback.o
