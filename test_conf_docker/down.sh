#! /bin/bash

docker stop $(docker ps -aq)
docker rmi -f $(docker image ls -aq)
echo -e "\033[0;32mEverything is Clean\033[0m"