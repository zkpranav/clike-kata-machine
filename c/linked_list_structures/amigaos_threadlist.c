#include <stdlib.h> // For NULL
#include <stdbool.h>
#include <assert.h>
#include "amigaos_threadlist.h"

void threadlistnode_init(struct threadlistnode *tln, struct thread* self) {
    assert(tln != NULL);
    assert(self != NULL);

    tln->tln_next = NULL;
    tln->tln_prev = NULL;
    tln->tln_self = self;
}

void threadlistnode_cleanup(struct threadlistnode *tln) {
    assert(tln != NULL);

    assert(tln->tln_next == NULL);
    assert(tln->tln_prev == NULL);
    assert(tln->tln_self != NULL);
}

void threadlist_init(struct threadlist *tl) {
    assert(tl != NULL);

    tl->tl_head->tln_next = &tl->tl_tail;
    tl->tl_head->tln_prev = NULL;
    tl->tl_tail->tln_prev = &tl->tl_head;
    tl->tl_tail->tln_next = NULL;
    tl->tl_head->tln_self = NULL;
    tl->tl_tail->tln_self = NULL;
    tl->tl_count = 0;
}

void threadlist_cleanup(struct threadlist *tl) {
    assert(tl != NULL);

    assert(tl->tl_head->tln_next == &tl->tl_tail);
    assert(tl->tl_head->tln_prev == NULL);
    assert(tl->tl_tail->tln_prev == &tl->tl_head);
    assert(tl->tl_tail->tln_next == NULL);
    assert(tl->tl_head->tln_self == NULL);
    assert(tl->tl_tail->tln_self == NULL);
    assert(tl->tl_count == 0);
}

bool threadlist_isempty(struct threadlist* tl) {
    assert(tl != NULL);

    return (tl->tl_count == 0);
}

//////////////////////////////////////////////////////////
/* Internal */

static void threadlist_insertafter(struct threadlistnode *onlist, struct thread *t) {    
    struct threadlistnode *addee;
    addee = t->tln;
    assert(addee != NULL);
    assert(addee->tln_next == NULL);
    assert(addee->tln_prev == NULL);

    addee->tln_prev = onlist;
    addee->tln_next = onlist->tln_next;
    addee->tln_prev->tln_next = addee;
    addee->tln_next->tln_prev = addee;
}

static void threadlist_insertbefore(struct thread *t, struct threadlistnode *onlist) {
    struct threadlistnode *addee;
    addee = t->tln;
    assert(addee != NULL);
    assert(addee->tln_next == NULL);
    assert(addee->tln_prev == NULL);

    addee->tln_next = onlist;
    addee->tln_prev = onlist->tln_prev;
    addee->tln_prev->tln_next = addee;
    addee->tln_next->tln_prev = addee;
}

static void threadlist_removenode(struct threadlistnode *tln) {
    assert(tln != NULL);
    assert(tln->tln_next != NULL);
    assert(tln->tln_prev != NULL);

    tln->tln_prev->tln_next = tln->tln_next;
    tln->tln_next->tln_prev = tln->tln_prev;
    tln->tln_prev = NULL;
    tln->tln_next = NULL;
}

//////////////////////////////////////////////////////////
/* Public */

void threadlist_addhead(struct threadlist *tl, struct thread *t) {
    assert(tl != NULL);
    assert(t != NULL);

    threadlist_insertafter(tl->tl_head, t);
    tl->tl_count += 1;
}

void threadlist_addtail(struct threadlist *tl, struct thread *t) {
    assert(tl != NULL);
    assert(t != NULL);

    threadlist_insertbefore(t, tl->tl_tail);
    tl->tl_count += 1;
}

struct thread* threadlist_remhead(struct threadlist *tl) {
    assert(tl != NULL);

    struct threadlistnode *tln;
    tln = tl->tl_head->tln_next;
    if (tln->tln_next == NULL) {
        // List was empty
        return NULL;
    }

    threadlist_removenode(tln);
    assert(tl->tl_count > 0);
    tl->tl_count -= 1;

    return tln->tln_self;
}

struct thread* threadlist_remtail(struct threadlist *tl) {
    assert(tl != NULL);

    struct threadlistnode *tln;
    tln = tl->tl_tail->tln_prev;
    if (tln->tln_prev == NULL) {
        // List was empty
        return NULL;
    }

    threadlist_removenode(tln);
    assert(tl->tl_count > 0);
    tl->tl_count -= 1;
    
    return tln->tln_self;
}
