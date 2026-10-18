#include <stdio.h>
#include <string.h>

#define DB "applications.txt"
#define LINE 512

static int clean(const char *s) { return !strchr(s, '|') && !strchr(s, '\n') && !strchr(s, '\r'); }
static int valid_stage(const char *s) {
    return !strcmp(s,"applied") || !strcmp(s,"online-test") || !strcmp(s,"interview") || !strcmp(s,"offer") || !strcmp(s,"rejected");
}
static void usage(void) {
    puts("Placement Tracker\n  placement-tracker add COMPANY ROLE STAGE DATE\n  placement-tracker list\nStages: applied, online-test, interview, offer, rejected");
}
int main(int argc, char **argv) {
    FILE *f;
    char line[LINE];
    if (argc == 2 && !strcmp(argv[1], "list")) {
        f = fopen(DB, "r");
        if (!f) { puts("No applications yet."); return 0; }
        while (fgets(line, sizeof line, f)) printf("%s", line);
        fclose(f); return 0;
    }
    if (argc != 6 || strcmp(argv[1], "add")) { usage(); return 1; }
    if (!clean(argv[2]) || !clean(argv[3]) || !clean(argv[4]) || !clean(argv[5]) || !valid_stage(argv[4])) {
        fputs("Invalid field or stage. Fields cannot contain | characters.\n", stderr); return 1;
    }
    f = fopen(DB, "a");
    if (!f) { perror(DB); return 1; }
    fprintf(f, "%s | %s | %s | %s\n", argv[2], argv[3], argv[4], argv[5]);
    fclose(f); puts("Application saved."); return 0;
}
