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