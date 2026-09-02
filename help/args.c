#include <getopt.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int flag = 0;
  const struct option options[] = {
    {"coso", no_argument, NULL, 0},
    {"shish", required_argument, NULL, 1},
    {"sus", optional_argument, NULL, 2}
  };
  
  if (argc == 1)
    for (unsigned char i = 0; i < 3; i++)
    {
      int childProcessId = fork(),
          execute = -1;
      switch (childProcessId)
      {
        case -1:
          puts("C'è stato un piccolo intoppo :-)");
          return 1;
          break;
        case 0:
          execute = execl(*argv, *argv, !i ? "-coso" : i == 1 ? "-shish=132" : "-sus=3422314",0);
          if (execute == -1)
          {
            puts("Errore nell'esecuzione!");
            return 1;
          }
          break;
      }
      wait(NULL);
    }

  while ((flag = getopt_long(argc, argv, "", options, NULL)) != -1)
  {
    switch (flag)
    {
      case 0:
        printf("cosone %s %d\n", optarg, optind);
        break;
      case 1:
        printf("shishone %s %d\n", optarg, optind);
        break;
      case 2:
        printf("susone %s %d\n", optarg, optind);
        break;
    }
  }

  return 0;
}
