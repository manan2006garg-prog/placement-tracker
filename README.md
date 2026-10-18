# Placement Tracker

A small C command-line program for recording placement applications and their current stage. It writes entries to a local text file.

## Build

Requires a C11 compiler such as GCC or Clang.

```sh
gcc -std=c11 -Wall -Wextra -pedantic app.c -o placement-tracker
```

On Windows, add `.exe` to the output name.

## Use

```sh
./placement-tracker add "Example Systems" "Software Intern" applied 2026-10-18
./placement-tracker add "Example Systems" "Software Intern" interview 2026-11-02
./placement-tracker list
```

Stages: `applied`, `online-test`, `interview`, `offer`, and `rejected`. Data is stored in `applications.txt` in the current directory. Fields cannot contain `|`.

## Scope and next steps

This is a local, single-user starter. Add date validation, editing, duplicate detection, filters, and CSV export as follow-up work. Do not commit personal application data.
