#ARG TAG
#ARG VARIANT="jammy"
#FROM buildpack-deps:${VARIANT}-curl
#FROM cs50/codespace:latest
#FROM cs50/codespace:00ae65f484da2691d86ddb8e6bb3b844cbb4686d as builder
# Criado e alterado por Edkallenn Lima em 15/03/2024. Se for alterar use sempre o idioma inglês para os comentários, exceto este.

# Debian 11 baseado na imagem: mcr.microsoft.com/devcontainers/cpp:debian-11 (or bullseye)
# Link para outros containers de desenvolvimento: https://hub.docker.com/_/microsoft-devcontainers-cpp
# se precisar atualizar basta verificar no link acima qual o mais atual (latest) e trocar no ARG abaixo
ARG base_tag=bullseye 
ARG base_img=mcr.microsoft.com/vscode/devcontainers/base:dev-${base_tag}

FROM --platform=linux/amd64 ${base_img} AS builder-install


# Unset user
USER root

RUN apt-get update --fix-missing && apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    apt-utils \
    curl \
    clang \
    cmake \
    build-essential \
    gcc \
    g++-multilib \
    locales \
    make \
    ruby \
    gcovr \
    wget \
    && rm -rf /var/lib/apt/lists/*

# [Optional] Uncomment this section to install additional OS packages.
# The first part is the core of distro
#WORKDIR /root
#EXPOSE 1234    
RUN apt-get update &&  apt update --fix-missing && apt upgrade -f -y && apt-get install  -y \    
    git \
    vim \
    nano \
    gcc \
    g++ \
    automake \     
    doxygen \     
    iputils-ping \
    cowsay \
    graphviz \
    libboost-dev \
    libboost-regex-dev \
    acl \
#        dwarfdump \
    jq \
    openbox \
#        mysql-client \
#        php-cli \
#        php-mbstring \
#        php-sqlite3 \
    xvfb \
    pip \
    unzip \
#        x11vnc && \   
 && apt-get clean \ 
 && rm -rf /var/lib/apt/lists/* 

RUN apt-get update; apt-get upgrade -y
#RUN apt-get upgrade -y
RUN apt-get install -y linux-headers-generic
#RUN apt-get install -y glibc-dev
RUN apt-get install -y vim exuberant-ctags
RUN apt-get install -y bash-completion
RUN apt-get install -y gdb
RUN apt-get install -y libc-dbg
RUN apt-get install -y nodejs

# colorize output of make
RUN apt-get install -y colormake
RUN echo "alias make='colormake '\n" >> /etc/bash.bashrc

# manpages
RUN apt-get install -y man-db manpages-dev
RUN apt-get install -y less

# colorize manpages for all users that use bash
RUN echo "export LESS_TERMCAP_mb=$'\E[01;31m'       # begin blinking \n \
    export LESS_TERMCAP_md=$'\E[01;38;5;74m'  # begin bold \n \
    export LESS_TERMCAP_me=$'\E[0m'           # end mode \n \
    export LESS_TERMCAP_se=$'\E[0m'           # end standout-mode \n \
    export LESS_TERMCAP_so=$'\E[38;5;246m'    # begin standout-mode - info box \n \
    export LESS_TERMCAP_ue=$'\E[0m'           # end underline \n \ 
    export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline \n" >> /etc/bash.bashrc


RUN apt-get install -y locate
RUN apt-get install -y tree
RUN updatedb

# Install Lua 5.x
# https://www.lua.org/manual/5.4/readme.html
RUN cd /tmp && \
    curl --remote-name https://www.lua.org/ftp/lua-5.4.6.tar.gz && \
    tar xzf lua-5.4.6.tar.gz && \
    rm --force lua-5.4.6.tar.gz && \
    cd lua-5.4.6 && \
    make all install && \
    cd .. && \
    rm --force --recursive /tmp/lua-5.4.6

# Final stage
#FROM cs50/cli:latest


# Unset user
USER root
ARG DEBIAN_FRONTEND=noninteractive

# Copy files from builder
#COPY --from=builder-install /build /build
#COPY --from=builder-install /opt /opt
#COPY --from=builder-install /usr/local /usr/local

# Set virtual display
ENV DISPLAY=":0"

# Install Python packages
RUN pip3 install --no-cache-dir \
        black \
        clang-format \
        djhtml \
        matplotlib \
        "pydantic<2" \
        pytz \
        setuptools

# Copy files to image
#COPY ./etc /etc
#COPY ./opt /opt
#RUN chmod a+rx /opt/cs50/bin/* && \
#    chmod a+rx /opt/cs50/phpliteadmin/bin/phpliteadmin && \
#    ln --symbolic /opt/cs50/phpliteadmin/bin/phpliteadmin /opt/cs50/bin/phpliteadmin


# Enforce login shell
#RUN echo "\nshopt -q login_shell || exec bash --login -i" >> /etc/bash.bashrc


# installs cs50lib
RUN touch instala-config-cs50.sh && \
    curl -s https://raw.githubusercontent.com/ed1rac/FerramentasProgramacao/master/script.deb.sh > instala-config-cs50.sh && \ 
    chmod +x instala-config-cs50.sh && \
    ./instala-config-cs50.sh && \
    apt install libcs50


#RUN echo "eval \"$(/usr/local/bin/oh-my-posh init bash --config ~/themes/amro.omp.json)\"" >> ~/.bashrc


#export some enviroment variables
RUN echo "export CC=\"clang\"" >> ~/.bashrc
RUN echo "export CFLAGS=\"-ferror-limit=1 -gdwarf-4 -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow\"" >> ~/.bashrc
RUN echo "export LDLIBS=\"-lcrypt -lcs50 -lm\"" >> ~/.bashrc

RUN echo "export LIBRARY_PATH=/usr/local/lib" >> ~/.bashrc
RUN echo "export C_INCLUDE_PATH=/usr/local/include" >> ~/.bashrc
RUN echo "export LD_LIBRARY_PATH=/usr/local/lib" >> ~/.bashrc
RUN echo "export GLOBAL_MAKEFILE_PATH=~" >> ~/.bashrc
RUN export "PATH=$PATH:/home/vscode"


# instala algumas configuracoes.
RUN touch instala-config-ed.sh && \
    curl https://raw.githubusercontent.com/ed1rac/FerramentasProgramacao/master/instala-config-codespace.sh > instala-config-ed.sh && \
    chmod +x instala-config-ed.sh && \
    ./instala-config-ed.sh && \
    touch config_bash_oh_my_posh.sh && \
    curl https://raw.githubusercontent.com/ed1rac/FerramentasProgramacao/master/configura_bash_oh_my_posh.sh > config_bash_oh_my_posh.sh && \
    chmod +x config_bash_oh_my_posh.sh 
#    ./configura_bash_oh_my_posh.shell

#RUN git clone https://github.com/ed1rac/FerramentasProgramacao.git
#RUN cp FerramentasProgramacao/ /home/vscode/ -r -v -f
#RUN cd FerramentasProgramacao
#RUN dos2unix instala-config-codespace.sh 
#RUN bash /workspaces/unipe-estruturas-dados/FerramentasProgramacao/instala-config-codespace.sh
#/home/codespace/.cache/oh-my-posh/themes
#RUN curl -s https://ohmyposh.dev/install.sh | bash -s -- -d /home/vscode
#Installing oh-my-posh for linux-amd64 in /home/vscode
#Downloading oh-my-posh from https://github.com/JanDeDobbeleer/oh-my-posh/releases/latest/download/posh-linux-amd64
#Installing oh-my-posh themes in /root/themes
#oh-my-posh init bash --config /root/themes/amro.omp.json
##eval "$(oh-my-posh init bash --config /root/themes/amro.omp.json)"

RUN cp /root/.bashrc /home/vscode


# Copy files to image
#COPY ./etc /etc
#COPY ./opt /opt
#RUN chmod a+rx /opt/cs50/bin/*

# Set user
# Adiciona o usuário 'unipe'
RUN useradd -m unipe
# Define a senha do usuário 'unipe' como 'unipe'
RUN echo "unipe:unipe" | chpasswd

RUN mv /instala-config-ed.sh /home/vscode && \
    cd /home/vscode && \
    bash /home/vscode/instala-config-ed.sh && \
    cp /home/vscode/.bashrc /home/unipe -r -f -v
RUN cp /root/FerramentasProgramacao/bash-profile/bash-ubuntu-on-windows/.bashrc /home/vscode -r -f -v

USER vscode