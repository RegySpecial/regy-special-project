#@description Dockerfile to create a docker debian image and compiling for various architectures
#@author Regy Special
#@date 2026 June 11th Thursday, 00:06:17
#@license GNU General Public License to stop private corporation to not share source code

from parrot:latest

# Install basic dependencies
run 
  for compiler in gcc g++; \
    do apt-get update && apt-get install -y \
      $compiler-aarch64-linux-gnu \
      $compiler-arm-linux-gnueabi \
      $compiler-riscv64-linux-gnu \
      $compiler-riscv64-unknown-elf; \
  done \
  && rm -rf /var/lib/apt/lists/*


volume /root
workdir /root

cmd ["/bin/bash"]
cmd ["echo", "-e", "\e[31mBenvenuto all'inferno!\n"]