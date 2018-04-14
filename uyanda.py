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
    	
    	
    	
    		
        yield 1, 1


if __name__ == '__main__':
    MRWordFrequencyCount.run()

