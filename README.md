# Conway's Game of Life 

Game of Life coursework for the module Research Computing with C++.

# Instructions

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
