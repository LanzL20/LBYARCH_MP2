## Overview of the Project
This project serves as a comparative analysis of the execution times of C-based and x86-64-based programs.
To do so, the same kernel was programmed in both C and x86-64, keeping track of their exact execution times to compare and contrast their overall performance.
The specifications of both kernels, as well as the results of the analysis, may be seen below.

## Task: Perform the DAXPY Function
### Given the inputs...<br>
$n$: Integer Length of the Vectors<br>
$A$: Double-Precision Float<br>
$X$: Vector of Double-Precision Floats<br>
$Y$: Vector of Double-Precision Floats<br>
### ...use the formula...<br>
$Z[i]=A*X[i]+Y[i]$
### ...to calculate the output vector $Z$.<br>

## Performance of Both Kernels
When compiling C code, there are two distinct settings that the compiler may take, namely Debug Mode and Release Mode.
Notably, Release Mode applies some or all optimizations possible, resulting in the program running noticeably faster overall.
Since this choice of mode greatly impacts execution time, two sets of comparisons will be made, C (Debug) vs x86-64 and C (Release) vs x86-64.

Furthermore, in order to compute for an average execution time, thirty (30) runs will be performed for each set of tests.
To cover a range of input sizes, the vector sizes ($n$) that will be tested are $2^{20}$, $2^{24}$, and $2^{28}$. 

### Execution Time (in Seconds): x86-64 vs C (Debug Mode)
| Run   | x86-64  | C       |         | x86-64  | C       |         | x86-64  | C       |
|-------|---------|---------|---------|---------|---------|---------|---------|---------|
| $n$   |$2^{20}$ |$2^{20}$ |         |$2^{24}$ |$2^{24}$ |         |$2^{28}$ |$2^{28}$ |
| 1     | 0.002000| 0.001000|         | 0.019000| 0.028000|         | 0.417000| 0.492000|
| 2     | 0.001000| 0.002000|         | 0.018000| 0.028000|         | 0.334000| 0.596000|
| 3     | 0.001000| 0.002000|         | 0.022000| 0.028000|         | 0.309000| 0.461000|
| 4     | 0.002000| 0.002000|         | 0.019000| 0.029000|         | 0.444000| 0.714000|
| 5     | 0.002000| 0.002000|         | 0.020000| 0.028000|         | 0.372000| 0.523000|
| 6     | 0.001000| 0.002000|         | 0.019000| 0.030000|         | 0.382000| 0.611000|
| 7     | 0.001000| 0.002000|         | 0.018000| 0.028000|         | 0.357000| 0.609000|
| 8     | 0.001000| 0.001000|         | 0.019000| 0.027000|         | 0.362000| 0.579000|
| 9     | 0.001000| 0.002000|         | 0.021000| 0.030000|         | 0.326000| 0.504000|
| 10    | 0.001000| 0.002000|         | 0.019000| 0.029000|         | 0.307000| 0.500000|
| 11    | 0.001000| 0.002000|         | 0.019000| 0.027000|         | 0.340000| 0.541000|
| 12    | 0.001000| 0.002000|         | 0.018000| 0.028000|         | 0.357000| 0.490000|
| 13    | 0.002000| 0.002000|         | 0.018000| 0.028000|         | 0.362000| 0.464000|
| 14    | 0.001000| 0.002000|         | 0.019000| 0.028000|         | 0.333000| 0.482000|
| 15    | 0.001000| 0.002000|         | 0.020000| 0.028000|         | 0.309000| 0.456000|
| 16    | 0.002000| 0.002000|         | 0.019000| 0.028000|         | 0.296000| 0.434000|
| 17    | 0.001000| 0.002000|         | 0.022000| 0.028000|         | 0.297000| 0.454000|
| 18    | 0.001000| 0.002000|         | 0.018000| 0.028000|         | 0.318000| 0.500000|
| 19    | 0.001000| 0.002000|         | 0.019000| 0.028000|         | 0.315000| 0.488000|
| 20    | 0.001000| 0.002000|         | 0.019000| 0.027000|         | 0.309000| 0.634000|
| 21    | 0.002000| 0.001000|         | 0.020000| 0.028000|         | 0.330000| 0.498000|
| 22    | 0.001000| 0.001000|         | 0.019000| 0.028000|         | 0.296000| 0.499000|
| 23    | 0.001000| 0.002000|         | 0.019000| 0.030000|         | 0.282000| 0.485000|
| 24    | 0.002000| 0.002000|         | 0.020000| 0.028000|         | 0.326000| 0.494000|
| 25    | 0.001000| 0.002000|         | 0.017000| 0.031000|         | 0.305000| 0.500000|
| 26    | 0.002000| 0.002000|         | 0.019000| 0.028000|         | 0.360000| 0.497000|
| 27    | 0.001000| 0.002000|         | 0.019000| 0.028000|         | 0.334000| 0.483000|
| 28    | 0.001000| 0.002000|         | 0.018000| 0.029000|         | 0.283000| 0.511000|
| 29    | 0.002000| 0.002000|         | 0.018000| 0.028000|         | 0.349000| 0.488000|
| 30    | 0.001000| 0.002000|         | 0.019000| 0.027000|         | 0.356000| 0.464000|
|<b>Average</b>|<b>0.001300</b>|	<b>0.001867</b>|         | <b>0.019100</b>|	<b>0.028267</b>|         | <b>0.335567</b>|	<b>0.515033</b>|

As expected, when Debug Mode is active, the x86-64-based kernel significantly outperforms the C-based kernel across the board. This difference in execution speed may be attributed to the fact that Assembly generally results in fewer instructions than C after translating them both into machine code. 

This directly leads to a shorter execution time, as the computer needs to execute fewer instructions to compute for the desired result. In this light, the results shown above clearly reflect how C is overall slower than x86-64, at least without performing proper optimization.

### Execution Time (in Seconds): x86-64 vs C (Release Mode)
| Run   | x86-64   |    C       |           |   x86-64 |    C       |           | x86-64   |    C       |
|-------|----------|------------|-----------|----------|------------|-----------|----------|------------|
| $n$   |$2^{20}$  |$2^{20}$    |           |$2^{24}$  |$2^{24}$    |           |$2^{28}$  |$2^{28}$    |
| 1     | 0.001000 | 0.001000   |           | 0.020000 | 0.019000   |           | 0.378000 | 0.359000   |
| 2     | 0.001000 | 0.001000   |           | 0.019000 | 0.017000   |           | 0.337000 | 0.308000   |
| 3     | 0.001000 | 0.000000   |           | 0.019000 | 0.018000   |           | 0.329000 | 0.289000   |
| 4     | 0.001000 | 0.001000   |           | 0.019000 | 0.019000   |           | 0.286000 | 0.274000   |
| 5     | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.309000 | 0.293000   |
| 6     | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.311000 | 0.274000   |
| 7     | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.293000 | 0.267000   |
| 8     | 0.001000 | 0.001000   |           | 0.019000 | 0.018000   |           | 0.291000 | 0.300000   |
| 9     | 0.000000 | 0.001000   |           | 0.019000 | 0.017000   |           | 0.293000 | 0.275000   |
| 10    | 0.000000 | 0.000000   |           | 0.019000 | 0.018000   |           | 0.290000 | 0.312000   |
| 11    | 0.001000 | 0.001000   |           | 0.019000 | 0.018000   |           | 0.356000 | 0.382000   |
| 12    | 0.000000 | 0.001000   |           | 0.020000 | 0.021000   |           | 0.302000 | 0.305000   |
| 13    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.283000 | 0.283000   |
| 14    | 0.001000 | 0.000000   |           | 0.017000 | 0.019000   |           | 0.375000 | 0.303000   |
| 15    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.308000 | 0.319000   |
| 16    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.343000 | 0.327000   |
| 17    | 0.001000 | 0.001000   |           | 0.019000 | 0.018000   |           | 0.279000 | 0.280000   |
| 18    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.297000 | 0.301000   |
| 19    | 0.000000 | 0.001000   |           | 0.021000 | 0.018000   |           | 0.282000 | 0.284000   |
| 20    | 0.001000 | 0.001000   |           | 0.020000 | 0.020000   |           | 0.285000 | 0.282000   |
| 21    | 0.001000 | 0.001000   |           | 0.017000 | 0.018000   |           | 0.328000 | 0.339000   |
| 22    | 0.002000 | 0.001000   |           | 0.020000 | 0.018000   |           | 0.286000 | 0.279000   |
| 23    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.344000 | 0.295000   |
| 24    | 0.001000 | 0.001000   |           | 0.019000 | 0.017000   |           | 0.285000 | 0.355000   |
| 25    | 0.002000 | 0.001000   |           | 0.019000 | 0.018000   |           | 0.358000 | 0.328000   |
| 26    | 0.001000 | 0.001000   |           | 0.018000 | 0.017000   |           | 0.338000 | 0.347000   |
| 27    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.337000 | 0.302000   |
| 28    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.340000 | 0.330000   |
| 29    | 0.001000 | 0.001000   |           | 0.018000 | 0.018000   |           | 0.348000 | 0.341000   |
| 30    | 0.002000 | 0.001000   |           | 0.020000 | 0.019000   |           | 0.351000 | 0.290000   |
|<b>Average</b>|<b>0.000967</b>|<b>0.000900 </b>|           |<b>0.018700 </b>|<b>0.018167 </b>  |           |<b>0.318067</b> |<b>0.307433</b> |

On the other hand, when Release Mode is active, the C-based kernel now outperforms the x86-64-based kernel as a whole, albeit only by a slight margin. This may be due to the fact that the various optimizations performed by Release Mode are significant enough to outweigh the time saved by coding in Assembly. Said optimizations may include function inlining, dead code elimination, loop unrolling, and many more. 

Although they all serve to improve performance at runtime, these optimizations also greatly hinder debugging and significantly reduce code readability. All in all, the results displayed above demonstrate the progress C compilers have made in terms of optimizing code, as well as how x86-64 Assembly still fairs relatively well even when faced with such optimized C code.

## Sample Run of The Program (With Sanity/Correctness Checks)

#### To start off, the program asks for the intended value of $n$ before it produces randomized vectors for $X$ and $Y$ of said size.
![image](https://github.com/LanzL20/LBYARCH_MP2/assets/68149934/8d60f049-9e3d-4616-ae76-d634151a84b8)

#### To ensure the correctness of the programs, the outputs of both the C-based and x86-64-based programs are compared to verify that they are indeed the same. Before the execution of the main program, a simple "sanity check" is performed (i.e., a sample run of $n=15$).
![image](https://github.com/LanzL20/LBYARCH_MP2/assets/68149934/db49b768-9bd8-453c-a866-9091abc5db03)

#### Proceeding to the main portion of the program, a total of thirty (30) runs is executed with the inputted value of $n$. Each run indicates the execution time of both C-based and x64-64-based kernels, as well as whether or not their outputs match or not.
![image](https://github.com/LanzL20/LBYARCH_MP2/assets/68149934/256f0b28-7493-49e4-ab14-f5d8a06b3ae9)

#### The code snippet below illustrates how the program checks between the outputs of the two kernels, throwing an error in the case that they are detected to be different.
![image](https://github.com/LanzL20/LBYARCH_MP2/assets/68149934/727a1763-230a-44a1-aa70-aa0a7605d046)
#### In light of this, so long as all runs indicate that their results have matched, then one may finally be ensured that the results shown are indeed correct and free of error.

## Authors of This Project
### LBYARCH S13 Pair 8
- Lim, Lanz Kendall Yong
- Tan, Tyler Justin Hernandez
