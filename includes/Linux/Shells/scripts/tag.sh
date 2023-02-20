#!/bin/bash
tag () {
    TAG=$1 ; shift # First arg has to be a valid tag name.
    shopt -s nocasematch
    case $TAG in
        "amapiano")
            while [ $# -gt 0 ]
            do
               INPUTFILE="$1"
               ffmpeg -i "$INPUTFILE" -metadata genre=Amapiano -c copy "${INPUTFILE/./_tagged.}"
               shift
            done
            ;;
        *)
            echo "Invalid tag!"
            ;;
    esac
    shopt -u nocasematch
}