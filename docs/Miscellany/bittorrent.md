# BitTorrent
Bram Cohen invented BitTorrent protocol in 2001 and wrote the first client in Python. It is a peer-to-peer file sharing protocol where those who share a file are called **seeders** and those who download are called **peers**. All seeders and peers related to a particular torrent comprise the **swarm**. The **tracker server** or **tracker** serves as a repository for information about peers associated with the same file. Files are downloaded in hashed pieces from multiple seeders to distribute the burden of seeding a file. [^](https://app.getpocket.com/read/2717933967 "How Does BitTorrent Work? a Plain English Guide")

A **Torrent Descriptor** file is a hashmap file

Torrent Descriptor property | Description
:---                        | :---
Announce                    | URL of the tracker
Info                        | dictionary whose keys depend on whether one or more files are being shared, including:<br/>Files: list of dictionaries, only exists when multiple files are being shared, each dictionary has two keys and corresponds to a file<br/>Length: size of the file in bytes<br/>Path: list of strings corresponding to subdirectory names, the last of which is the actual filename
length                      | size of the file in bytes (when one file is being shared
name                        | suggested file or directory name
Pieces length               | number of bytes per piece; must be a power of 2 and at least 16KiB
Pieces                      | list of SHA-1 160-bit hashes calculated on various parts of data

```json
{
  "Announce": "url of tracker",
  "Info": {
  "Files": [{ 
    "Length": 16, 
    "path": "/folder/to/path" }, 
    { "length": 193, 
    "path": "/another/folder" }] 
  },
  "length": 192, 
  "name":" Ubuntu.iso", 
  "Pieces length": 262144, 
  "Pieces": [AAF4C61DDCC5E8A2DABEDE0F3B482CD9AEA9434D, CFEA2496442C091FDDD1BA215D62A69EC34E94D0]
}
```

#### BitTorrent clients
- [**Deluge**](https://deluge-torrent.org/) [^](https://fossbytes.com/best-utorrent-alternatives/ "fossbytes.com: \"8 best uTorrent Alternatives for Downloading Torrent files in 2019\") [^](https://itsfoss.com/best-torrent-ubuntu/ "itsfoss.com: \"Best torrent programs for Ubuntu and other Linux distributions\"")
  - command-line functionality
  - open-source with expandable functionalities
  - chosen as the best torrent client by Lifehacker
- **qBittorrent** open-source, ad-free alternative to uTorrent
- **Tixati** closed-source
- **Transmission** installed by default on Ubuntu (ca. 2017)
- **Tribler**
- **Vuze** has ads and is closed-source
- **Frostwire**: multiplatform, including Android
- **WebTorrent Desktop**
