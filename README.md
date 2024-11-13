# Matrix-Vector Multiplication Analysis with HLS

This repository provides an implementation and analysis of matrix-vector multiplication optimized for hardware using Xilinx High Level Synthesis (HLS). Matrix-vector multiplication is a core operation in various fields, including scientific computing, machine learning, and digital signal processing, making its efficient implementation crucial for high-performance applications on FPGA platforms.

## Table of Contents

- [Overview](#overview)
- [Directory Structure](#directory-structure)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [Reports](#reports)

## Overview

This project focuses on designing and optimizing matrix-vector multiplication in hardware using **Xilinx HLS**, allowing for highly efficient execution on FPGA devices. The repository includes:
- HLS code for matrix-vector multiplication with configurable parameters
- Testbenches to verify correctness and analyze performance
- Reports on optimization techniques, performance metrics, and resource utilization

## Directory Structure

- `src/`: Contains the HLS source code for matrix-vector multiplication, with configurable parameters for matrix and vector sizes.
- `testbench/`: Testbenches to validate functionality and measure performance in different scenarios.
- `report/`: Detailed documentation on the implementation, including optimization techniques and performance analysis.

## Dependencies

To use this repository, you’ll need:
- [Xilinx Vivado HLS](https://www.xilinx.com/products/design-tools/vivado.html) for synthesizing and simulating HLS code
- [Python 3.x](https://www.python.org/) (optional, for any additional scripts or utilities)

## Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/gubbriaco/matrix-vector-multiplication-analysis.git
    ```
2. Navigate to the repository:
    ```bash
    cd matrix-vector-multiplication-analysis
    ```

## Usage

To synthesize and test the matrix-vector multiplication design:
1. Open Xilinx Vivado HLS and import the project files from the `src/` directory.
2. Configure matrix and vector sizes in the source code or project settings as needed.
3. Run synthesis and simulation using the testbenches in the `testbench/` directory to verify the functionality and analyze performance.

The `src/` directory contains configuration files and parameters that can be adjusted for different use cases. For detailed guidance on these settings, consult the comments in each file.

## Reports

The `report/` directory includes comprehensive documentation on the project, covering topics such as:
- Optimization techniques for matrix-vector multiplication in hardware
- Performance and resource utilization analysis
- Trade-offs in latency, throughput, and area efficienc
