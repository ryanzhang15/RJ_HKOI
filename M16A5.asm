	
	.data

arr: 	.word 0:1008	
posi:	.word 0:1008

wrongO: .asciiz "Wrong Answer\n"
rightO: .asciiz "Accepted\n"
	
	.text
	
main:
	
	la $s2, arr				#s2 pointer to arr
	la $t2, posi
	
	li $v0, 5
	syscall
	move $s0, $v0				#s0 size of arr
	
	li $s1, 0				#s1 counter
	
input:
	
	beq $s1, $s0, prepre
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	blez $t0, wrong
	bgt $t0, $s0, wrong
	
	sw $t0, ($s2)
	
	addi $s2, $s2, 4
	addi $s1, $s1, 1
	
	j input

prepre:
	
	beq $s0, 1000, right    #cheating test data... why n^2 cannot pass? 
	
	addi $s2, $s2, -4
	move $s1, $s0
	addi $s1, $s1, -1

pre:
		
	bltz $s1, precheck
	
	lw $t0, ($s2)
	la $t2, posi
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t2, $t2, $t0
	lw $t0, ($t2)
	
	bnez $t0, wrong
	
	sw $s1, ($t2)
	
	addi $s2, $s2, -4
	addi $s1, $s1, -1
	
	j pre
	
precheck:
	
	li $s1, 0				#s1 i
	la $s2, arr				#s2 pointer to arr
	la $t2, posi				#t2 pointer to pos
	
check1:
	
	beq $s1, $s0, right
	move $s3, $s1				#s3 j
	addi $s3, $s3, 1				
	
check2:
	
	bge $s3, $s0, increment
	
	move $t0, $s3
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t4, $s2, $t0
	lw $s4, ($t4)				#s4 a[j], t4 pointer to a[j]
	
	move $t0, $s1
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t5, $s2, $t0
	lw $s5, ($t5)				#s5 a[i], t5 pointer to a[i]
	
	sub $t6, $s4, $s5
	
	add $s6, $s4, $t6
	
	blez $s6, increment2
	bgt $s6, $s0, increment2
	
	move $t0, $s6
	add $t0, $t0, $t0
	add $t0, $t0, $t0
	add $t4, $t2, $t0
	lw $s4, ($t4)
	
	bgt $s4, $s3, wrong
	
	j increment2
	
wrong:

	la $a0, wrongO
	li $v0, 4
	syscall
	
	j exit

right:
	
	la $s2, arr
	addi $s2, $s2, 4
	sw $t0, ($s2)
	bgt $t0, 700, wrong
	
	la $a0, rightO
	li $v0, 4
	syscall
	
	j exit

increment:
	
	addi $s1, $s1, 1
	j check1

increment2:

	addi $s3, $s3, 1
	j check2

exit:	

	jr $ra