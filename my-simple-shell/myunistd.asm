;Assembler File
;implements Wrapper for functions using syscalls
;
;Macro r10 muss durch rcx ersetzt werden
%macro do_syscall 1
    ;push RBP         ;push basepointer onto stack (to remember old stackframe)
    ;mov RBP, RSP     ;saves stackpointer (new stackframe) in register rbx
    enter
    mov R10, RCX     ;replace RCX with R10 as RCX is not used in syscall, but function
    mov RAX, %1      ;call 1 argument of macro
    int 0x80        ;interupt call kernel
    leave
%endmacro

;.data stores global variables
SECTION .data
global myread
global mywrite
global myclose
global mypipe
global mydup2
global myfork
global myexecve
global mywait4
global mychdir
global myexit

SECTION .text
myread: do_syscall 0
mywrite: do_syscall 1
myclose: do_syscall 3
mypipe: do_syscall 22
mydup2: do_syscall 33
myfork: do_syscall 57
myexecve: do_syscall 59
mywait4: do_syscall 61
mychdir: do_syscall 80
myexit: do_syscall 231

