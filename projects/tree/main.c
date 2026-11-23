#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

void exploreDirectory(char *path, int level, int *dir_count, int *files_count) {
  DIR *dir;
  struct stat stats;
  dir = opendir(path);

  if (dir == NULL) {
    return;
  }
  struct dirent *entry;
  char fullPath[2048];

  while ((entry = readdir(dir)) != NULL) {

    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
      continue;
    }

    int result = stat(entry->d_name, &stats);
    for (int i = 0; i < level; i++) {
      printf("    ");
    }
    printf("|--%s", entry->d_name);
    if (S_ISDIR(stats.st_mode)) {
      printf("/\n");
      *dir_count += 1;
      snprintf(fullPath, strlen(path) + strlen(entry->d_name) + 2, "%s/%s",
               path, entry->d_name);
      exploreDirectory(fullPath, level + 1, dir_count, files_count);
    } else {
      *files_count += 1;
      printf("\n");
    }
  }
}

int main(int c, char *argv[]) {
  char *cur_dir = ".";

  if (c == 2) {
    cur_dir = argv[1];
  }

  int directorires_count = 0;
  int files_count = 0;
  exploreDirectory(cur_dir, 0, &directorires_count, &files_count);
  printf("%d directories, %d files \n", directorires_count, files_count);
  return 0;
}
