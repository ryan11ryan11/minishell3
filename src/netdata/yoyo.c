#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int pipe1[2]; // ls -al | grep a
    int pipe2[2]; // grep a | grep b

    // 파이프 생성
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(1);
    }
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(1);
    }

    // 첫 번째 자식 프로세스: ls -al
    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid1 == 0) {
        // 자식 프로세스 1: ls -al
        // pipe1의 쓰기 끝을 STDOUT으로 연결
        dup2(pipe1[1], STDOUT_FILENO);

        // 사용하지 않는 파이프 닫기
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        // ls -al 실행
        execlp("ls", "ls", "-al", NULL);
        perror("execlp ls");
        exit(1);
    }

    // 두 번째 자식 프로세스: grep a
    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid2 == 0) {
        // 자식 프로세스 2: grep a
        // pipe1의 읽기 끝을 STDIN으로 연결
        dup2(pipe1[0], STDIN_FILENO);
        // pipe2의 쓰기 끝을 STDOUT으로 연결
        dup2(pipe2[1], STDOUT_FILENO);

        // 사용하지 않는 파이프 닫기
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        // grep a 실행
        execlp("grep", "grep", "a", NULL);
        perror("execlp grep a");
        exit(1);
    }

    // 세 번째 자식 프로세스: grep b
    pid_t pid3 = fork();
    if (pid3 == -1) {
        perror("fork");
        exit(1);
    }

    if (pid3 == 0) {
        // 자식 프로세스 3: grep b
        // pipe2의 읽기 끝을 STDIN으로 연결
        dup2(pipe2[0], STDIN_FILENO);

        // 사용하지 않는 파이프 닫기
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        // grep b 실행
        execlp("grep", "grep", "b", NULL);
        perror("execlp grep b");
        exit(1);
    }

    // 부모 프로세스: 사용하지 않는 파이프 닫기
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // 자식 프로세스가 종료될 때까지 대기
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
