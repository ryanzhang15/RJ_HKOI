	.data
	
stack: 	.word 100		#idk how big its meant to be, 100 must be enough right

	.text
	
main:

	la $s0, stack		#s0 is stack top
	
in:
	
	li $v0, 12		#read character
	syscall
	move $t0, $v0
	
	beq $t0, 10, exit
	
	blt $t0, 48, stackPop	#bacon lettuce tomato
	
	addi $t0, $t0, -48
	j stackPush

stackPush:
	
	addi $s0, $s0, 4
	sw $t0, ($s0)
	
	j in
	
stackPop:
	
	lw $s2, ($s0)
	addi $s0, $s0, -4
	lw $s1, ($s0)
	addi $s0, $s0, -4
	
	beq $t0, 43, addition
	beq $t0, 45, subtraction
	j multiplication

addition:
	
	add $t0, $s1, $s2
	j stackPush

subtraction:

	sub $t0, $s1, $s2
	j stackPush
	
multiplication:

	mult $s1, $s2
	mflo $t0
	j stackPush

exit:

	lw $a0, ($s0)
	li $v0, 1
	syscall
	
	jr $ra
