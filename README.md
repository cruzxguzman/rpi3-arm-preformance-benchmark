# Raspberry Pi 3 ARM Performance Benchmark
Experimental analysis of single-core vs multi-core workload scaling on ARM Cortex-A53 using C and pthreads.

.

Overview
This project evaluates computational performance on an ARM Cortex-A53 (Raspberry Pi 3 Model B v1.2) by comparing:

Single-threaded execution

Multi-threaded execution using pthreads

Memory stress behavior under load

The objective was to observe real-world scaling behavior on embedded ARM hardware and analyze the efficiency of parallel execution.

All benchmarks were written in C and executed in a Linux terminal environment.

.

System Configuration
Hardware
Component	Specification
Device	Raspberry Pi 3 Model B v1.2
CPU	Quad-core ARM Cortex-A53
Frequency	1.2 GHz
RAM	1GB LPDDR2
Architecture	ARMv8
Software
Raspberry Pi OS Lite

GCC compiler

pthreads library

Linux time command

htop for CPU monitoring

.

Benchmark Design
Three benchmarks were implemented to evaluate different aspects of system performance:

1. Single-Core Matrix Multiplication
Uses one execution thread

Establishes baseline computational throughput

2. Multi-Core Matrix Multiplication
Distributes workload across multiple threads

Evaluates parallel scaling efficiency

3. Memory Stress Test
Allocates and accesses large memory blocks

Observes RAM limitations and memory behavior

Implementation Details
Compile Commands
Single-Core:

gcc matrix_single.c -o matrix_single
Multi-Core:

gcc matrix_multi.c -o matrix_multi -lpthread
Memory Test:

gcc memory_test.c -o memory_test
Execution
./matrix_single
./matrix_multi
./memory_test
Execution time was measured using:

time ./program_name
CPU utilization was monitored using:

htop
Results

Observed Behavior
Multi-threaded execution significantly reduced runtime.

All four CPU cores reached near 100% utilization during parallel execution.

Speedup was substantial but not perfectly linear due to thread overhead and memory constraints.

Memory testing highlighted limitations of 1GB RAM under sustained load.

Performance Analysis
The results demonstrate typical parallel scaling characteristics:

Parallel workloads benefit from distributing computation across cores.

Thread creation and synchronization introduce measurable overhead.

Memory bandwidth and cache behavior influence scaling efficiency.

Embedded ARM systems can effectively handle parallel workloads within hardware limits.

This experiment reinforces fundamental concepts in multicore architecture and performance optimization.

.

Key Takeaways
Parallel execution improves computational throughput.

Scaling efficiency is limited by overhead and hardware constraints.

ARM-based embedded systems provide a practical platform for systems-level experimentation.

Benchmarking and documentation are essential for understanding performance behavior.

.

Skills Demonstrated
C systems programming

Multithreading with pthreads

ARM architecture fundamentals

Linux performance monitoring

Benchmark design and analysis

Git-based project documentation
