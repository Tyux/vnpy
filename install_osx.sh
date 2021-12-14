#!/usr/bin/env bash

python=$1
shift 1

[[ -z $python ]] && python=python

$python -m pip install --upgrade pip setuptools wheel

# Get and build ta-lib
function install-ta-lib()
{
    export HOMEBREW_NO_AUTO_UPDATE=true
    brew install ta-lib
}
function ta-lib-exists()
{
    ta-lib-config --libs > /dev/null
}
ta-lib-exists || install-ta-lib

# install ta-lib
$python -m pip install numpy==1.18.2
$python -m pip install ta-lib==0.4.17

# Install Python Modules
$python -m pip install -r requirements.txt

# Install local Chinese language environment
locale-gen zh_CN.GB18030

# Install vn.py
$python -m pip install . $@