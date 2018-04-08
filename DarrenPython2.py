class matrixMultiply(MRJob):

	def mapper(self, _, line):
		iM,jM,valueM = matrixM.readline().split()
		jN,kN,valueN = matrixN.readline().split()
		for k in range(0,int(columnsN)):
		        yield (int(iM),int(k)),('M',int(jM),int(valueM))
			#print iM, k, 'M', jM, valueM
		for i in range(0,int(rowsM)):
			yield (int(i),int(kN)),('N',int(jN),int(valueN))
	        	#print i, kN, 'N', jN, valueN


	def reducer(self, key, values):
        	yield key, sum(values)
	#	for i in values:
	#		if i[0]=='M':
	#			listM.append(index[2])#,index[2]]
	#		else:
	#			listN.append(index[2])#,index[2]]
	#	for i in range(0,int(columnsM)):
	#		P.append(listM[i]*listN[i])
	#	yield key,sum(P)
	#	print key, sum(P)
	


if __name__ == '__main__':
	matrixM = open("test.txt","r")
	rowsM,columnsM = matrixM.readline().split()
	matrixN = open("test2.txt","r")
	rowsN,columnsN = matrixN.readline().split()	
	listM = []
	listN = []		
	P = [] #Answer Matrix    
	matrixMultiply.run()
	









