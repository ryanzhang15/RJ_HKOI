.data

.text
main:   li $v0, 5
syscall
move $t0, $v0

li $v0, 5
syscall

div $t0, $v0
mflo $a0
li $v0, 1
syscall

li $a0, 10
li $v0, 11
syscall

mfhi $a0
li $v0 ,1
syscall

li $a0, 10
li $v0, 11
syscall

jr $ra
