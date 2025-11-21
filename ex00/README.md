# Megaphone

This program behaves like a megaphone: it takes command-line arguments, converts them to uppercase, and prints them to the standard output. If no arguments are provided, it emits a loud feedback noise.

## Compilation

To compile the program, use the provided Makefile:

```bash
make
```

This will generate an executable named `megaphone`.

## Usage

Run the program with arguments to hear them amplified:

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

Output:
```
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

Multiple arguments are concatenated:

```bash
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
```

Output:
```
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
```

If run without arguments:

```bash
./megaphone
```

Output:
```
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## Cleaning up

To remove object files:
```bash
make clean
```

To remove object files and the executable:
```bash
make fclean
```

To recompile from scratch:
```bash
make re
```
