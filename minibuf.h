#pragma once


/* caution: the following function uses what is already in the buffer
 * as the default content of the field, so it absolutely must not
 * contain trash (and must be 0-terminated). 
 *
 * If you want to start with an empty buffer, do something like *buf = 0
 * before calling.
 *
 * Returns whether used confirmed the input, that is whether the
 * user ended the input with ENTER. If the user exitted with ESC
 * any other 'cancel-key', the return value will be false.
 */
bool minibuf_prompt(WINDOW *w, const char *prompt, unsigned char attr, 
                               char *buf, int len);

/* displays a message in the window, waits for the
 * user to acknowledge it and returns */
void minibuf_msg(WINDOW *w, const char *msg, unsigned char attr);

/* displays a message in the minibuffer and returns immediately.
 * Remember to call this function with an empty (or NULL) message
 * to erase it. */
void minibuf_put(WINDOW *w, const char *msg, unsigned char attr);

