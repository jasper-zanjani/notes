# ffmpeg

#### Specify metadata
:   
    [Metadata](https://wiki.multimedia.cx/index.php/FFmpeg_Metadata) is defined as key/value pairs, although not all formats support all metadata.
    This example adds metadata but does not reencode the input file.
    ```sh
    ffmpeg -i $INPUTFILE -metadata title=$TITLE -metadata year=$YEAR -codec copy $OUTPUTFILE
    ```