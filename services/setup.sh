#!/bin/sh

minikube start --vm-driver=virtualbox --cpus=4 --memory=4G --disk-size=50G

minikube addons enable metallb
minikube addons enable dashboard

eval $(minikube docker-env)

docker build -t nginx_image srcs/nginx/
docker build -t mysql_image srcs/mysql/
docker build -t phpmyadmin_image srcs/phpmyadmin/
docker build -t wordpress_image srcs/wordpress/
docker build -t ftps_image srcs/ftps/
docker build -t influxdb_image srcs/influxdb/
docker build -t grafana_image srcs/grafana/

kubectl apply -f srcs/configmap.yaml

kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/influxdb/influxdb.yaml
kubectl apply -f srcs/grafana/grafana.yaml

sleep 10

minikube dashboard
