# 2022
# Farhan Syed 
# Abhinav Sasikumar  

.text

	#i = n
	# for(j = i-1; j > 1; j--){
	#	k = sum
	#	for(t=1;t < j;t++){
	#	 sum += k				
																																	
main :
    	addi $a0, $0, 0 #n 
    	addi $v0, $a0, 0		# set sum = n
    	addi $a1,$a0, 0			# j = i
    	beq $a0,$0,zero			# base case
outerLoop:
    	addi $a1, $a1, -1		# decrement j 
    	addi $a3, $v0, 0		# k = sum
    	beq $a1,$0, stop 		# if j = 0 stop
    	add $0,$0,$0			# nop 
    	addi $a2, $0,1			# t
addLoop:
    	beq $a2,$a1, outerLoop		# if t = j, go back to outerloop
    	add $0,$0,$0		
    	addi $a2, $a2,1			# increment t
    	add $v0, $v0, $a3		# sum += k
    	beq $0, $0, addLoop 		# loop
 	add $0,$0,$0			# nop
	  
zero:
	addi	$v0, $0, 1
	
stop:
	beq	$0, $0, stop
	add $0,$0,$0
	

