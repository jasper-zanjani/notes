# Helm

Helm is a package manager for Kubernetes. 

Helm packages are refered to as **charts**.
Charts are a collection of files and directories that adhere to a specification.
A chart is **packed** when tarred and gzipped.

- **Chart.yaml** contains metadata
- **templates/** contains Kubernetes manifests potentially annotated with templating directives
- **values.yaml** provides default configuration


It is managed using the **helm** CLI utility.


## Tasks

Create a new chart
```sh
helm create foo
```

There is no longer a default Helm repository, although there are many available at the [Artifact Hub](https://artifacthub.io)



## Syncthing TrueChart app [:material-github:](https://github.com/truecharts/apps/tree/master/charts/stable/syncthing)
