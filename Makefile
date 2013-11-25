FWD : main_window.o \
	window_menubar_help_about_callback.o \
	window_button_new_callback.o \
	window_button_query_callback.o \
	dialog_button_new_diagnose_callback.o \
	dialog_button_query_person_diagnose_callback.o \
	dialog_button_query_treat_diagnose_callback.o \
	dialog_button_query_treat_medicine_callback.o
	gcc -o FWD \
		main_window.o \
		window_menubar_help_about_callback.o \
		window_button_new_callback.o \
		window_button_query_callback.o \
		dialog_button_new_diagnose_callback.o \
		dialog_button_query_person_diagnose_callback.o \
		dialog_button_query_treat_diagnose_callback.o \
		dialog_button_query_treat_medicine_callback.o \
		`pkg-config --cflags --libs gtk+-2.0`
main_window.o : main_window.c
	gcc -c main_window.c `pkg-config --cflags --libs gtk+-2.0`
window_menubar_help_about_callback.o : window_menubar_help_about_callback.c
	gcc -c window_menubar_help_about_callback.c `pkg-config --cflags --libs gtk+-2.0`
window_button_new_callback.o : window_button_new_callback.c
	gcc -c window_button_new_callback.c `pkg-config --cflags --libs gtk+-2.0`
window_button_query_callback.o : window_button_query_callback.c
	gcc -c window_button_query_callback.c `pkg-config --cflags --libs gtk+-2.0`
dialog_button_new_diagnose_callback.o : dialog_button_new_diagnose_callback.c
	gcc -c dialog_button_new_diagnose_callback.c `pkg-config --cflags --libs gtk+-2.0`
dialog_button_query_person_diagnose_callback.o : dialog_button_query_person_diagnose_callback.c
	gcc -c dialog_button_query_person_diagnose_callback.c `pkg-config --cflags --libs gtk+-2.0`
dialog_button_query_treat_diagnose_callback.o : dialog_button_query_treat_diagnose_callback.c
	gcc -c dialog_button_query_treat_diagnose_callback.c `pkg-config --cflags --libs gtk+-2.0`
dialog_button_query_treat_medicine_callback.o : dialog_button_query_treat_medicine_callback.c
	gcc -c dialog_button_query_treat_medicine_callback.c `pkg-config --cflags --libs gtk+-2.0`

clean :
	rm FWD \
		main_window.o \
		window_menubar_help_about_callback.o \
		window_button_new_callback.o \
		window_button_query_callback.o \
		dialog_button_new_diagnose_callback.o \
		dialog_button_query_person_diagnose_callback.o \
		dialog_button_query_treat_diagnose_callback.o \
		dialog_button_query_treat_medicine_callback.o
