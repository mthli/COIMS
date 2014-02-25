#include "coims.h"

void get_row_and_column(GtkCList *clist, gint row, gint column, GdkEvent *event, Item *parents)
{
    (*parents).get_row = row;
    (*parents).get_column = column;

    printf("row = %d, column = %d.\n", (*parents).get_row, (*parents).get_column);
}
