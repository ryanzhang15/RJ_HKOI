	.data
	
arr: .word 456
	
	.text
	
main:
	
	la $s0, arr		#s0 points to arr
	
	li $v0, 5
	syscall	
	move $s1, $v0		#s1 size of array
	
	li $s2, 0		#s2 counter

input:
	
	beq $s2, $s1, startSort
	
	li $v0, 5
	syscall
	sw $v0, ($s0)
	
	addi $s0, $s0, 4
	addi $s2, $s2, 1
	
	j input
	
startSort:
	
	la $s0, arr
	li $t0, 0
	addi $t2, $s1, -1
					
loop1:
	
	beq $t0, $t2, out
	li $t1, 0
	sub $t3, $s1, $t0
	addi $t3, $t3, -1

loop2:
	
	beq $t1, $t3, increment
	
	move $t4, $t1
	add $t4, $t4, $t4
	add $t4, $t4, $t4
	add $s3, $t4, $s0
	lw $s2, ($s3)
	
	move $t4, $t1
	add $t4, $t4, 1
	add $t4, $t4, $t4
	add $t4, $t4, $t4
	add $s5, $t4, $s0
	lw $s4, ($s5)
	
	bgt $s2, $s4, swap

back:
	
	addi $t1, $t1, 1
	j loop2
	
out:

	la $s0, arr
	li $s2, 0		#s2 counter
	
outLoop: 

	beq $s1, $s2, exit
	
	lw $a0, ($s0)
	li $v0, 1
	syscall
	
	li $a0, 10
	li $v0, 11
	syscall
		
	addi $s0, $s0, 4
	addi $s2, $s2, 1
	
	j outLoop
	
exit:

	jr $ra
	
increment: 

	addi $t0, $t0, 1
	
	j loop1

swap:
	
	sw $s4, ($s3)
	sw $s2, ($s5)
	j back