#pragma once


/* Initializes the menu system. minibuf is the window it should use
 * as "minibuffer", that is, the window where it will show prompts
 * and confirmation messages. */
void menu_init(WINDOW *minibuf);

/* Shows the Omnitty extended menu onscreen. After calling this function,
 * the screen will be dirty so you must touchwin() all your windows to
 * get them to redraw fully. */
void menu_show();

