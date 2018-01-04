#ifndef _PROCESSINFO_H_
#define _PROCESSINFO_H_
#include "types.h"

// procstate was previously defined in kernel/proc.h but we moved it here to
// make the process state definitions available to user code.
enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct ProcessInfo {
  int pid; // process id
  int ppid; // parent pid
  int state; // state (with values taken from "enum procstate" above
  uint sz; // size in bytes
  char name[16]; // name of process
};

#endif //_PROCESSINFO_H_
