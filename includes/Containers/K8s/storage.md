
### Storage

**Volumes** are an abstraction of file systems accessible from within a Pod's containers.

- Network storage device, such as [**`gcePersistentVolume`** <sup>:material-kubernetes:</sup>](https://kubernetes.io/docs/concepts/storage/volumes/#emptydir)
- [**`emptyDir`**](#emptydir), where the data is stored in RAM using Docker's [tmpfs](#tmpfs) file system
- **`hostPath`**, where the volume is located within the node's file system. Because pods are expected to be created and destroyed on any node (which may themselves be destroyed and recreated), hostPath volumes are discommended.

Volumes are declared in **.spec.volumes** and mounted into containers in **.spec.containers[\*].volumeMounts**.

=== "emptyDir"

    ```yaml
    apiVersion: v1
    kind: Pod
    metadata:
      name: alpine
    spec:
      volumes:
        - name: data
          emptyDir:


      containers:
      - name: alpine
        image: alpine
        volumeMounts:
          - mountPath: "/data"
            name: "data"
    ```

=== "hostPath"

    ```yaml
    apiVersion: v1
    kind: Pod
    metadata:
      name: alpine
    spec:
      volumes:
        - name: data
          hostPath:
            path: /var/data
            
      containers:
      - name: alpine
        image: alpine
        volumeMounts:
          - mountPath: "/data"
            name: "data"
    ```

=== "gcePersistentDisk"

    ```yaml
    apiVersion: v1
    kind: Pod
    metadata:
      name: alpine
    spec:
      volumes:
        - name: data
          gcePersistentDisk:
            pdName: my-disk
            fsType: ext4
      containers:
      - name: alpine
        image: alpine
        volumeMounts:
          - mountPath: "/data"
            name: "data"
    ```