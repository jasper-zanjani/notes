# TGIK 121: Starboard
- Spin up a `kind` cluster with worker nodes
- Use [**Starboard**](https://github.com/aquasecurity/starboard "Kubernetes-native security tool kit") to explore it
- Leverage **Octant** plugin
```yaml
# kind.yaml
kind: Cluster
apiVersion: kind.sigs.k8s.io/v1alpha3
nodes;
- role: control-plane
- role: worker
- role: worker
```
[22:30](https://youtu.be/P_QZtZJAZyU?t=1345)
```sh
kind create cluster --config kind.yaml
```
Starboard can be installed from a binary <sup>[23:29](https://youtu.be/P_QZtZJAZyU?t=1409)</sup> or with the `Krew` plugins manager
```sh
k krew install starboard
```
Create a `.envrc` to create environment variables when within it, then initialize `starboard` <sup>[27:00](https://youtu.be/P_QZtZJAZyU?t=1620)</sup>
```sh
# .envrc
export PATH=$PATH:$(pwd)/bin
```
```sh
direnv allow
starboard init
k get crd
k get ns
k get pods -A -n starboard
k get sa -n starboard
k get all -n starboard
k api-resources --api-group aquasecurity.github.io
```
Deploy Nginx [30:00](https://youtu.be/P_QZtZJAZyU?t=1800)
```sh
k create ns dev
k create deployment nginx --image nginx:1.16 --namespace dev
k get pods -n dev
```
[**`ksn`**](https://github.com/blendle/kns) is a small shellscript based on `fzf` to quickly switch between Kubernetes namespaces.
```sh
kns
```
```sh
starboard find vulnerabilities deployment/nginx --namespace dev --output yaml
```