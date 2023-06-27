FROM ubuntu:23.10


RUN mkdir /root/testing
RUN mkdir /root/targets

WORKDIR /root/demo

RUN apt-get update

RUN apt-get install -y build-essential  curl

# Update new packages
RUN apt-get update


# Get Rust
RUN curl https://sh.rustup.rs -sSf | bash -s -- -y

RUN apt-get install openjdk-19-jdk -y

WORKDIR /root/demo/natif

COPY fuzzer_from_scratch/ /root/demo/fuzzer_from_scratch/
COPY natif/ /root/demo/natif/
COPY recreating_frida_fuzzing/ /root/demo/recreating_frida_fuzzing/
COPY targets /root/demo/targets

ENV JAVA_HOME /usr/lib/jvm/java-19-openjdk-amd64

RUN cd /root/demo/natif

RUN make

WORKDIR /root/demo/fuzzer_from_scratch/ 

