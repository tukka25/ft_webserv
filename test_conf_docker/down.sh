#! /bin/bash

docker stop $deleteme
docker rmi -f $deleteme
unset $deleteme
echo -e "\033[0;32mEverything is Clean\033[0m"