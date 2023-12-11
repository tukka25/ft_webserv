#! /bin/bash

sudo echo -e "\033[0;36mPlease Wait To Builddd\033[0m"
sudo docker build -t "ngin" .
sudo docker run -d -p 443:443 --name "ngin4" "ngin"
sudo docker exec -it "ngin4" /bin/bash