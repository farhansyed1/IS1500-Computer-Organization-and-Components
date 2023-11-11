  # hexmain.asm
  # 2022
  # Farhan Syed 
  # Abhinav Sasikumar 

	.text
main:
	li	$a0,17		#change this to test different values

	jal	hexasc		# call hexasc
	nop			# delay slot filler (just in case)	

	move	$a0,$v0		# copy return value to argument register

	li	$v0,11		
	syscall			
	
stop:	j	stop		# stop after one run
	nop			# delay slot filler (just in case)

  # You can write your own code for hexasc here
  #
hexasc: 
	sll $t0, $a0, 0x1c
	srl $t0, $t0, 0x1c
	
	slti $t1, $t0, 0xA			#0-9 = dont run convert
	beq $t1, $0, aToFConvert		#10-15 = run convert
	nop
	addi $v0 , $t0, 0x30			#the number plus 48 gives the correct ascii
	jr $ra
	nop
 	
aToFConvert:
	addi $v0, $t0, 0x37  			#the number plus 55 gives the correct ascii
	jr $ra
	nop
