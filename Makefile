FWD : main_window.o window_menubar_help_callback.o window_notebook_treat_button_medicine_callback.o
	gcc -o FWD main_window.o window_menubar_help_callback.o window_notebook_treat_button_medicine_callback.o `pkg-config --cflags --libs gtk+-2.0`
main_window.o : main_window.c
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
window_menubar_help_callback.o : window_menubar_help_callback.c
	gcc -c window_menubar_help_callback.c `pkg-config --cflags --libs gtk+-2.0`
window_notebook_treat_button_medicine_callback.o :
	gcc -c window_notebook_treat_button_medicine_callback.c `pkg-config --cflags --libs gtk+-2.0`

clean :
	rm FWD main_window.o window_menubar_help_callback.o window_notebook_treat_button_medicine_callback.o
