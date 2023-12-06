FROM debian:latest

RUN apt-get update && apt-get install -y sudo && apt-get install -y nginx && apt install -y vim && apt install -y systemctl

COPY index.html /etc/

COPY def /etc/nginx/sites-available/default

CMD ["nginx", "-g", "daemon off;"]