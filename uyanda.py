from mrjob.job import MRJob
import math
matrixName = []
rows = []
columns = []
values = []

listA = []
listB = []

matrixA = []
matrixB = []


def oneToTwoDimensions(theList, n):
	return [theList[i:i+n] for i in range(0, len(theList), n)]

def addMatrices(X, Y):
	ult = X
	for i in range(len(X)):
		for j in range(len(X[0])):
			ult[i][j] = X[i][j] + Y[i][j]
	return ult

def subtractMatrices(X, Y):
	ult = X
	for i in range(len(X)):
		for j in range(len(X[0])):
			ult[i][j] = X[i][j] - Y[i][j]
	return ult
	
def multiplyMatrices(v, G):	
	result = []
	total = 0
	for i in range(len(G)):
		r = G[i]
		for j in range(len(v)):
		    total += r[j] * v[j]
		result.append(total)
	return result 
	
class MRWordFrequencyCount(MRJob):

    def mapper(self, _, line):
    	a,b,c,d = line.split()
    	print d
        yield 1, (a,b,c,d)

    def reducer(self, key, values):
    	
    	for k in values:
    		if k[0] == 'A':
    			a = k[-1:]
    			listA.append(a[0])
    		elif k[0] == 'B':
    			b = k[-1:]
    			listB.append(b[0])
    			
   
    	
    	matrixA = oneToTwoDimensions(listA, int(math.sqrt(len(listA))))
    	
    	matrixB = oneToTwoDimensions(listB, int(math.sqrt(len(listB))))
    	
    	
    	nDimension = int(len(matrixA))
    	
    	
    	
        yield 1, 1


if __name__ == '__main__':
    MRWordFrequencyCount.run()

