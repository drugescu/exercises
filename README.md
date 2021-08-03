=Various embedded C and C++ exercises=

Make them all with:
`ls *.c | xargs -I{} basename {} .c | xargs -I{} gcc {}.c -o {}.o`
