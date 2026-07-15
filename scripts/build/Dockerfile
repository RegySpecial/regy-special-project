#@description Dockerfile to create a docker debian image and compiling for various architectures
#@author Regy Special
#@date 2026 June 11th Thursday, 00:06:17
#@license GNU General Public License to stop private corporation to not share source code

from debian:bookworm-slim

# Install basic dependencies
run apt-get update && apt-get install -y \
    curl \
    wget \
    git \
    vim \
    build-essential \
    python3 \
    python3-pip \
    nodejs \
    && rm -rf /var/lib/apt/lists/*


volume /root
workdir /root
cmd ["echo -e \"\e[31mBenvenuto all'inferno!\n\""]
cmd ["/bin/bash"]