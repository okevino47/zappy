#!/usr/bin/env bash

##
##  Test with too few argument
##
./zappy_server 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with too few argument: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with too few argument: \033[31m\tKO\033[0m"
fi

##
##  Test with too much argument
##
./zappy_server -p 2000 -x 3 -y 3 -n test -c 8 -f 10 a 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with too much argument: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with too much argument: \033[31m\tKO\033[0m"
fi


##
##  Test with port < 1024
##
#./zappy_server -p 1000 -x 3 -y 3 -n test -c 8 -f 10 2> /dev/null
#if [ $? == 84 ]
#then
#    echo -e "test with port < to 1024: \033[32m\tOK\033[0m"
#else
#    echo -e "\033[1mtest with port < to 1024: \033[31m\tKO\033[0m"
#fi

##
##  Test with x negative value
##
./zappy_server -p 4242 -x -1 -y 3 -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with negative x value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with negative x value: \033[31m\tKO\033[0m"
fi

##
##  Test with negative y value
##
./zappy_server -p 4242 -x 1 -y -3 -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with negative y value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with negative y value: \033[31m\tKO\033[0m"
fi

##
##  Test with NULL x value
##
./zappy_server -p 4242 -x 0 -y 3 -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with NULL x value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with NULL x value: \033[31m\tKO\033[0m"
fi

##
##  Test with NULL y value
##
./zappy_server -p 4242 -x 1 -y 0 -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with NULL y value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with NULL y value: \033[31m\tKO\033[0m"
fi

##
##  Test with inconsistent x value
##
./zappy_server -p 4242 -x i -y 4 -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with inconsistent x value: \033[32mOK\033[0m"
else
    echo -e "\033[1mtest with inconsistent x value: \033[31mKO\033[0m"
fi

##
##  Test with inconsistent y value
##
./zappy_server -p 4242 -x 1 -y z -n test -c 8 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with inconsistent y value: \033[32mOK\033[0m"
else
    echo -e "\033[1mtest with inconsistent y value: \033[31mKO\033[0m"
fi

##
##  Test with NULL n value
##
#./zappy_server -p 4242 -x 3 -y 3 -n \"\" -c 8 -f 10 2> /dev/null
#if [ $? == 84 ]
#then
#    echo -e "test with NULL n value: \033[32mOK\033[0m"
#else
#    echo -e "\033[1mtest with NULL n value: \033[31mKO\033[0m"
#fi

##
##  Test with NULL c value
##
./zappy_server -p 4242 -x 1 -y z -n test -c 0 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with NULL c value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with NULL c value: \033[31m\tKO\033[0m"
fi

##
##  Test with negative c value
##
./zappy_server -p 4242 -x 1 -y z -n test -c -30 -f 10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with negative c value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with negative c value: \033[31m\tKO\033[0m"
fi

##
##  Test with inconsistent f value
##
./zappy_server -p 4242 -x 1 -y z -n test -c 10 -f y 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with NULL f value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with NULL f value: \033[31m\tKO\033[0m"
fi

##
##  Test with NULL f value
##
./zappy_server -p 4242 -x 1 -y z -n test -c 10 -f 0 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with NULL f value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with NULL f value: \033[31m\tKO\033[0m"
fi

##
##  Test with negative f value
##
./zappy_server -p 4242 -x 1 -y z -n test -c 10 -f -10 2> /dev/null
if [ $? == 84 ]
then
    echo -e "test with negative f value: \033[32m\tOK\033[0m"
else
    echo -e "\033[1mtest with negative f value: \033[31m\tKO\033[0m"
fi
