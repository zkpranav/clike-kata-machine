#ifndef _THREADLIST_H_
#define _THREADLIST_H_

/*
 * AmigaOS-style linked list of threads.
 *
 * The two threadlistnodes in the threadlist structure are always on
 * the list, as bookends; this removes all the special cases in the
 * list handling code. However, this means that iterating starts with
 * the "second" element in the list (tl_head.tln_next, or
 * tl_tail.tln_prev) and it ends at the last element that's actually a
 * thread.
 *
 * Note that this means that assigning or memcpying threadlist
 * structures will break them. Don't do that...
 *
 * ->tln_self always points to the thread that contains the
 * threadlistnode.
 */

/* Placeholder thread struct */
struct thread {
    struct threadlistnode *tln;
};

struct threadlistnode {
    struct threadlistnode *tln_next;
    struct threadlistnode *tln_prev;
    struct thread *tln_self;
};

struct threadlist {
    struct threadlistnode *tl_head;
    struct threadlistnode *tl_tail;
    unsigned tl_count;
};

/* Initialize and cleanup a thread list node */
void threadlistnode_init(struct threadlistnode *tln, struct thread* self);
void threadlistnode_cleanup(struct threadlistnode *tln);

/* Initialize and cleanup a thread list */
void threadlist_init(struct threadlist *tl);
void threadlist_cleanup(struct threadlist *tl);

/* Check if empty */
bool threadlist_isempty(struct threadlist* tl);

/* Add and remove at ends */
void threadlist_addhead(struct threadlist *tl, struct threadlistnode *tln);
void threadlist_addtail(struct threadlist *tl, struct threadlistnode *tln);
struct thread* threadlist_remhead(struct threadlist *tl);
struct thread* threadlist_remtail(struct threadlist *tl);

/* Internal functions. Add remove in the middle. tl is needed to maintain ->tl_count */
void threadlist_insertAfter(struct threadlist *tl, struct threadlistnode *onlist, struct thread *addee);
void threadlist_insertBefore(struct threadlist *tl, struct thread *addee, struct threadlistnode *onlist);
struct thread* threadlist_remove(struct threadlist *tl, struct thread *t);

#endif /* THREADLIST_H_ */