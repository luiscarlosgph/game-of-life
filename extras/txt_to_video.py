#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np
from sys import argv

def createMatrixFromString(str):
	rows = len(str.splitlines())
	cols = 0
	
	# Get size of the board
	line = str.splitlines()[0]
	for i in range(0, len(line)):
		if (line[i] == 'O' or line[i] == 'X'):
			cols += 1

	# Create binary matrix
	i = 0
	j = 0
	mat = np.zeros((rows, cols))
	for line in str.splitlines():
		for k in range(0, len(line)):
			if (line[k] == 'O'):
				mat[i, j] = 1
				j += 1
			elif (line[k] == 'X'):
				mat[i, j] = 0
				j += 1
		j = 0
		i += 1
	
	return mat

# def createImageFromMatrix(mat):
	# TODO	
	# plt.plot([1,2,3,4], [1,4,9,16], 'ro')
	# plt.axis([0, 6, 0, 20])
	# plt.show()

def getHistoryFileAsString(fname):
	with open(fname) as f:
	    content = f.readlines()
	return content

def main():
	script, filename = argv

	# Read history file and convert it to a list of lines
	lines = getHistoryFileAsString(filename)
	
	# Convert lines to a list of images
	listOfImages = []
	boardStr = ''
	for line in lines:
		if line in ['\n', '\r\n']:
			boardStr = boardStr[:-1]
			mat = createMatrixFromString(boardStr)
			boardStr = ''
			print mat
			# img = generateBoardImageFromMatrix(mat)	
			# listOfImages.append(img)
		else:
			boardStr += line
	
	# Convert the list of images into a video
	# for image in listOfImages:
	# TODO	
	
if __name__ == "__main__":
	main()
