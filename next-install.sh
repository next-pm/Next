check_install_cmake()
{
    CMAKE_VERSION="cmake --version"
    RETVAL=0
    if eval $CMAKE_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install CMake"
    fi
    return $RETVAL
}

check_install_git()
{
    GIT_VERSION="git --version"
    RETVAL=0
    if eval $GIT_VERSION 
    then
        RETVAL=1
        printf "n"
    else
        echo "Not install git"
    fi
    return $RETVAL
}

check_install_make()
{
    MAKE_VERSION="make --version"
    RETVAL=0
    if eval $MAKE_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install make"
    fi
    return $RETVAL
}

check_install_gcc()
{
    gcc_VERSION="gcc --version"
    RETVAL=0
    if eval $gcc_VERSION 
    then
        RETVAL=1
        printf "\n"
    else
        echo "Not install gcc"
    fi
    return $RETVAL
}

clone_next_rep(){
    mkdir -p $HOME/opt
    cd $HOME/opt
    git clone https://github.com/KEGEStudios/Next
}

build_next(){
    cd $HOME/opt/Next
    mkdir -p $HOME/opt/Next/build/cmake
    cd $HOME/opt/Next/build/cmake
    cmake ../..
    make
}

add_next_to_path(){
    cat $HOME/.bashrc ; echo 'source $HOME/opt/Next/env' > $HOME/.bashrc
    cat $HOME/.zshrc ; echo 'source $HOME/opt/Next/env' > $HOME/.bashrc
}

main(){
    check_install_git
    check_install_gcc
    check_install_make
    check_install_cmake
    clone_next_rep
    build_next
    add_next_to_path
}

main