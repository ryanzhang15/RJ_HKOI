        .data
        
        .text
main:   

	li $v0, 5
	syscall
	move $t0, $v0
	
	li $v0, 5
	syscall
	move $s1, $v0
	
	beqz $t0, Twelve
	
	li $t3, 12
	sub $s2, $t0, $t3
	bgtz $s2, Ting
	
	move $a0, $t0
	li $v0, 1
	syscall
	
Back:

	li $a0, 58
	li $v0, 11
	syscall
	
	li $t3, 10
	sub $s3, $s1, $t3
	bltz $s3, What
	
After:
	
	move $a0, $s1
	li $v0 1
	syscall
	
	li $a0, 32
	li $v0, 11
	syscall
	
	beqz $t0, AM
	bgez $s2, PM
	j AM
	
Done:
	
	j End
	
Ting:

	move $a0, $s2
	li $v0, 1
	syscall
	
	j Back

What:
	
	li $a0, 48
	li $v0, 11
	syscall
	
	j After
	
AM:
	
	li $a0, 65
	li $v0, 11
	syscall
	
	li $a0, 77
	li $v0, 11
	syscall
	
	j Done
	
PM:
	
	li $a0, 80
	li $v0, 11
	syscall
	
	li $a0, 77
	li $v0, 11
	syscall
	
	j Done
	
Twelve:
	
	li $a0, 12
	li $v0, 1
	syscall
	
	j Back
	
End:

	#jr $ra