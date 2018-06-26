FROM ubuntu:18.04
MAINTAINER Thom Troy

RUN apt-get update && apt-get install -y build-essential \
    cmake \
    ninja-build \
    wget \
    git \
    python3 python3-dev python3-pip \
    && pip3 install pytest \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN cd /usr/local/src \
    && wget https://github.com/pybind/pybind11/archive/v2.2.3.tar.gz \
    && tar xvf v2.2.3.tar.gz \
    && cd pybind11-2.2.3 \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install

RUN cd /usr/local/src \
    && wget https://github.com/tianon/gosu/releases/download/1.10/gosu-amd64 \
    && mv gosu-amd64 /usr/local/bin/gosu \
    && chmod +x /usr/local/bin/gosu

ADD setup.sh /setup.sh
RUN chmod +x /setup.sh

CMD ["/bin/bash"]
ENTRYPOINT ["/setup.sh"]
