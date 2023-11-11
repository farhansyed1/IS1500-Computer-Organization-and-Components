# 2022
# Farhan Syed 
# Abhinav Sasikumar  

.text

	#i = n
	#sum = n
	# for(j = i-1; j > 1; j--){
	#	 sum *= j-1				
																																	
main :
    	addi $a0, $0, 1	# n 
    	addi $v0, $a0, 0		# set sum = n
    	addi $a1,$a0, 0			# j = i
    	beq $a0,$0,zero			# base case
loop:
    	addi $a1, $a1, -1		# decrement j 
    	beq $a1,$0, stop 		# if j = 0 stop
    	add $0,$0,$0			# nop 
    	mul $v0, $v0, $a1
    	beq $0,$0, loop	
    	add $0,$0,$0
    
zero:
	addi	$v0, $0, 1
	
stop:
	beq	$0, $0, stop
	add $0,$0,$0
	

