**curl**{: #curl}
:   [`#`][curl -&#35;]   <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`d`][curl -&#100;] <code>&nbsp;</code> [`f`][curl -&#102;] <code>&nbsp;</code> [`h`][curl -&#104;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`m`][curl -&#109;] <code>&nbsp;</code> [`o`][curl -&#111;] <code>&nbsp;</code> [`q`][curl -&#113;] <code>&nbsp;</code> [`s`][curl -&#115;] <code>&nbsp;</code> [`u`][curl -&#117;] [`v`][curl -&#118;] <code>&nbsp;</code> [`x`][curl -&#120;] <code>&nbsp;</code> <code>&nbsp;</code>  <br><code>&nbsp;</code>&nbsp;<code>&nbsp;</code> <code>&nbsp;</code> [`C`][curl -&#67;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`K`][curl -&#75;] [`L`][curl -&#76;] [`M`][curl -&#77;] <code>&nbsp;</code> [`O`][curl -&#79;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> [`S`][curl -&#83;] [`T`][curl -&#84;] [`U`][curl -&#85;] [`V`][curl -&#86;] <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code> <code>&nbsp;</code>\
    [`connect-timeout`][curl --connect-timeout]
    [`create-dirs`][curl --create-dirs]
    [`disable-epsv`][curl --disable-epsv]
    [`ftp-pasv`][curl --ftp-pasv]
    [`limit-rate`][curl --limit-rate]
    [`max-filesize`][curl --max-filesize]
    [`url`][curl --url]

    Use the [ `dict` network protocol ](https://tools.ietf.org/html/rfc2229) to retrieve the definition of a word.
    [ref](https://fedoramagazine.org/set-up-an-offline-command-line-dictionary-in-fedora/)
    ```sh
    curl dict://dict.org/d:<word>
    ```
    Sending a POST method to a FastAPI app ([src](https://app.pluralsight.com/guides/explore-python-libraries:-fastapi))
    ```sh
    curl -X POST "http://127.0.0.1:8000/purchase/item/" -H "accept: application/json" -H "Content-Type: application/json" -d "{\"name\":\"sample item\",\"info\":\"This is info for the item\",\"price\":40,\"qty\":2}"
    ```

[curl -&#35;]: #curl '```&#10;$ curl -#&#10;$ curl --progress-bar&#10;```&#10;Print progress information as a progress bar instead of as statistics&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#67;]: #curl '```&#10;$ curl -C $OFFSET&#10;$ curl --continue-at $OFFSET&#10;```&#10;continue a previous file transfer at `$OFFSET` bytes&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl -&#102;]: #curl '```&#10;$ curl -f&#10;$ curl --fail&#10;```&#10;Fail silently upon HTTP server errors. Mainly useful for scripts.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl -&#104;]: #curl '```&#10;$ curl -h&#10;$ curl --help&#10;```&#10;Print a brief help message.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl -&#75;]: #curl '```&#10;$ curl -K $CONFIGFILE&#10;$ curl --config $CONFIGFILE&#10;```&#10;Use `$CONFIGFILE` as the configuration file, instead of the default "$HOME/.curlrc". Use `-` to read configuration information from STDIN.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl -&#109;]: #curl '```&#10;$ curl -m $SECONDS&#10;$ curl --max-time $SECONDS&#10;```&#10;Do not exceed `$SECONDS` for the entire operation.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#77;]: #curl '```&#10;$ curl -M&#10;$ curl --manual&#10;```&#10;Display full help text (> 2400 lines) in the form of a manpage.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#111;]: #curl '```&#10;$ curl -o $FILE&#10;$ curl --output $FILE&#10;```&#10;Write output to `$FILE` instead of to STDOUT&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#113;]: #curl '```&#10;$ curl -q&#10;```&#10;When used as the first parameter, do not read "$HOME/.curlrc"&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#115;]: #curl '```&#10;$ curl -s&#10;$ curl --silent&#10;```&#10;Do not print a progress meter or any error messages.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#83;]: #curl '```&#10;$ curl -S&#10;$ curl --show-error&#10;```&#10;With `-s`, do display error messages.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#84;]: #curl '```&#10;$ curl -T $FILE&#10;$ curl --upload-file $FILE&#10;```&#10;Upload `$FILE` to the URL on the command line.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#117;]: #curl '```&#10;$ curl -u $USER:$PASSWORD&#10;$ curl --user $USER:$PASSWORD&#10;```&#10;Supply `$USER` and `$PASSWORD` to the server for authentication.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#85;]: #curl '```&#10;$ curl -U $USER:$PASSWORD&#10;$ curl --proxy-user $USER:$PASSWORD&#10;```&#10;Supply `$USER` and `$PASSWORD` to the server for proxy authentication.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#118;]: #curl '```&#10;$ curl -v&#10;$ curl --verbose&#10;```&#10;Be verbose during file retrieval.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#86;]: #curl '```&#10;$ curl -V&#10;$ curl --version&#10;```&#10;Print version and supported-feature information&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#120;]: #curl '```&#10;$ curl -x $PROXYHOST:$PORT&#10;$ curl --proxy $PROXYHOST:$PORT&#10;```&#10;Use `$PROXYHOST` (and the optional `$PORT` which is 1080 by default), as the HTTP proxy&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl --connect-timeout]: #curl '```&#10;$ curl --connect-timeout $SECONDS&#10;```&#10;Limit connection phase to `$SECONDS` seconds&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --create-dirs]: #curl '```&#10;$ curl --create-dirs&#10;```&#10;When used with `-o`, create local directories as needed&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --disable-epsv]: #curl '```&#10;$ curl --disable-epsv&#10;```&#10;Do not use the `EPSV` FTP command for passive FTP transfer. Normally `curl` tries `EPSV` before `PASV`.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --ftp-pasv]: #curl '```&#10;$ curl --ftp-pasv&#10;```&#10;Use the FTP `PASV` command (default)&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --limit-rate]: #curl '```&#10;$ curl --limit-rate $SPEED&#10;```&#10;Limit transfers to `$SPEED` (bytes per second by default). Other possible units, placed at the end of the argument, include:&#10;  - `k`,`K`               kilboytes&#10;  - `m`,`M`               megabytes&#10;  - `g`,`G`               gigabytes&#10;&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --max-filesize]: #curl '```&#10;$ curl --max-filesize $BYTES&#10;```&#10;Do not download a file exceeding `$BYTES` in size.&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 49'
[curl --url]: #curl '```&#10;$ curl --url $URL&#10;```&#10;Retrieve `$URL`&#10;Robbins, Arnold. _UNIX in a Nutshell_ 4th ed (2005): 50'
[curl -&#79;]: #curl '```&#10;$ curl -O $URL&#10;$ curl --remote-name $URL&#10;```&#10;download `$URL` saving output under the filename indicated by `$URL` itself'
[curl -&#100;]: #curl '```&#10;$ curl -d $NAME=$VALUE&#10;```&#10;Post form-encoded `$NAME` with value `$VALUE`'
[curl -&#76;]: #curl '```&#10;$ curl -L&#10;$ curl --location&#10;```&#10;Follow redirects'