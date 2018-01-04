#include "user.h"
#include "param.h" // for NPROC

int
main(int argc, char **argv)
{
  static char *state_description[] = {
    [UNUSED]    "UNUSED",
    [EMBRYO]    "EMBRYO",
    [SLEEPING]  "SLEEPING",
    [RUNNABLE]  "RUNNABLE",
    [RUNNING]   "RUNNING",
    [ZOMBIE]    "ZOMBIE"
  };
  struct ProcessInfo pi_array[NPROC];
  int num_procs = getprocs(pi_array);
  struct ProcessInfo* pi;
  for (pi = pi_array; pi < pi_array + num_procs; pi++) {
    // print to file descriptor 1, which is stdout.
    printf(1, "%d  %d  %s  %d  %s\n",
	   pi->pid, pi->ppid, state_description[pi->state], pi->sz, pi->name);
  }
  exit();
}
