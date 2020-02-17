[alsamixer]:                                         #alsamixer                                 '```&#10;$ alsamixer&#10;```&#10;Command-line mixer'
[amixer]:                                            #amixer                                    '```&#10;$ amixer&#10;```&#10;Command-line mixer for ALSA sound card driver'
[speaker-test]:                                      #speaker-test                              '```&#10;$ speaker-test&#10;```&#10;Generates a tone that can be used to test the speakers of a computer'

[http://www.volkerschatz.com/noise/alsa.html]: http://www.volkerschatz.com/noise/alsa.html "www.volkerschatz.com: \"A close look at ALSA\""

# Linux audio commands

### ALSA
**Advanced Linux Sound Architecture (ALSA)** replaced the earlier "Open Sound System". [^][Schatz]

ALSA kernel modules are designed to offer an interface that "corresponds to that of the hardware" to keep the modules simple, and similar cards will offer a similar interface. They offer two interfaces: **operational** and **configuration**

**Operational interface** through the `/dev/` tree, with 3 main types of devices
- **PCM** for recording or playing digitized sound samples
- **CTL** for manipulating the internal mixer and routing of the card
- **MIDI** to control the MIDI port, if it exists
- Optionally, **sequencer** devices may also exist if the card has a builtin sound synthesizer with an associated **timer** device

**Status and configuration interface** via the `/proc/asound/` tree (ref [`amixer`][amixer])

PCM devices come in two varieties: **output** and **input** and are numbered from 0, which is generally for analog multichannel sound.

Cards have input or output **sockets**, and the **mixer** is controlled by the CTL device and routes sound samples among devices and sockets.

Controls come in 3 types;
- **Playback** controls are associated with an output device or **copy (input-to-output)** routes
- **Capture** controls are associated with an input device or **copy (output-to-input)** routes
- **Feature** controls drive features of the card or mixer, usually just a switch to enable or disable the feature, though some also have levels. The **Master Volume** control is the most typical example, which allows control of the internal amplifier feature of the card. A more interesting example is that of a 3d spatializer that can be represented by a switch to enable or disable it as well as two levels.

Typical channel assignments
- **0**: front left
- **1**: front right
- **2**: rear left
- **3**: rear right

### PulseAudio
PulseAudio is a sound server for POSIX OSes and a fixture on many Linux distributions.

PulseAudio is built around **sources** and **sinks** (i.e. devices) connected to **source outputs** and **sink inputs** (streams)
- **Source** is an input device that produces samples, usually running a thread with its own event loop, generating sample chunks which are posted to all connected source outputs
- **Source output** is a recording stream which consumes samples from a source
- **Sink** is an output device that consumes samples, usually running a thread with its own event loop mixing sample chunks from connect sink inputs
- **Sink input** is a playback stream, connected to a sink and producing samples for it

[^]: https://gavv.github.io/articles/pulseaudio-under-the-hood/ "gavy.github.io: \"PulseAudio under the hood\""
[amixer]: commands/sound.md#amixer "Command-line mixer for ALSA sound card driver"
[Schatz]: http://www.volkerschatz.com/noise/alsa.html "www.volkerschatz.com: \"A close look at ALSA\""

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