# Conway's Game of Life 

Game of Life coursework for the module Research Computing with C++.

# Pre-requisites

This program requires:

	- g++ 4.9 with C++11 and OpenMP support. That is, there must exist a binary of g++ with OpenMP
	  support in '/usr/bin/g++' (when compiling under Linux) and '/usr/local/bin/g++' (when 
	  compiling under MAC OS X).

	- ffmpeg is required. It is used in the script that converts the output text file to video.
	  
	- For MAC OS X users (tested only in Mavericks): the folder 'extras/gcc-4.9-bin/' contains the 
	  binaries for gcc and g++ version 4.9 with OpenMP support for Mac OS X Mavericks and Yosemite 
	  downloaded from:
	  
	  http://hpc.sourceforge.net/

	  In order to install them in your system run the following commands:

	  $ cd extras/gcc-4.9-bin
	  $ mkdir workdir
	  $ cp gcc-4.9-bin.tar.gz workdir/
	  $ cd workdir
	  $ tar -xzf gcc-4.9-bin.tar.gz
	  $ sudo rsync -vah usr/* /usr/
	
	- For Linux users (tested only in Ubuntu 14.04):

	  $ sudo add-apt-repository ppa:ubuntu-toolchain-r/test
	  $ sudo add-apt-repository ppa:jon-severinsson/ffmpeg
	  $ sudo apt-get update
	  $ sudo apt-get install g++-4.9
	  $ sudo apt-get install ffmpeg
	  $ sudo apt-get install frei0r-plugins

# Build Instructions

Execute the following commands in the main directory of the project:

```
$ ./build.sh
```

The compile process has been tested in: 

	- Mac OS X 10.9.5
	- Ubuntu 14.04

# Unit Testing

Execute the following commands in the main directory of the project in order to check the
correctness of the code.

```
$ ./test.sh 
```

# Run the Program 

After the project has been built, execute this command to run the program and generate the output videos:

```
$ ./run.sh
```

These four steps are executed with the previous script:

1. Run Game of Life with the file 'test/input.txt' as input and generates the output in 'output.txt'.  
2. Convert 'output.txt' to 'output.mp4' so that you can see a video of the execution of the game.  
3. Run Game of Life with a random input board and 100 iterations and generate 'output_random.txt'  
4. Convert 'output_random.txt' to video so that you can see the execution of the randomly initialised game.  

These are other examples on how to run the program:

```
$ bin/GameOfLife --input test/input.txt --output output.txt --niter 100
$ bin/GameOfLife --random 100 --output output.txt --niter 100
$ python extras/txt_to_video.py output.txt output.mp4
```

# Results

See a random execution of Conway's Game of Life generated by this program in the following link:  

https://www.youtube.com/watch?v=949ciYmRyhE

See report in https://github.com/luiscarlosgph/game-of-life/blob/master/doc/report.pdf

# Coursework Instructions

1. Research Conway’s Game of Life (the Boolean version of the floating-point game
presented in the lectures) and understand the algorithm. Explain the algorithm in your own
words in your report. 
[5 marks]

2. Create an appropriate scaffold for your project, by adapting that of the previous coursework
assignment, with CMakeLists.txt files, and an appropriate layout for source code and tests,
and a main executable. 
[5 marks]

3. Create an appropriate serial implementation in C++, with an output file describing the state
of the simulation over time. Define an input file specifying the domain size and initial state.
[20 marks]

4. While doing (2) above, create appropriate unit tests as you go, using the Catch framework. 
[15 marks]

5. While doing (2) above, create sensible commit messages in GitHub, and continually
commit to version control.
[10 marks]

6. Use a high-level language of your choice to turn your output file into a video. (E.g. Python
or MATLAB). Upload a created video to the internet (e.g. via You Tube) and put the link in
your report.
[5 marks]

7. Parallelise your code using EITHER OpenMP or MPI. 
[20 marks]

8. Modify your output file and video-creator to work with your parallel code. 
[15 marks]

9. Execute your code in parallel on a computer with at least 4 compute cores, and plot an
appropriate graph showing achieved speedup. Comment on your results. 
[5 marks]

