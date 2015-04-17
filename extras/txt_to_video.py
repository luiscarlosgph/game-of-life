#!/usr/bin/python
# 
# Script to convert the output file produced by the program GameOfLife into a video.
# 
# Dependencies:
# =============
#
# 1) FFmpeg version 2.4.2
# 
# Author: Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
# Date  : 15 Apr 2015.

import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np
import cv2
import os
import shutil
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

def createImageFromMatrix(mat):
	# Create colormap of fixed colors (two tones of blue, one darker (representing alive cells) than the other one)
	cmap = mpl.colors.ListedColormap([[0.84, 0.92, 1], [0.11, 0.58, 1]])
	bounds = [-0.1, 0.1, 0.9, 1.1]
	norm = mpl.colors.BoundaryNorm(bounds, cmap.N)
	
	# Hide axes text
	frame = plt.gca()
	frame.axes.get_xaxis().set_visible(False)
	frame.axes.get_yaxis().set_visible(False)

	# Set the previous color map as the one to be used when plotting
	img = plt.imshow(mat, interpolation = 'nearest', cmap = cmap, norm = norm)
	
	# Convert image to OpenCV format
	tmpFile = '/tmp/.temp_conv.png'
	plt.savefig(tmpFile, format = 'png')
	cvImg = cv2.imread(tmpFile, cv2.IMREAD_UNCHANGED)
	os.remove(tmpFile)

	return cvImg

def createVideoFromImages(images, outputFilePath):
	#height, width, layers = images[0].shape
	# video = cv2.VideoWriter(outputFilePath, -1, 1, (width, height))
	#fourcc = cv2.cv.CV_FOURCC(*'XVID')
	#video = cv2.VideoWriter(outputFilePath, fourcc, 20.0, (width, height))

	#for image in images:
	#	for j in xrange(25):
	#		video.write(image)
	# cv2.destroyAllWindows()

	#video.release()

	# Create temporary dir for the pictures
	temporaryFolder = '/tmp/.temporaryVideoFolder'
	if not os.path.exists(temporaryFolder):
	    os.makedirs(temporaryFolder)
	else:
		raise Exception('The temporary folder used to generate the video already exists. Delete it first!')
	
	# Save all the pictures in order
	for i in xrange(len(images)):
		cv2.imwrite(temporaryFolder + '/image' + '{0:05d}'.format(i) + '.png', images[i])
	
	# Convert images to video
	speed = 5
	retvalue = os.system('ffmpeg -f image2 -r ' + str(speed) + ' -i ' + temporaryFolder + '/image%05d.png -vcodec mpeg4 -y ' + outputFilePath)
	
	# Delete temporary folder and its contents
	shutil.rmtree(temporaryFolder)

def getHistoryFileAsString(fname):
	with open(fname) as f:
		content = f.readlines()
	return content

def main():
	script, inputFile, outputFile = argv

	# Read history file and convert it to a list of lines
	lines = getHistoryFileAsString(inputFile)
	
	# Convert lines to a list of images
	listOfImages = []
	boardStr = ''
	for line in lines:
		if line in ['\n', '\r\n']:
			boardStr = boardStr[:-1]
			mat = createMatrixFromString(boardStr)
			img = createImageFromMatrix(mat)	
			listOfImages.append(img)
			boardStr = ''
		else:
			boardStr += line
	
	# Convert the list of images into a video
	createVideoFromImages(listOfImages, outputFile)	
	
if __name__ == "__main__":
	main()
