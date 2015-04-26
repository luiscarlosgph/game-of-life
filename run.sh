#!/bin/bash

# Run Game of Life with test/input.txt as input file and 10 iterations -> output.txt
CMD1="bin/GameOfLife --niter 10 --input test/input.txt --output output.txt"
if [ -f output.txt ]; then
	rm output.txt
fi
echo "Running program with an input file that specifies domain size and initial state..."
echo ""
echo $CMD1
echo ""
$CMD1

# Convert the output file generated in the previous step to video -> output.mp4
CMD2="python extras/txt_to_video.py output.txt output.mp4"
echo "Running python script to generate video from output.txt... "
echo ""
echo $CMD2
echo ""
$CMD2

# Run 100 iterations of Game of Life with a board of 100x100 -> output_random.txt
CMD3="bin/GameOfLife --random 100 --niter 100 --output output_random.txt"
if [ -f output_random.txt ]; then
	rm output_random.txt
fi
echo "Running program with random input..."
echo ""
echo $CMD3
echo ""
$CMD3

# Convert the output from the previous step to a video file -> output_random.mp4 
CMD4="python extras/txt_to_video.py output_random.txt output_random.mp4"
echo "Running python script to generate video from output_random.txt file..."
echo ""
echo $CMD4
echo ""
$CMD4
