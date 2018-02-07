test= input()
instr = ''
t= int(test)

while t>0:
	count = 0
	instr = input()
	i=0
	while i<len(instr):
		if instr[i]== 'c' or instr[i]=='h' or instr[i]=='e' or instr[i]=='f':
			print(sorted(instr[i:i+4]))
			if sorted(instr[i:i+4]) == sorted('cefh'):
				count = count+1
		i=i+1

	if count==0:
		print('normal')
	else:
		print('lovely', count)

	t=t-1
