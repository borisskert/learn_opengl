FROM ubuntu:20.04

MAINTAINER borisskert <boris.skert@gmail.com>
ENV DEBIAN_FRONTEND	noninteractive

RUN apt-get update && \
    apt-get install -y git \
                       cmake \
                       make \
                       build-essential
RUN apt-get install -y libx11-dev \
                       libxrandr-dev \
                       libxinerama-dev \
                       libxcursor-dev \
                       libxi-dev \
                       libglu1-mesa-dev
RUN apt-get install -y python3 \
                       python3-dev

COPY . /usr/local/src
WORKDIR /usr/local/src/out

RUN cmake .. && make && ./tests/test_gl_lib
