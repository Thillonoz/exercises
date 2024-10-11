printf "Script is starting\n"
mkdir -p program
cd /home/thillonoz/Projects/c/local/SPC/program
touch main.c
printf "#include <stdio.h>\n#define NAME \"bob\"\nint main()\n{\nprintf(\"Hello %%s\\\n\", NAME);\nreturn 0;\n}" >> main.c
rm -f main
clear
gcc ./main.c -o main
./main
code .
ls
