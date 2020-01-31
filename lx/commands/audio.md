# Linux audio commands
&nbsp;  | Commands
---     | ---
&nbsp;  | [`alsamixer`][alsamixer] [`amixer`][amixer] [`speaker-test`][speaker-test]
### `alsamixer`
Command-line mixer
### `amixer`
Command-line mixer for ALSA sound card driver

Display simplified list of controls [^][http://www.volkerschatz.com/noise/alsa.html]
```sh
amixer scontrols
```
Display full list of controls [^][http://www.volkerschatz.com/noise/alsa.html]
```sh
amixer controls
```
Show information about a mixer device [^][http://www.volkerschatz.com/noise/alsa.html]
```sh
amixer info
```
### `speaker-test`
Test loudspeakers with a 2-speaker setup
```sh
speaker-test -c 2
```
## 
[alsamixer]:                                         #alsamixer                                 '```&#10;$ alsamixer&#10;```&#10;Command-line mixer'
[amixer]:                                            #amixer                                    '```&#10;$ amixer&#10;```&#10;Command-line mixer for ALSA sound card driver'
[speaker-test]:                                      #speaker-test                              '```&#10;$ speaker-test&#10;```&#10;Generates a tone that can be used to test the speakers of a computer'

[http://www.volkerschatz.com/noise/alsa.html]: http://www.volkerschatz.com/noise/alsa.html "www.volkerschatz.com: \"A close look at ALSA\""