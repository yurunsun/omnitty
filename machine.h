#pragma once

#define TAGSTACK_SIZE 8

/** This structure represents each machine the program interacts with */
struct Machine
{
    std::string login;
    std::string name;       /* name of the machine */
    bool tag;               /* whether the machine is 'tagged' */
    bool alive;             /* initially set to true; set to false when
                             * main program notifies that a certain pid has died and
                             * it matches this machine's ssh pid */
    RoteTerm *vt;           /* the machine's virtual terminal (ROTE library) */
    pid_t pid;              /* pid of ssh process running in terminal */
    bool tagstack[TAGSTACK_SIZE];    /* the following stack is used for storing the 'tagged' state for later retrieval */
    int tagstack_count;
};

/**
 * Creates a new machine with the given name and virtual terminal dimensions.
 * Returns a pointer to the newly created machine. The machine must be
 * destroyed with machine_destroy after use. This function starts
 * a child ssh process to connect to the machine and puts its PID
 * in the pid field of the returned machine structure. The ssh runs
 * in the RoteTerm virtual terminal, whose address is also returned in
 * the structure.
*/
Machine *machine_new(const std::string& login, const std::string& name, int vtrows, int vtcols);

/** Destroyes a machine previously created my machine_new. */
void machine_destroy(Machine*);

/** Save/restore machine's 'tagged' state.  */
void machine_tag_push(Machine*);
void machine_tag_pop(Machine*);

/** Rename a machine */
void machine_rename(Machine*, char*);

