#! /bin/bash

echo -e "\033[0;36mPlease Wait To Builddd\033[0m"
docker build -t $1 .
docker run -d -p 443:443 --name $2 $1
export deleteme=$1
docker exec -it $2 /bin/bash