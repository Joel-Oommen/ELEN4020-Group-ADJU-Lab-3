from mrjob.job import MRJob
import os


class matrixMultiply(MRJob):

	def sortbyJ(listItem):
		return listItem[0]
	
	def mapper(self, _, line):
		#info1 = matrixM.readline()
		#info2 = matrixN.readline()
		if len(line.split()) == 3: 
			nameFile = os.environ['map_input_file']
			if nameFile == "test.txt":			
				iM,jM,valueM =  line.split()
				#print '---',iM,jM,valueM,jN,kN,valueN,'---'
				for k in range(0,int(columnsN)):
				        yield (int(iM),int(k)),('M',int(jM),int(valueM))
					#print iM, k, 'M', jM, valueM
			else:
				jN,kN,valueN =  line.split()
				for i in range(0,int(rowsM)):
					yield (int(i),int(kN)),('N',int(jN),int(valueN))
		        		#print i, kN, 'N', jN, valueN


	def reducer(self, key, values):
		oldlistM = []
		oldlistN = []
		for i in values:
			if i[0]=='M':
				oldlistM.append([i[1],i[2]])
			else:
				oldlistN.append([i[1],i[2]])
		print oldlistM
		print oldlistN
		listM = sorted(oldlistM, key=lambda x:x[1])
		listN = sorted(oldlistN, key=lambda x:x[1])
		print listM
		print listN
		P = []
		k=0;
		#for i in range((len(listM)/(int(columnsM))-1)*int(columnsM),len(listM)):
		for i in listM:
			for l in range(0,len(listN)):
				if listN[l][0]==i[0]:			
					P.append(i[1]*listN[k][1])
					k=k+1
					print P
				else:
					P.append(0)
		#key.sort()
		sumofP=sum(P)
		if sumofP != 0:
			yield key,sumofP
		

		#print key, sum(P)
	


if __name__ == '__main__':
	matrixM = open("test.txt","r")
	rowsM,columnsM = matrixM.readline().split()
	matrixN = open("test2.txt","r")
	rowsN,columnsN = matrixN.readline().split()	
			
	#P = [] #Answer Matrix    
	matrixMultiply.run()
	









