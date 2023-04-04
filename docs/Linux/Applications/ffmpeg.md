# ffmpeg

#### Convert format
:   
    ffmpeg is most often used to convert file formats for media from the command-line
    ```sh title="Convert mp3 to m4a"
    ffmpeg -i media.{mp3,m4a}
    ```

#### Display metadata
:   

    ```sh
    ffmpeg -hide_banner -i $INPUT
    ```

#### Specify metadata
:   

    [Metadata](https://wiki.multimedia.cx/index.php/FFmpeg_Metadata) is defined as key/value pairs, although not all formats support all metadata.
    This example adds metadata but does not reencode the input file.
    ```sh
    ffmpeg -i $INPUTFILE -metadata title=$TITLE -metadata year=$YEAR -codec copy $OUTPUTFILE
    ```

    ```sh title="Tag all audio in a directory"
    for INPUT in $(ls *.mp3);
    do
        ffmpeg -i "$INPUT" -c copy -metadata genre=Amapiano "${INPUT/.mp3/_tagged.mp3}"
    done
    ```

#### Concatenating multiple files
:   
    It is possible to combine many files into one.
    The canonical way of doing this is by first assembling a list of filenames.
    These must appear in a specific [format](https://trac.ffmpeg.org/wiki/Concatenate):
    ```sh
    file 'file1.mp3'
    file 'file2.mp3'
    # etc...
    ```

    This can be done quickly by piping the output of **ls** to a file, then editing it manually.
    ```sh
    echo $(ls -1 *.mp3) > files
    ```

    Then this file can be used by ffmpeg, specifying the **concat** demuxer as the argument to **-f**
    ```sh
    ffmpeg -f concat -i files -c copy compilation.mp3
    ```

    Chapters will be accepted with the right container (apparently not mp3).
    Note that mp3 files cannot be placed into a m4a container without re-encoding.
    Also note that the **-map_metadata** option must be specified **after** the second infile, because its argument refers to the second infile as if it were zero-indexed.
    ```sh
    ffmpeg -f concat -i files -i chapters -map_metadata 1 -c copy compilation.m4a
    ```
