
# pointers.asm
# 2022
# Farhan Syed 
# Abhinav Sasikumar 


.macro	PUSH (%reg)
	addi	$sp,$sp,-4
	sw	%reg,0($sp)
.end_macro

.macro	POP (%reg)
	lw	%reg,0($sp)
	addi	$sp,$sp,4
.end_macro

.data


text1: 	  .asciiz "This is a string."
text2:	  .asciiz "Yet another thing."

.align 2
list1: 	.space 80
list2: 	.space 80
count:	.word  0

.text
main:
	jal	work
stop:	j	stop

# function work()
work:
	PUSH	($ra)
	la 	$a0,text1
	la	$a1,list1
	la	$a2,count
	jal	copycodes
	
	la 	$a0,text2
	la	$a1,list2
	la	$a2,count
	jal	copycodes
	POP	($ra)
	
	
# function copycodes()
copycodes:
loop:
	lb	$t0,0($a0)	
	beq	$t0,$0,done
	sw	$t0,0($a1)

	addi	$a0,$a0,1
	addi	$a1,$a1,4
	
	lw	$t1,0($a2)
	addi	$t1,$t1,1
	sw	$t1,0($a2)
	j	loop
done:
	jr	$ra
		



