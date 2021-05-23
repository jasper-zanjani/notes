
```sh
minikube start
```

```sh
minikube dashboard
```

Create a sample deployment
```sh
kubectl create deployment hello-minikube --image=k8s.gcr.io/echoserver:1.4
kubectl expose deployment hello-minikube --type=NodePort --port=8080
```

```sh
minikube stop
```