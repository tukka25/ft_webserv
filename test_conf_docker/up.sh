#! /bin/bash

echo -e "\033[0;36mPlease Wait To Builddd\033[0m"
docker build -t "ngin" .
docker run -d -p 443:443 --name "ngin1" "ngin"
docker exec -it "ngin1" /bin/bash
