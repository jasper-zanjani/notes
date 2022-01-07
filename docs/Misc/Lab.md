# Home lab

### Media server

- [tubearchivist](https://github.com/bbilly1/tubearchivist), which describes itself as a self-hosted YouTube media server, can be used to store, index, and play YouTube videos. It uses yt-dlp to download from YouTube. It can be deployed using a [docker-compose file](https://github.com/bbilly1/tubearchivist/blob/master/docker-compose.yml).
- [tubesync](https://github.com/meeb/tubesync) is not a complete media server, but a web application frontend that also allows channels and playlists to be added and downloaded to a file server. It supports Plex as a media server, but it has to be added separately. It is not meant to be used to download individual videos, but rather to scan specified channels or playlists for new content and to download them in the background.