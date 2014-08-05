#omnitty

##1. Fork from http://omnitty.sourceforge.net/

##2. Compile

###2.1 Install libncurses

    sudo apt-get install libncurses

###2.2 Download librote

http://rote.sf.net/

    $ tar -zxf /path/to/rote-X.Y.Z.tar.gz
    $ cd rote-X.Y.Z
    $ ./configure
    $ make
    $ su -c "make install"
    $ cd ..

###2.3 Compile and Install

    qmake *.pro
    make

##3. Usage

###3.1 Deprecated Usage

This version block the usage of adding machine dynamicly on the fly since it doesn't make any sense.

###3.2 Resource file

Create a resource file like r.txt in this way:

    [name]=[login command]

For example:

    192.168.1.101=ssh user@192.168.1.101 -i .ssh/key.pem
    192.168.1.102=sshpass -p password ssh user@192.168.1.102 -p 22

Only in this way we can support different login commands case by case



