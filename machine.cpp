#include "stdafx.h"
#include "machine.h"


#define CMD_FORMAT "/usr/bin/sshpass -p 15j4h8y-ob ssh -p 4353 root@%s"

Machine *machine_new(const std::string &login, const std::string &name, int vtrows, int vtcols)
{
    Machine *m = new Machine;
    m->login = login;
    m->name = name;
    m->alive = true;
    m->vt = rote_vt_create(vtrows, vtcols);

    /* build the command line and fork an ssh to the given machine */
    m->pid = rote_vt_forkpty(m->vt, m->login.c_str());
    return m;
}

void machine_destroy(Machine *m) {
    if (!m) return;
    rote_vt_destroy(m->vt);
    delete m;
    m = nullptr;
}

void machine_rename(Machine *m, char *newname) {
    if (!m) return;
    m->name = std::string(newname);
}

void machine_tag_push(Machine *m) {
    if (m->tagstack_count >= TAGSTACK_SIZE) return;
    m->tagstack[m->tagstack_count++] = m->tag;
}

void machine_tag_pop(Machine *m) {
    if (!m->tagstack_count) return;
    m->tag = m->tagstack[--m->tagstack_count];
}

