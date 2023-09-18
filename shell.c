#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command) {
    char *args[64];
    int arg_count = 0;
    char *token = strtok(command, " ");
    
    while (token != NULL) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    
    args[arg_count] = NULL;
    
    if (arg_count > 0) {
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (arg_count == 2) {
                if (chdir(args[1]) == -1) {
                    perror("cd");
                }
            } else {
                fprintf(stderr, "Usage: cd <directory>\n");
            }
            return;
        }
    }
    
    pid_t pid;
    int status;
    
    if ((pid = fork()) == 0) {
        // Child process
        int in_fd = -1;
        int out_fd = -1;
        
        for (int i = 0; i < arg_count; i++) {
            if (strcmp(args[i], "<") == 0) {
                if (i < arg_count - 1) {
                    in_fd = open(args[i + 1], O_RDONLY);
                    if (in_fd == -1) {
                        perror("open");
                        exit(EXIT_FAILURE);
                    }
                    dup2(in_fd, STDIN_FILENO);
                    close(in_fd);
                    args[i] = NULL;
                } else {
                    fprintf(stderr, "Missing input file.\n");
                    exit(EXIT_FAILURE);
                }
            } else if (strcmp(args[i], ">") == 0) {
                if (i < arg_count - 1) {
                    out_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    if (out_fd == -1) {
                        perror("open");
                        exit(EXIT_FAILURE);
                    }
                    dup2(out_fd, STDOUT_FILENO);
                    close(out_fd);
                    args[i] = NULL;
                } else {
                    fprintf(stderr, "Missing output file.\n");
                    exit(EXIT_FAILURE);
                }
            } else if (strcmp(args[i], "2>") == 0) {
                if (i < arg_count - 1) {
                    out_fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    if (out_fd == -1) {
                        perror("open");
                        exit(EXIT_FAILURE);
                    }
                    dup2(out_fd, STDERR_FILENO);
                    close(out_fd);
                    args[i] = NULL;
                } else {
                    fprintf(stderr, "Missing output file.\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
        
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    
    while (1) {
        printf("myshell> ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0'; // Remove trailing newline
        
        if (strlen(input) == 0) {
            continue; // Ignore empty lines
        }
        
        execute_command(input);
    }
    
    return 0;
}
