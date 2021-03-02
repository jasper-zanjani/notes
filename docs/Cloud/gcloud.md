# gcloud

- [Google Command Line for beginners](https://youtu.be/j274vq9a2Rs)

[doc:gcloud-app]: https://cloud.google.com/sdk/gcloud/reference/app "gcloud app documentation"
[doc:gcloud-compute]: https://cloud.google.com/sdk/gcloud/reference/compute "gcloud compute documentation"
[doc:gcloud-container]: https://cloud.google.com/sdk/gcloud/reference/container "gcloud container documentation"
[doc:gcloud-functions]: https://cloud.google.com/sdk/gcloud/reference/functions "gcloud functions documentation"
[doc:gcloud-run]: https://cloud.google.com/sdk/gcloud/reference/run "gcloud run documentation"
[doc:gcloud-services]: https://cloud.google.com/sdk/gcloud/reference/services "gcloud services documentation"

[gcloud-app]: #app-engine '```&#10;gcloud app &#10;```&#10;App Engine'
[gcloud-compute]: #gcloud-compute '```&#10;gcloud compute &#10;```&#10;Compute Engine'
[gcloud-container]: #gcloud-container '```&#10;gcloud container &#10;```&#10;Kubernetes Engine'
[gcloud-functions]: #gcloud-functions '```&#10;gcloud functions &#10;```&#10;Cloud Functions'
[gcloud-run]: #google-cloud-run '```&#10;gcloud run &#10;```&#10;Manage Cloud Run applications'
[gcloud-services]: #gcloud-services '```&#10;gcloud services &#10;```&#10;manage project's access to APIs'

[`app`][gcloud-app]<sup>[?][doc:gcloud-app]</sup>
[`compute`][gcloud-compute]<sup>[?][doc:gcloud-compute]</sup>
[`container`][gcloud-container]<sup>[?][doc:gcloud-container]</sup>
[`functions`][gcloud-functions]<sup>[?][doc:gcloud-functions]</sup>
[`run`][gcloud-run]<sup>[?][doc:gcloud-run]</sup>
[`services`][gcloud-services]<sup>[?][doc:gcloud-services]</sup>
`source`

Google Cloud Source Control repositories
```sh
gcloud source repos clone
gcloud source repos create
```

## PaaS

Deploy app in current working directory.
```sh
gcloud app deploy
```
View the deployed app
```sh
gcloud app browse
```
app.yaml allows configuration of the app in several ways
```yaml
runtime: python37
```